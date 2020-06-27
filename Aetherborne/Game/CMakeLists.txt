cmake_minimum_required (VERSION 3.8)

project ("Game")

set(GLSL_COMPILER "C:/Users/nicho/Desktop/AetherborneDocs/Libraries/Vulkan/1.2.135.0/Bin/glslc.exe")
set(STB_INCLUDE "C:/Users/nicho/Desktop/AetherborneDocs/Libraries/stb-master")
set(FASTNOISE_ROOT "C:/Users/nicho/Desktop/AetherborneDocs/Libraries/FastNoise-master")

add_library("FastNoise"
    ${FASTNOISE_ROOT}/FastNoise.h
    ${FASTNOISE_ROOT}/FastNoise.cpp
)

add_executable("Game"
    main.cpp
    "Header Files/World.h"
    "Source Files/World.cpp"
    "Source Files/ChunkMesher.cpp"
    "Header Files/ChunkManager.h"
    "Source Files/stb.cpp"
    "Header Files/FramerateCounter.h"
    "Source Files/FramerateCounter.cpp"
    "Header Files/Renderer.h"
    "Source Files/Renderer.cpp"
    "Header Files/FreeCam.h"
    "Source Files/FreeCam.cpp"
    "Header Files/Chunk.h"
    "Source Files/Chunk.cpp"
    "Header Files/ChunkRenderer.h"
    "Source Files/ChunkRenderer.cpp"
    "Header Files/ChunkMesh.h"
    "Source Files/ChunkMesh.cpp"
    "Header Files/ChunkUpdater.h"
    "Source Files/ChunkUpdater.cpp"
    "Header Files/ChunkMesher.h"
    "Source Files/ChunkManager.cpp"
    "Header Files/BlockManager.h"
    "Source Files/BlockManager.cpp"
    "Header Files/TerrainGenerator.h"
    "Source Files/TerrainGenerator.cpp"
    "Header Files/MeshManager.h"
    "Source Files/MeshManager.cpp"
    "Header Files/PriorityQueue.h"
    "Source Files/PriorityQueue.cpp"
)

target_link_libraries("Game"
    "Engine"
    "FastNoise"
)

target_include_directories("Game"
    PRIVATE ${STB_INCLUDE}
    PRIVATE ${FASTNOISE_ROOT}
)

set(SHADER_SOURCES
    "Shaders/shader.vert" ;
    "Shaders/shader.frag" ;
)
set(SPIRV_BINARY_FILES)

foreach(SHADER_SOURCE ${SHADER_SOURCES})
    get_filename_component(FILE_NAME ${SHADER_SOURCE} NAME)
    set(SPIRV "${PROJECT_BINARY_DIR}/Shaders/${FILE_NAME}.spv")
    add_custom_command(
        OUTPUT ${SPIRV}
        COMMAND ${GLSL_COMPILER} "${PROJECT_SOURCE_DIR}/${SHADER_SOURCE}" -o ${SPIRV}
        DEPENDS ${SHADER_SOURCE})
    list(APPEND SPIRV_BINARY_FILES ${SPIRV})
endforeach(SHADER_SOURCE)

add_custom_target(
    CompileShaders 
    DEPENDS ${SPIRV_BINARY_FILES}
)

add_dependencies("Game" CompileShaders)

set_property(TARGET "Game" PROPERTY CXX_STANDARD 17)