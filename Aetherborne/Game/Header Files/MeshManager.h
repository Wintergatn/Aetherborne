#pragma once
#include <VulkanWrapper/VulkanWrapper.h>
#include <../../Engine/Header Files/Engine.h>
#include <../../Engine/RenderGraph/TransferNode.h>

struct MeshAllocation {
    std::shared_ptr<Aetherborne::Buffer> buffer;
    Aetherborne::Allocation allocation;

    MeshAllocation();
    MeshAllocation(const std::shared_ptr<Aetherborne::Buffer>& buffer, Aetherborne::Allocation allocation);
    MeshAllocation(const MeshAllocation& other) = delete;
    MeshAllocation& operator = (const MeshAllocation& other) = delete;
    MeshAllocation(MeshAllocation&& other);
    MeshAllocation& operator = (MeshAllocation&& other);
    ~MeshAllocation();
};

class MeshManager {
    struct Page {
        Aetherborne::FreeListAllocator allocator;
        std::shared_ptr<Aetherborne::Buffer> buffer;

        Page(Aetherborne::Engine& engine);
    };

public:
    MeshManager(Aetherborne::Engine& engine);

    std::shared_ptr<Aetherborne::Buffer>& indexBuffer() { return m_indexBuffer; }

    void setTransferNode(Aetherborne::TransferNode& transferNode);

    MeshAllocation allocateBuffer(size_t size, size_t alignment);

private:
    Aetherborne::Engine* m_engine;
    Aetherborne::TransferNode* m_transferNode;

    std::vector<std::unique_ptr<Page>> m_pages;

    std::shared_ptr<Aetherborne::Buffer> m_indexBuffer;
    uint32_t m_indexCount;
    size_t m_indexBufferSize;

    void createIndexBuffer(std::vector<uint32_t>& indexData);
};