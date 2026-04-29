#ifndef BACKEND_BUFFER_UNIFORM_H
#define BACKEND_BUFFER_UNIFORM_H
#include "../backend_manager.h"
#include "buffer.h"
#include <vulkan/vulkan.h>
namespace lina { namespace graphics { namespace backend { namespace buffers {
    class uniform  : public buffer
    {
        public:
            void init(manager* device);
            void construct(u32 size, u32 count = 1);
            void write_data(void* data, i32 slot = 0);
        private:
            void* m_data;
    };
}}}}
#endif
