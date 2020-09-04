#include "keyboard_controller.hpp"

#include "application.hpp"
#include <opencv2/highgui.hpp>

KeyboardController::KeyboardController(KeyboardView* view, Application* module) :
    _view(view),
    _module(module),
    _frameGrabber() {
    _view->setListener(this);
}

#include <iostream>
void KeyboardController::activate() {
    std::cout << "Tello: send command" << std::endl;
    auto com_resp = _module->baseSettings()->tellos().at(0)->command();
    com_resp.wait();

    std::cout << "set frame grabber" << std::endl;
    _frameGrabber.tello(_module->baseSettings()->tellos().at(0));
    _frameGrabber.activate();
    std::cout << "activated" << std::endl;

    bool imageFound = false;
    int tries = 0;
    while(!imageFound && tries < 10000) {
        auto image = _frameGrabber.grabNext();
        if (image) {
            Mat matIm = image->get();
            std::cout << "Mat: " << matIm.rows << std::endl;
            if (matIm.rows > 0 && matIm.cols > 0) {
                cv::imshow("Image", matIm);
                cv::waitKey(0);
                imageFound = true;
            }
        }
        tries++;
    }
}

void KeyboardController::deactivate() {
    _frameGrabber.deactivate();
}

Fl_Group* KeyboardController::view() {
    return _view;
}