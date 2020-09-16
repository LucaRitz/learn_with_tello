#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <common/macro_definition.hpp>
#include <atomic>

class Texture;
class Shader;
class VertexBuffer;
class VertexArray;

using std::atomic_bool;

class EXPORT OpencvWidget : public Fl_Gl_Window {
public:
    OpencvWidget(int x, int y, int w, int h);

    void frame(cv::Mat frame);
    void draw();

private:
    atomic_bool _draw;
    int gl_version_major;
    Texture* texture1;
    Shader* shader;
    VertexBuffer* vbo;
    VertexArray* vao;
    cv::Mat _frame;

    void setUp();
};
