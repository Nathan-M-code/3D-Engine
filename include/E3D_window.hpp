//
// Created by natha on 10/07/2021.
//

#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// std
#include <string>

namespace E3D {

    class E3DWindow {
    public:
        E3DWindow(int w, int h, std::string name);
        ~E3DWindow();

        //we don't want to have two E3D_window pointing to the same GLFWwindow *
        E3DWindow(const E3DWindow &) = delete;
        E3DWindow &operator=(const E3DWindow &) = delete;

        bool shouldClose() { return glfwWindowShouldClose(window); }

    private:
        void initWindow();

        const int width;
        const int height;
        std::string windowName;
        GLFWwindow *window;
    };
}  // namespace E3D
