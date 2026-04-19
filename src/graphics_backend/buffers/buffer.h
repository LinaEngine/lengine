#ifndef BACKEND_BUFFER_H
#define BACKEND_BUFFER_H
#include <vulkan/vulkan_core.h>
#include "../utils.h"
#include <lmath/types.h>
#include "../backend_manager.h"
#include <iostream>
namespace lina{ namespace graphics{ namespace backend{
    class manager;
    class buffer
    {
        struct specs
        {
            u32 count = 1;
            VkDeviceSize size;
            u32 unaligned_size = 0;
            VkBufferUsageFlags usage;
            VkMemoryPropertyFlags properties;
            VkBuffer buffer;
            VkDeviceMemory buffer_memory;
        };
        public:
            virtual void create();
            inline VkDeviceSize get_size() const{ return m_specs.size; }
            inline VkBuffer& get_buffer() { return m_specs.buffer; }
            inline u32 get_count() const {return m_specs.count;}
        protected:
            manager* m_manager;
            specs m_specs;

    };
}}}
#endif
