//
// Created by natha on 10/07/2021.
//

#pragma once

#include "E3D_device.hpp"
#include "E3D_game_object.hpp"
#include "E3D_renderer.hpp"

#include "simple_render_system.hpp"

// std
#include <memory>
#include <vector>
#include <iostream>


class AppBase {
public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    AppBase();
    ~AppBase();

    AppBase(const AppBase &) = delete;
    AppBase &operator=(const AppBase &) = delete;

    void run();

private:
    void loadGameObjects();

    E3D::Window m_window{WIDTH, HEIGHT, "Hello Vulkan!"};
    E3D::Device m_device{m_window};
    E3D::Renderer m_renderer{m_window, m_device};

    std::vector<E3D::GameObject> gameObjects;
};
