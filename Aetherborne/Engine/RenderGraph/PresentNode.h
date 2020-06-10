#pragma once
#include "../Header Files/Engine.h"
#include "AcquireNode.h"

namespace Aetherborne {

	class PresentNode : public RenderGraph::Node {

    public:
        PresentNode(Aetherborne::Engine& engine, RenderGraph& graph, vk::PipelineStageFlags stage, AcquireNode& acquireNode);

        void preRender(uint32_t currentFrame) {}
        void render(uint32_t currentFrame, vk::CommandBuffer& commandBuffer) {}
        void postRender(uint32_t currentFrame);

    private:
        const vk::Queue* m_presentQueue;
        AcquireNode* m_acquireNode;
        std::unique_ptr<vk::Semaphore> m_semaphore;

    };
}