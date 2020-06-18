#pragma once
#include "../Header Files/Engine.h"
#include "VulkanWrapper/VulkanWrapper.h"

#include <iostream>

namespace Aetherborne {

    class AcquireNode : public RenderGraph::Node {

    public:
        AcquireNode(Aetherborne::Engine& engine, RenderGraph& graph);

        RenderGraph::ImageUsage& imageUsage() const { return *m_imageUsage; }

        vk::Swapchain& swapchain() const { return *m_swapchain; }
        uint32_t swapchainIndex() const { return m_swapchainIndex; }

        void preRender(uint32_t currentFrame);
        void render(uint32_t currentFrame, vk::CommandBuffer& commandBuffer) {}
        void postRender(uint32_t currentFrame) {}

    private:
        vk::Swapchain* m_swapchain;
        std::unique_ptr<vk::Semaphore> m_semaphore;
        std::unique_ptr<RenderGraph::ImageUsage> m_imageUsage;
        uint32_t m_swapchainIndex;

        void onSwapchainChanged(vk::Swapchain& swapchain);
    };
}