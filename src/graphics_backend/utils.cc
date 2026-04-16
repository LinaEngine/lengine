#include "utils.h"
#include <iostream>
namespace lina { namespace graphics { namespace backend { namespace utils {
    u32 find_memory_type(VkPhysicalDeviceMemoryProperties memProperties, u32 typeFilter, VkMemoryPropertyFlags flags)
    {
        for (u32 i = 0; i < memProperties.memoryTypeCount; i++) 
        {
            if ((typeFilter & (1 << i))
                    && (memProperties.memoryTypes[i].propertyFlags & flags) == flags) {
                return i;
            }
        }
        std::cerr << "failed to find memory type!\n";
    }
}}}}
