#pragma once
#include <vector>
#include <string>
#include <VulkanWrapper/VulkanWrapper.h>

namespace Aetherborne {

    size_t align(size_t ptr, size_t alignment);
    std::vector<char> readFile(const std::string& filename);
    vk::ShaderModule createShaderModule(vk::Device& device, const std::vector<char>& byteCode);

}