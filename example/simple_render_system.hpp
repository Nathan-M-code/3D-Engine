//
// Created by natha on 12/07/2021.
//

#pragma once

#include "E3D_device.hpp"
#include "E3D_game_object.hpp"
#include "E3D_pipeline.hpp"

// std
#include <memory>
#include <vector>

namespace E3D {
    class SimpleRenderSystem {
    public:
        SimpleRenderSystem(Device &device, VkRenderPass renderPass);
        ~SimpleRenderSystem();

        SimpleRenderSystem(const SimpleRenderSystem &) = delete;
        SimpleRenderSystem &operator=(const SimpleRenderSystem &) = delete;

        void renderGameObjects(VkCommandBuffer commandBuffer, std::vector<GameObject> &gameObjects);

    private:
        void createPipelineLayout();
        void createPipeline(VkRenderPass renderPass);

        Device &m_device;

        std::unique_ptr<Pipeline> m_pipeline;
        VkPipelineLayout m_pipelineLayout;
    };
}  // namespace E3D
