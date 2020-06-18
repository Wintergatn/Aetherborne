#include <../../Engine/Header Files/Engine.h>
#include <../../Engine/RenderGraph/TransferNode.h>
#include <../../Engine/Header Files/BlockingQueue.h>
#include <../../Engine/Header Files/BufferedQueue.h>
#include <entt/entt.hpp>
#include "Chunk.h"
#include "BlockManager.h"
#include "World.h"
#include "MeshManager.h"

struct ChunkVertex {
    glm::i8vec4 posData;
    glm::i8vec4 colorData;
    glm::i8vec4 uvData;
};

struct MeshUpdate {
    std::vector<ChunkVertex> vertexData;
    uint32_t indexCount;
};

struct MeshUpdate2 {
    size_t index;
    glm::ivec3 coord;
    ChunkData<Light, Chunk::chunkSize + 2> lightBuffer;
};

class ChunkMesher : public Aetherborne::System {
    static const size_t queueSize = 16;
public:
    ChunkMesher(Aetherborne::Engine& engine, World& world, BlockManager& blockManager, MeshManager& meshManager);

    void setTransferNode(Aetherborne::TransferNode& transferNode);

    void update(Aetherborne::Clock& clock);

    void run();
    void stop();

    bool queue(glm::ivec3 coord);

private:
    using ChunkBuffer = ChunkData<Block, Chunk::chunkSize + 2>;
    using LightBuffer = ChunkData<Light, Chunk::chunkSize + 2>;

    Aetherborne::Engine* m_engine;
    Aetherborne::TransferNode* m_transferNode;
    World* m_world;
    BlockManager* m_blockManager;
    MeshManager* m_meshManager;

    bool m_running = false;
    std::thread m_thread;

    std::array<MeshUpdate, queueSize * 2> m_updates;
    size_t m_updateIndex = 0;
    Aetherborne::BlockingQueue<glm::ivec3> m_requestQueue;
    Aetherborne::BufferedQueue<MeshUpdate2> m_resultQueue;

    size_t makeMesh(glm::ivec3 worldChunkPos, ChunkBuffer& chunkBuffer, LightBuffer& lightBuffer);
    void transferMesh(entt::entity entity, size_t index);

    void update(glm::ivec3 worldChunkPos);

    void loop();
};