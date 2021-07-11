//
// Created by natha on 10/07/2021.
//

#pragma once

#include "E3D_device.hpp"
#include "E3D_pipeline.hpp"
#include "E3D_window.hpp"
#include "E3D_swap_chain.hpp"

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
    void loadModels();
    void createPipelineLayout();
    void createPipeline();
    void createCommandBuffers();
    void freeCommandBuffers();
    void drawFrame();
    void recreateSwapChain();
    void recordCommandBuffer(int imageIndex);

    E3D::Window m_window{WIDTH, HEIGHT, "Hello Vulkan!"};
    E3D::Device m_device{m_window};
    std::unique_ptr<E3D::SwapChain> m_swapChain;
    std::unique_ptr<E3D::Pipeline> m_pipeLine;
    VkPipelineLayout m_vkPipelineLayout;
    std::vector<VkCommandBuffer> m_commandBuffers;
    std::unique_ptr<E3D::Model> m_model;
};
