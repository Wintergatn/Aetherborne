#pragma once
#include <VulkanWrapper/VulkanWrapper.h>
#include <../../Engine/Header Files/Engine.h>
#include <../../Engine/RenderGraph/RenderGraph.h>
#include <../../Engine/RenderGraph/AcquireNode.h>
#include <../../Engine/RenderGraph/TransferNode.h>
#include <../../Engine/Header Files/CameraSystem.h>
#include <entt/entt.hpp>

#include <../../Engine/Header Files/CameraSystem.h>
#include <entt/entt.hpp>
//#include "TextureManager.h"
//#include "SkyboxManager.h"
//#include "SelectionBox.h"
#include "World.h"

class MeshManager;

class ChunkRenderer : public Aetherborne::RenderGraph::Node {
public:
    ChunkRenderer(Aetherborne::Engine& engine, Aetherborne::RenderGraph& graph, Aetherborne::AcquireNode& acquireNode, Aetherborne::TransferNode& transferNode, Aetherborne::CameraSystem& cameraSystem, World& world,/* TextureManager& textureManager, SkyboxManager& skyboxManager, SelectionBox& selectionBox, */MeshManager& meshManager);

    vk::RenderPass& renderPass() const { return *m_renderPass; }
    Aetherborne::RenderGraph::BufferUsage& uniformBufferUsage() const { return *m_uniformBufferUsage; }
    Aetherborne::RenderGraph::BufferUsage& vertexBufferUsage() const { return *m_vertexBufferUsage; }
    Aetherborne::RenderGraph::BufferUsage& indexBufferUsage() const { return *m_indexBufferUsage; }
    Aetherborne::RenderGraph::ImageUsage& textureUsage() const { return *m_textureUsage; }
    Aetherborne::RenderGraph::ImageUsage& skyboxUsage() const { return *m_skyboxUsage; }
    Aetherborne::RenderGraph::ImageUsage& selectionTextureUsage() const { return *m_selectionTextureUsage; }
    Aetherborne::RenderGraph::ImageUsage& imageUsage() const { return *m_imageUsage; }

    void preRender(uint32_t currentFrame);
    void render(uint32_t currentFrame, vk::CommandBuffer& commandBuffer);
    void postRender(uint32_t currentFrame) {}

private:
    Aetherborne::Engine* m_engine;
    Aetherborne::Graphics* m_graphics;
    Aetherborne::AcquireNode* m_acquireNode;
    Aetherborne::TransferNode* m_transferNode;
    Aetherborne::CameraSystem* m_cameraSystem;
    World* m_world;
    //TextureManager* m_textureManager;
    //SkyboxManager* m_skyboxManager;
    //SelectionBox* m_selectionBox;
    MeshManager* m_meshManager;

    std::unique_ptr<Aetherborne::Image> m_depthBuffer;
    std::unique_ptr<vk::ImageView> m_depthBufferView;
    std::unique_ptr<vk::RenderPass> m_renderPass;
    std::vector<vk::Framebuffer> m_framebuffers;
    std::unique_ptr<vk::PipelineLayout> m_pipelineLayout;
    std::unique_ptr<vk::Pipeline> m_pipeline;

    std::unique_ptr<Aetherborne::RenderGraph::BufferUsage> m_uniformBufferUsage;
    std::unique_ptr<Aetherborne::RenderGraph::BufferUsage> m_vertexBufferUsage;
    std::unique_ptr<Aetherborne::RenderGraph::BufferUsage> m_indexBufferUsage;
    std::unique_ptr<Aetherborne::RenderGraph::ImageUsage> m_textureUsage;
    std::unique_ptr<Aetherborne::RenderGraph::ImageUsage> m_skyboxUsage;
    std::unique_ptr<Aetherborne::RenderGraph::ImageUsage> m_selectionTextureUsage;
    std::unique_ptr<Aetherborne::RenderGraph::ImageUsage> m_imageUsage;

    void createDepthBuffer();
    void createRenderPass();
    void createFramebuffers();
    void createPipelineLayout();
    void createPipeline();

    void onSwapchainChanged(vk::Swapchain& swapchain);
};