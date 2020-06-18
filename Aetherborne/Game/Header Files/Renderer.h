#pragma once
#include <../../Engine/Header Files/System.h>
#include <../../Engine/RenderGraph/RenderGraph.h>
#include <../../Engine/RenderGraph/AcquireNode.h>
#include <../../Engine/RenderGraph/PresentNode.h>
#include <../../Engine/RenderGraph/TransferNode.h>
#include <../../Engine/Header Files/CameraSystem.h>
#include "Chunk.h"
#include "ChunkRenderer.h"
#include "World.h"
#include <entt/signal/sigh.hpp>
//#include "TextureManager.h"
//#include "MipmapGenerator.h"
//#include "SkyboxManager.h"
//#include "SelectionBox.h"

class MeshManager;

class Renderer : public Aetherborne::System {
public:
    Renderer(Aetherborne::Engine& engine, Aetherborne::RenderGraph& renderGraph, Aetherborne::CameraSystem& cameraSystem, World& world,/* TextureManager& textureManager, SkyboxManager& skyboxManager, SelectionBox& selectionBox,*/ MeshManager& meshManager);

    Aetherborne::TransferNode& transferNode() const { return *m_transferNode; }
    //MipmapGenerator& mipmapGenerator() const { return *m_mipmapGenerator; }
    ChunkRenderer& chunkRenderer() const { return *m_chunkRenderer; }

    void wait();

    void update(Aetherborne::Clock& clock);

private:
    Aetherborne::Engine* m_engine;
    Aetherborne::Graphics* m_graphics;
    Aetherborne::RenderGraph* m_renderGraph;
    Aetherborne::AcquireNode* m_acquireNode;
    Aetherborne::PresentNode* m_presentNode;
    Aetherborne::TransferNode* m_transferNode;
    ChunkRenderer* m_chunkRenderer;
    //MipmapGenerator* m_mipmapGenerator;
};