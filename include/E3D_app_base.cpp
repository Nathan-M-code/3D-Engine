//
// Created by natha on 10/07/2021.
//

#include "../source/E3D_app_base.hpp"

namespace E3D {

    void E3DAppBase::run() {
        while (!E3DWindow.shouldClose()) {
            glfwPollEvents();
        }
    }
}  // namespace E3D
