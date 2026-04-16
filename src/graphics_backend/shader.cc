#include "shader.h"
#include <fstream>
namespace lina { namespace graphics { namespace backend {
    i32 shader::add_program(const char* src)
    {
        auto idx = mprograms.size();
        mprograms.emplace_back();
        if (load_program(idx, src))
        {
            return idx;
        }
        return -1;
    }
    b8 shader::load_program(i32 idx, const char* src)
    {
        if (idx > mprograms.size()-1) 
        {
            return false;
        }
        std::ifstream file(src, std::ios::ate | std::ios::binary);
        if (!file)
        {
            return false;
        }
        u32 file_size = (u32) file.tellg();
        mprograms[idx].resize(file_size);
        file.seekg(0);
        file.read(mprograms[idx].data(), file_size);
        file.close();
        return true;
    }
}}}
