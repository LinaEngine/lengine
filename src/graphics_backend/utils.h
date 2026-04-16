#ifndef BACKEND_UTILS_H
#define BACKEND_UTILS_H
#include <vulkan/vulkan.h>
#include <lmath/types.h>
namespace lina { namespace graphics { namespace backend { namespace utils {
       u32 find_memory_type(VkPhysicalDeviceMemoryProperties props, u32 typeFilter, VkMemoryPropertyFlags flags);
}}}}
#endif
