//
// Created by natha on 10/07/2021.
//

#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// std
#include <iostream>
#include <string>
#include <stdexcept>

namespace E3D {

    class Window {
    public:
        Window(int w, int h, std::string name);
        ~Window();

        //we don't want to have two E3D_window pointing to the same GLFWwindow *
        Window(const Window &) = delete;
        Window &operator=(const Window &) = delete;

        bool shouldClose() { return glfwWindowShouldClose(m_glfwWindow); }
        VkExtent2D getExtent() { return {static_cast<uint32_t>(m_width), static_cast<uint32_t>(m_height)};}
        bool wasWindowResized(){return m_framebufferResized;}
        void resetWindowResizedFlag(){m_framebufferResized = false;}

        int getWidth() { return m_width; }
        int getHeight() { return m_height; }

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

    private:
        static void framebufferResizeCallback(GLFWwindow *glfwWindow, int width, int height);
        void initWindow();

        int m_width;
        int m_height;
        bool m_framebufferResized = false;

        std::string m_windowName;
        GLFWwindow *m_glfwWindow;
    };
}  // namespace E3D
