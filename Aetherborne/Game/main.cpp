/*// IMPORT VULKAN


// IMPORT GLM
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>*/

// IMPORT ENGINE CLASSES
#include <../../Engine/Header Files/Engine.h>
#include "../../Engine/Header Files/Console.h"
#include <../../Engine/RenderGraph/AcquireNode.h>
#include <../../Engine/RenderGraph/PresentNode.h>
#include <../../Engine/Header Files/CameraSystem.h>
#include <entt/entt.hpp>

// IMPORT GAME CLASSES
#include "Header Files/FramerateCounter.h"
#include "Header Files/Renderer.h"
#include "Header Files/FreeCam.h"
#include "Header Files/Chunk.h"
#include "Header Files/ChunkMesh.h"
#include "Header Files/ChunkUpdater.h"
#include "Header Files/ChunkMesher.h"
#include "Header Files/ChunkManager.h"
#include "Header Files/BlockManager.h"
#include "Header Files/TerrainGenerator.h"
#include "Header Files/MeshManager.h"
//#include "Header Files/TextureManager.h"
//#include "SkyboxManager.h"
//#include "Header Files/SelectionBox.h"

// GENERAL IMPORTS
#include <iostream>

using namespace Aetherborne;


int main() {

    Aetherborne::Engine engine;
    Aetherborne::Window window(800, 600, "Aetherborne");
    engine.addWindow(window);

    Aetherborne::Graphics& graphics = engine.getGraphics();
    graphics.pickPhysicalDevice(window);

    Aetherborne::Console console;
    console.run();

    Aetherborne::RenderGraph renderGraph(graphics.device(), 2);
    engine.setRenderGraph(renderGraph);

    FramerateCounter counter(window, "Aetherborne");
    engine.getUpdateGroup().add(counter, 0);

    Aetherborne::Camera camera(engine, window.getFramebufferWidth(), window.getFramebufferHeight(), glm::radians(90.0f), 0.01f, 1000.0f);
    Aetherborne::CameraSystem cameraSystem(engine);
    cameraSystem.setCamera(camera);
    engine.getUpdateGroup().add(cameraSystem, 90);
    std::cout << "cameraSystem added to systems." << std::endl;

    window.onFramebufferResized().connect<&Aetherborne::Camera::setSize>(&camera);

    MeshManager meshManager(engine);
    //SkyboxManager skyboxManager(engine, cameraSystem);
    //SelectionBox selectionBox(engine, cameraSystem);
    //TextureManager textureManager(engine);
    BlockManager blockManager;
    World world(blockManager);

    FreeCam freeCam(camera, window.input(), world, blockManager/*, selectionBox*/);
    engine.getUpdateGroup().add(freeCam, 10);
    std::cout << "freeCam added to systems." << std::endl;

    freeCam.setPosition({ 0, 80, 0 });

    ChunkManager chunkManager(world, freeCam, 16);
    engine.getUpdateGroup().add(chunkManager, 20);
    std::cout << "chunkManager added to systems." << std::endl;

    TerrainGenerator terrainGenerator(world, chunkManager);
    terrainGenerator.run();
    std::cout << "terrainGenerator running." << std::endl;

    ChunkUpdater chunkUpdater(engine, world, blockManager, chunkManager);
    chunkUpdater.run();
    std::cout << "chunkUpdater running." << std::endl;

    ChunkMesher chunkMesher(engine, world, blockManager, meshManager);
    engine.getUpdateGroup().add(chunkMesher, 30);
    chunkMesher.run();
    std::cout << "chunkMesher running." << std::endl;

    chunkManager.setTerrainGenerator(terrainGenerator);
    chunkManager.setChunkUpdater(chunkUpdater);
    chunkManager.setChunkMesher(chunkMesher);

    Renderer renderer(engine, renderGraph, cameraSystem, world,/* textureManager, skyboxManager, selectionBox,*/ meshManager);
    engine.getUpdateGroup().add(renderer, 100);
    std::cout << "renderer added to systems." << std::endl;

    meshManager.setTransferNode(renderer.transferNode());
    cameraSystem.setTransferNode(renderer.transferNode());
    chunkMesher.setTransferNode(renderer.transferNode());
    //textureManager.createTexture(renderer.transferNode(), renderer.mipmapGenerator());
    //skyboxManager.transfer(renderer.transferNode());
    //skyboxManager.createPipeline(renderer.chunkRenderer().renderPass());
    //selectionBox.transfer(renderer.transferNode());
    //selectionBox.createMesh(renderer.transferNode(), meshManager);
    //selectionBox.createPipeline(renderer.chunkRenderer().renderPass());
    std::cout << "Transfer nodes set." << std::endl;

    engine.run();

    terrainGenerator.stop();
    chunkUpdater.stop();
    chunkMesher.stop();
    renderer.wait();

    std::cout << "Processes stopped." << std::endl;
    console.stop();

    return 0;
}