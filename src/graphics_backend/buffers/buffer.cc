#include "buffer.h"
namespace lina{ namespace graphics{ namespace backend{
    void buffer::create()
    {
        VkBufferCreateInfo bufferInfo{};
        bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
        bufferInfo.size = m_specs.size * m_specs.count;
        bufferInfo.usage = m_specs.usage;
        bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

        if (vkCreateBuffer(m_manager->mvkdevice, &bufferInfo, nullptr, &m_specs.buffer) != VK_SUCCESS) {
            throw std::runtime_error("failed to create buffer!");
        }

        VkMemoryRequirements memRequirements;
        vkGetBufferMemoryRequirements(m_manager->mvkdevice, m_specs.buffer, &memRequirements);

        VkMemoryAllocateInfo allocInfo{};
        allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        allocInfo.allocationSize = memRequirements.size;
        allocInfo.memoryTypeIndex =
            utils::find_memory_type(m_manager->mpd.memory_properties,
                    memRequirements.memoryTypeBits,
                    m_specs.properties
                    );

        auto allocResult = (vkAllocateMemory(m_manager->mvkdevice,
                    &allocInfo,
                    nullptr,
                    &m_specs.buffer_memory));
        if  (allocResult != VK_SUCCESS){
            std::cerr<<"RESULT: " << allocResult<< '\n';
            throw std::runtime_error("failed to allocate buffer memory!");
        }

        vkBindBufferMemory(m_manager->mvkdevice, m_specs.buffer, m_specs.buffer_memory, 0);

    }
}}}
