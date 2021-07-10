//
// Created by natha on 10/07/2021.
//

#pragma once

#include "E3D_window.hpp"

namespace E3D {

    class E3DAppBase {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

    private:
        E3DWindow E3DWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
    };
}  // namespace E3D
