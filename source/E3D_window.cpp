//
// Created by natha on 10/07/2021.
//

#include "E3D_window.hpp"

using namespace std;

namespace E3D {

    Window::Window(int w, int h, std::string name) : m_width{w}, m_height{h}, m_windowName{name} {
        initWindow();
    }

    Window::~Window() {
        glfwDestroyWindow(m_glfwWindow);
        glfwTerminate();
    }

    void Window::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        m_glfwWindow = glfwCreateWindow(m_width, m_height, m_windowName.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(m_glfwWindow,this);
        glfwSetFramebufferSizeCallback(m_glfwWindow, framebufferResizeCallback);
    }

    void Window::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if (glfwCreateWindowSurface(instance, m_glfwWindow, nullptr, surface) != VK_SUCCESS) {
            throw std::runtime_error("failed to create m_window surface!");
        }
    }

    void Window::framebufferResizeCallback(GLFWwindow *glfwWindow, int width, int height){
        auto window = reinterpret_cast<Window *>(glfwGetWindowUserPointer(glfwWindow));
        window->m_framebufferResized = true;
        window->m_width = width;
        window->m_height = height;
    }
}  // namespace E3D