#pragma once
#include <vk_mem_alloc.h>
#include <VulkanWrapper/VulkanWrapper.h>

#include <memory>

namespace Aetherborne {

	class Engine;

    class Image {

    public:
        Image(Engine& engine, const vk::ImageCreateInfo& info, const VmaAllocationCreateInfo& allocInfo);
        ~Image();

        vk::Image& image() const { return *m_image; }
        vk::Extent3D extent() const { return m_image->extent(); }

    private:
        Engine* m_engine;
        std::unique_ptr<vk::Image> m_image;
        VmaAllocation m_allocation;
        VmaAllocationInfo m_allocationInfo;

    };
}