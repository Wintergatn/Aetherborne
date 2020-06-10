#pragma once
#include <VulkanWrapper/VulkanWrapper.h>
#include <vk_mem_alloc.h>

namespace Aetherborne {

	class MemoryManager {

    public:
        MemoryManager(vk::Device& device);
        ~MemoryManager();

        VmaAllocator allocator() const { return m_allocator; }

    private:
        VmaAllocator m_allocator;

        void createAllocator(vk::Device& device);

	};
}