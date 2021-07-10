//
// Created by natha on 10/07/2021.
//

#include "E3D_window.hpp"

namespace E3D {

    E3DWindow::E3DWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
        initWindow();
    }

    E3DWindow::~E3DWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void E3DWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }
}  // namespace E3D