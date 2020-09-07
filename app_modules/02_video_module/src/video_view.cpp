#include "video_view.hpp"

static void onTakePicturePressed(Fl_Widget* widget, void* listener);

VideoView::VideoView() :
        Fl_Group(20, 55, 1280, 720, "Video"),
        _takePictureBtn(25, 65, 100, 30, "Take Picture"),
        _listener(nullptr) {
    end();
}

void VideoView::setListener(IListener *listener) {
    _listener = listener;
    _takePictureBtn.callback(onTakePicturePressed, _listener);
}

void onTakePicturePressed(Fl_Widget* widget, void* listener) {
    static_cast<IListener*>(listener)->takePicture();
}