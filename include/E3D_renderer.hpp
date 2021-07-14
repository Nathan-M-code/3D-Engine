//
// Created by natha on 12/07/2021.
//

#pragma once

#include "E3D_device.hpp"
#include "E3D_swap_chain.hpp"
#include "E3D_window.hpp"

// std
#include <cassert>
#include <memory>
#include <vector>

namespace E3D {
    class Renderer {
    public:
        Renderer(Window &window, Device &device);
        ~Renderer();

        Renderer(const Renderer &) = delete;
        Renderer &operator=(const Renderer &) = delete;

        VkRenderPass getSwapChainRenderPass() const { return m_swapChain->getRenderPass(); }
        bool isFrameInProgress() const { return m_isFrameStarted; }

        VkCommandBuffer getCurrentCommandBuffer() const {
            assert(m_isFrameStarted && "Cannot get command buffer when frame not in progress");
            return m_commandBuffers[m_currentFrameIndex];
        }

        int getFrameIndex() const {
            assert(m_isFrameStarted && "Cannot get frame index when frame not in progress");
            return m_currentFrameIndex;
        }

        VkCommandBuffer beginFrame();
        void endFrame();
        void beginSwapChainRenderPass(VkCommandBuffer commandBuffer);
        void endSwapChainRenderPass(VkCommandBuffer commandBuffer);

    private:
        void createCommandBuffers();
        void freeCommandBuffers();
        void recreateSwapChain();

        Window &m_window;
        Device &m_device;
        std::unique_ptr<SwapChain> m_swapChain;
        std::vector<VkCommandBuffer> m_commandBuffers;

        uint32_t m_currentImageIndex;
        int m_currentFrameIndex{0};
        bool m_isFrameStarted{false};
    };
}  // namespace E3D
