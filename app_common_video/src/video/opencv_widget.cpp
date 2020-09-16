#include <video/opencv_widget.hpp>
#include <glad/glad.h>

#include "image.h"
#include "shader.h"
#include "texture.h"
#include "vertexbuffer.h"
#include "vertexarray.h"

OpencvWidget::OpencvWidget(int x, int y, int w, int h)  : Fl_Gl_Window(x, y, w, h, nullptr),
    _draw(true) {
    mode(FL_RGB | FL_DOUBLE | FL_OPENGL3);
}

void OpencvWidget::frame(cv::Mat frame)  {
    _draw = false;
    _frame = std::move(frame);
    _draw = true;

    redraw();
    Fl::awake();
}

void OpencvWidget::draw() {
    if (_draw) {
        static bool first = true;
        if (first) {
            first = false;
            setUp();
        }

        if (!valid()) {
            glViewport(0, 0, pixel_w(), pixel_h());
        }

        if (gl_version_major < 3) return;

        cv::Mat frame = _frame;
        if (frame.empty()) {
            std::cout << "ERROR: No captured frame" << std::endl;
        } else {
            cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
            cv::flip(frame, frame, -1);
            texture1->image(Image{frame.cols, frame.rows, 3, frame.data});
        }

        shader->use();

        glClearColor(0.2, 0.3, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        texture1
                ->activeTexture(0)
                .bind();

        vao->bind();

        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
    }
}

void OpencvWidget::setUp() {
    if (!gladLoadGL()) {
        std::cerr << "Failed to initialize OpenGL context" << std::endl;
    }

    gl_version_major = 3;
    shader = new Shader("./scripts/video_common/shader.vs", "./scripts/video_common/shader.fs");

    Image containerImage = Image::of("./resources/video_common/tello.jpg");
    texture1 = &Texture::ofHeap()
            ->activeTexture(0)
            .bind()
            .wrap(GL_CLAMP_TO_BORDER, GL_CLAMP_TO_BORDER)
            .filter(GL_LINEAR, GL_LINEAR)
            .image(containerImage)
            .generateMipmap();
    containerImage.free();

    shader->use();
    shader->setInt("texture1", 0);

    glEnable(GL_DEPTH_TEST);

    float vertices[] = {
            // positions          // texture coords		// normals
            -1.0f, -1.0f,  0.0f,  0.0f, 0.0f,			0.0f,  0.0f,  1.0f,
            -1.0f,  1.0f,  0.0f,  0.0f, 1.0f,			0.0f,  0.0f,  1.0f,
            1.0f, -1.0f,  0.0f,  1.0f, 0.0f,			0.0f,  0.0f,  1.0f,
            1.0f, -1.0f,  0.0f,  1.0f, 0.0f,			0.0f,  0.0f,  1.0f,
            -1.0f,  1.0f,  0.0f,  0.0f, 1.0f,			0.0f,  0.0f,  1.0f,
            1.0f,  1.0f,  0.0f,  1.0f, 1.0f,			0.0f,  0.0f,  1.0f
    };

    vbo = VertexBuffer::of(sizeof(vertices), vertices);
    vao = VertexArray::create();
    vao->bind();
    vao->layout({
                        Attribute::of(3, AttributeType::FLOAT, Normalization::OFF),
                        Attribute::of(2, AttributeType::FLOAT, Normalization::OFF),
                        Attribute::of(3, AttributeType::FLOAT, Normalization::OFF),
                });
}