// IMPORT VULKAN
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// IMPORT GLM
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

// IMPORT CONSOLE CLASSES
#include "ConsoleGUI.h"
#include "Console.h"
#include "AddTimestamp.h"

// GENERAL IMPORTS
#include <iostream>
#include <thread>


Console console;


// Console function to run in thread alongside main game window.
void console_thread() {

    // Attach timestamps to iostream -- attaches to every newline. Only call once.
    AddTimestamp ats(std::cout);

    // RedirectIOToConsole redirects functions like printf straight to the console. Only call once.
    RedirectIOToConsole();

    // Console input -------------------------------
    while (console.isActive()) {
        std::string cmd = console.getInput();
        if (cmd != "") console.parseCommand(cmd);
    }

}


int main() {

    // Start the console thread.
    std::thread consoleObj(console_thread);


    // Check extensions for Vulkan.
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::cout << extensionCount << " extensions supported." << std::endl;


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