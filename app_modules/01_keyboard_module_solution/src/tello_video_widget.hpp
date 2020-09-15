#include <cstdarg>
#include <FL/Fl.H>
#include <glad/glad.H>
#include <FL/Fl_Gl_Window.H>
#include "image.h"
/*#include "shader.h"
#include "texture.h"
#include "vertexbuffer.h"
#include "vertexarray.h"*/
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

void add_output(const char *format, ...);


class TelloVideoWidget : public Fl_Gl_Window {

    int gl_version_major;
  /*  Texture* texture1;
    Shader* shader;
    VertexBuffer* vbo;
    VertexArray* vao;*/
    cv::VideoCapture capture;

public:
    TelloVideoWidget(int x, int y, int w, int h) : Fl_Gl_Window(x, y, w, h, nullptr) {
        mode(FL_RGB | FL_DOUBLE | FL_OPENGL3);
    }

    /*void init() {
        //mode(FL_RGB8 | FL_DOUBLE | FL_OPENGL3);

//        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//            std::cerr << "Failed to initialize GLAD" << std::endl;
//            exit(-1);
//        }

        gl_version_major = 0;

        Image containerImage = Image::of("resources/container.jpg");
        texture1 = &Texture::ofHeap()
                ->activeTexture(0)
                .bind()
                .wrap(GL_CLAMP_TO_BORDER, GL_CLAMP_TO_BORDER)
                .filter(GL_LINEAR, GL_LINEAR)
                .image(containerImage)
                .generateMipmap();
        containerImage.free();

        shader = new Shader("./resources/shader.vs", "./resources/shader.fs");
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

        capture.open(0);
        if (!capture.isOpened()) {
            std::cout << "ERROR: Failed to open video capture" << std::endl;
        }
    }*/

    void draw() override {
        static bool first = true;
        if (first) {
            if (!gladLoadGL()) {
                std::cerr << "Failed to initialize OpenGL context" << std::endl;
            }
            glViewport(0, 0, 10, 10);
            first = false;
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        glFlush();
/*
        if (!started) {
            std::cout << "Init" << std::endl;
            init();
            started = true;
        }
        if (gl_version_major < 3) return;

        cv::Mat frame;
        capture.read(frame);
        if (frame.empty()) {
            std::cout << "ERROR: No captured frame" << std::endl;
        } else {
            cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
            cv::flip(frame, frame, -1);
            texture1->image(Image {frame.cols, frame.rows, 3, frame.data});
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
        gl_finish();*/
    }
};
