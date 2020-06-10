/*// IMPORT VULKAN
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// IMPORT GLM
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>*/

// IMPORT ENGINE CLASSES
#include <../../Engine/Header Files/Engine.h>
#include <../../Engine/RenderGraph/AcquireNode.h>
#include <../../Engine/RenderGraph/PresentNode.h>
#include <../../Engine/Header Files/CameraSystem.h>
#include <entt/entt.hpp>

#include "../../Engine/Header Files/ConsoleGUI.h"
#include "../../Engine/Header Files/Console.h"
#include "../../Engine/Header Files/AddTimestamp.h"

// IMPORT GAME CLASSES
#include "Header Files/FramerateCounter.h"
#include "Header Files/Renderer.h"
#include "Header Files/FreeCam.h"
#include "Header Files/Chunk.h"
#include "Header Files/ChunkMesh.h"
#include "Header Files/ChunkUpdater.h"

// GENERAL IMPORTS
#include <iostream>
#include <thread>


using namespace Aetherborne;

// Console function to run in thread alongside main game window.
void console_thread() {

    //Console console;
    //ConsoleGUI consoleGUI;

    // Attach timestamps to iostream -- attaches to every newline. Only call once.
    //AddTimestamp ats(std::cout);

    // RedirectIOToConsole redirects functions like printf straight to the console. Only call once.
    //consoleGUI.RedirectIOToConsole();

    // Console input -------------------------------
    /*while (console.isActive()) {
        std::string cmd = console.getInput();
        if (cmd != "") console.parseCommand(cmd);
    }*/

}


int main() {

    // Start the console thread.
    //std::thread consoleObj(console_thread);


    // Check extensions for Vulkan.
    //uint32_t extensionCount = 0;
    //vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    //std::cout << extensionCount << " extensions supported." << std::endl;


    while (true) {

    }
    
    /*glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

    

    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();*/



    return 0;
}