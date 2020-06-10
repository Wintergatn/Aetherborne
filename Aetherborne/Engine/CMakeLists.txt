cmake_minimum_required (VERSION 3.8)

project ("Engine")

set(GLFW_ROOT "C:/Users/nicho/OneDrive/Desktop/AetherborneDocs/Libraries/glfw-3.3.2")
set(GLFW_BUILD "C:/Users/nicho/OneDrive/Desktop/AetherborneDocs/Libraries/glfw-3.3.2/build")
set(VULKAN_ROOT "C:/Users/nicho/OneDrive/Desktop/AetherborneDocs/Libraries/Vulkan/1.2.135.0")
set(VKW_ROOT "C:/Users/nicho/OneDrive/Desktop/AetherborneDocs/Libraries/VulkanWrapper-master")
set(VKW_BUILD "C:/Users/nicho/OneDrive/Desktop/AetherborneDocs/Libraries/VulkanWrapper-master/build")
set(VMA_INCLUDE "C:/Users/nicho/OneDrive/Desktop/AetherborneDocs/Libraries/VulkanMemoryAllocator-master/src")
set(GLM_INCLUDE "C:/Users/nicho/OneDrive/Desktop/AetherborneDocs/Libraries/glm")
set(ENTT_INCLUDE "C:/Users/nicho/OneDrive/Desktop/AetherborneDocs/Libraries/entt-master/src")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "C:/Users/nicho/OneDrive/Desktop/AetherborneDocs/Libraries/glfw-3.3.2/docs" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "C:/Users/nicho/OneDrive/Desktop/AetherborneDocs/Libraries/glfw-3.3.2/tests" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "C:/Users/nicho/OneDrive/Desktop/AetherborneDocs/Libraries/glfw-3.3.2/examples" FORCE)

add_subdirectory(${GLFW_ROOT} ${GLFW_BUILD} EXCLUDE_FROM_ALL)

add_library("Engine"
    "Header Files/Math.h"
    "Source Files/vma.cpp"
    "Header Files/Engine.h"
    "Source Files/Engine.cpp"
    "Header Files/Window.h"
    "Source Files/Window.cpp"
    "Header Files/System.h"
    "Source Files/System.cpp"
    "Header Files/Clock.h"
    "Source Files/Clock.cpp"
    "Header Files/Graphics.h"
    "Source Files/Graphics.cpp"
    "Header Files/MemoryManager.h"
    "Source Files/MemoryManager.cpp"
    "Header Files/Buffer.h"
    "Source Files/Buffer.cpp"
    "Header Files/Mesh.h"
    "Source Files/Mesh.cpp"
    "RenderGraph/RenderGraph.h"
    "RenderGraph/RenderGraph.cpp"
    "RenderGraph/AcquireNode.h"
    "RenderGraph/AcquireNode.cpp"
    "RenderGraph/PresentNode.h"
    "RenderGraph/PresentNode.cpp"
    "RenderGraph/TransferNode.h"
    "RenderGraph/TransferNode.cpp"
    "Header Files/Utilities.h"
    "Source Files/Utilities.cpp"
    "Header Files/UniformWriter.h"
    "Source Files/UniformWriter.cpp"
    "Header Files/BufferWriter.h"
    "Source Files/BufferWriter.cpp"
    "Header Files/Camera.h"
    "Source Files/Camera.cpp"
    "Header Files/CameraSystem.h"
    "Source Files/CameraSystem.cpp"
    "Header Files/Input.h"
    "Source Files/Input.cpp"
    "Header Files/Image.h"
    "Source Files/Image.cpp"
 "Header Files/DirectedAcyclicGraph.h")

target_compile_definitions("Engine" PUBLIC
    GLM_FORCE_RADIANS
    GLM_FORCE_DEPTH_ZERO_TO_ONE
)

target_include_directories("Engine"
    PUBLIC "${GLFW_ROOT}/include"
    PUBLIC "./include"
    PUBLIC "${VULKAN_ROOT}/Include"
    PUBLIC "${VKW_ROOT}/include"
    PUBLIC "${VMA_INCLUDE}"
    PUBLIC "${GLM_INCLUDE}"
    PUBLIC "${ENTT_INCLUDE}"
)

target_link_libraries("Engine"
    "${GLFW_BUILD}/src/Debug/glfw3.lib"
    "${VKW_BUILD}/src/Debug/VulkanWrapper.lib"
    "${VULKAN_ROOT}/Lib/vulkan-1.lib"
)

set_property(TARGET "Engine" PROPERTY CXX_STANDARD 17)