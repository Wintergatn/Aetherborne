#pragma once
#include <../../Engine/Header Files/Engine.h>
#include "MeshManager.h"

#include <memory>

class ChunkMesh {

public:
    ChunkMesh();
    ChunkMesh(const ChunkMesh& other) = delete;
    ChunkMesh& operator = (const ChunkMesh& other) = delete;
    ChunkMesh(ChunkMesh&& other) = default;
    ChunkMesh& operator = (ChunkMesh&& other) = default;

    const Aetherborne::Mesh& mesh() const { return m_mesh; }
    Aetherborne::Mesh& mesh() { return m_mesh; }

    bool dirty() const { return m_dirty; }
    void setDirty() { m_dirty = true; }
    void clearDirty() { m_dirty = false; }

    void clearMesh();

    int32_t vertexOffset() const { return m_mesh.vertexOffset(); }
    void setVertexOffset(int32_t vertexOffset) { m_mesh.setVertexOffset(vertexOffset); }

    void clearBindings();
    void addBinding(MeshAllocation&& allocation, size_t attributeSize);
    void setIndexBuffer(const std::shared_ptr<Aetherborne::Buffer>& buffer);

    MeshAllocation& getBinding(size_t index) { return m_allocations[index]; }

private:
    Aetherborne::Mesh m_mesh;
    bool m_dirty = false;

    std::vector<MeshAllocation> m_allocations;
};