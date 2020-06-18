#pragma once
#include <VulkanWrapper/VulkanWrapper.h>
#include "Engine.h"
#include "../RenderGraph/RenderGraph.h"
#include <vk_mem_alloc.h>

namespace Aetherborne {

    class Engine;

    struct BufferState {
        Engine* engine;
        vk::Buffer buffer;
        VmaAllocation allocation;

        BufferState(Engine* engine, vk::Buffer&& buffer, VmaAllocation allocation);
        BufferState(const BufferState& other) = delete;
        BufferState& operator = (const BufferState& other) = delete;
        BufferState(BufferState&& other);
        BufferState& operator = (BufferState&& other);
        ~BufferState();
    };

    class Buffer {

    public:
        Buffer(Engine& engine, const vk::BufferCreateInfo& info, const VmaAllocationCreateInfo& allocInfo);
        ~Buffer();

        vk::Buffer& buffer() const { return m_bufferState->buffer; }
        void* getMapping() const;
        size_t size() const { return m_bufferState->buffer.size(); }

    private:
        Engine* m_engine;
        std::unique_ptr<BufferState> m_bufferState;
        VmaAllocationInfo m_allocationInfo;
    };
}