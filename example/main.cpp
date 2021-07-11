//
// Created by natha on 10/07/2021.
//

#include "App_base.hpp"

// std
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main() {
    AppBase app{};

    try {
        app.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
