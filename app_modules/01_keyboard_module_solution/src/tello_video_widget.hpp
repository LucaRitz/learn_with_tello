#include <stdarg.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>
#include <glad/glad.h>
#include "image.h"
#include "shader.h"
#include "texture.h"
#include "vertexbuffer.h"
#include "vertexarray.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

void add_output(const char *format, ...);


class TelloVideoWidget : public Fl_Widget {

    int gl_version_major;
    Texture texture1;
    Shader shader;
    VertexBuffer* vbo;
    VertexArray* vao;
    cv::VideoCapture capture;

public:
    TelloVideoWidget(int x, int y, int w, int h) :  Fl_Widget(x, y, w, h),
            texture1(),
            shader("./resources/shader.vs", "./resources/shader.fs") {

        mode(FL_RGB8 | FL_DOUBLE | FL_OPENGL3);

//        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//            std::cerr << "Failed to initialize GLAD" << std::endl;
//            exit(-1);
//        }

        gl_version_major = 0;

        Image containerImage = Image::of("resources/container.jpg");
        texture1 = Texture::of()
                .activeTexture(0)
                .bind()
                .wrap(GL_CLAMP_TO_BORDER, GL_CLAMP_TO_BORDER)
                .filter(GL_LINEAR, GL_LINEAR)
                .image(containerImage)
                .generateMipmap();
        containerImage.free();

        shader.use();
        shader.setInt("texture1", 0);

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
    }

    void draw(void) {
        gl_start();
        if (gl_version_major < 3) return;

        cv::Mat frame;
        capture.read(frame);
        if (frame.empty()) {
            std::cout << "ERROR: No captured frame" << std::endl;
        } else {
            cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
            cv::flip(frame, frame, -1);
            texture1.image(Image {frame.cols, frame.rows, 3, frame.data});
        }

        shader.use();

        glClearColor(0.2, 0.3, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        texture1
                .activeTexture(0)
                .bind();

        vao->bind();

        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
        gl_end();
    }

    virtual int handle(int event) {

//        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
//            glfwSetWindowShouldClose(window, true);
//        }
//        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
//            camera.processKeyboard(CameraMovement::FORWARD, deltaTime);
//        }
//        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
//            camera.processKeyboard(CameraMovement::BACKWARD, deltaTime);
//        }
//        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
//            camera.processKeyboard(CameraMovement::LEFT, deltaTime);
//        }
//        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
//            camera.processKeyboard(CameraMovement::RIGHT, deltaTime);
//        }

//        static int first = 1;
//        if (first && event == FL_SHOW && shown()) {
//            first = 0;
//            make_current();
//#ifndef __APPLE__
//            GLenum err = glewInit(); // defines pters to functions of OpenGL V 1.2 and above
//            if (err) Fl::warning("glewInit() failed returning %u", err);
//            else add_output("Using GLEW %s\n", glewGetString(GLEW_VERSION));
//#endif
//            const uchar *glv = glGetString(GL_VERSION);
//            add_output("GL_VERSION=%s\n", glv);
//            sscanf((const char *)glv, "%d", &gl_version_major);
//            if (gl_version_major < 3) add_output("\nThis platform does not support OpenGL V3\n\n");
//            redraw();
//        }
//
//        if (event == FL_PUSH && gl_version_major >= 3) {
//            static float factor = 1.1;
//            GLfloat data[4];
//            glGetBufferSubData(GL_ARRAY_BUFFER, 0, 4*sizeof(GLfloat), data);
//            if (data[0] < -0.88 || data[0] > -0.5) factor = 1/factor;
//            data[0] *= factor;
//            glBufferSubData(GL_ARRAY_BUFFER, 0, 4*sizeof(GLfloat), data);
//            glGetBufferSubData(GL_ARRAY_BUFFER, 24*sizeof(GLfloat), 4*sizeof(GLfloat), data);
//            data[0] *= factor;
//            glBufferSubData(GL_ARRAY_BUFFER, 24*sizeof(GLfloat), 4*sizeof(GLfloat), data);
//            redraw();
//            add_output("push  Fl_Gl_Window::pixels_per_unit()=%.1f\n", pixels_per_unit());
//            return 1;
//        }
        return Fl_Gl_Window::handle(event);
    }
    void reset(void) { shaderProgram = 0; }
};


//void toggle_double(Fl_Widget *wid, void *data) {
//    static bool doublebuff = true;
//    doublebuff = !doublebuff;
//    SimpleGL3Window *glwin = (SimpleGL3Window*)data;
//    int flags = glwin->mode();
//    if (doublebuff) flags |= FL_DOUBLE; else flags &= ~FL_DOUBLE;
//    glwin->mode(flags);
//    glwin->reset();
//}
//
//
//Fl_Text_Display *output; // shared between output_win() and add_output()
//
//void output_win(SimpleGL3Window *gl)
//{
//    output = new Fl_Text_Display(300,0,500, 280);
//    Fl_Light_Button *lb = new Fl_Light_Button(300, 280, 500, 20, "Double-Buffered");
//    lb->callback(toggle_double);
//    lb->user_data(gl);
//    lb->value(1);
//    output->buffer(new Fl_Text_Buffer());
//}
//
//
//void add_output(const char *format, ...)
//{
//    va_list args;
//    char line_buffer[10000];
//    va_start(args, format);
//    vsnprintf(line_buffer, sizeof(line_buffer)-1, format, args);
//    va_end(args);
//    output->buffer()->append(line_buffer);
//    output->scroll(10000, 0);
//    output->redraw();
//}
//

//int main(int argc, char **argv)
//{
//    Fl::use_high_res_GL(1);
//    Fl_Window *topwin = new Fl_Window(800, 300);
//    SimpleGL3Window *win = new SimpleGL3Window(0, 0, 300, 300);
//    win->end();
//    output_win(win);
//    topwin->end();
//    topwin->resizable(win);
//    topwin->label("Click GL panel to reshape");
//    topwin->show(argc, argv);
//    Fl::run();
//}
