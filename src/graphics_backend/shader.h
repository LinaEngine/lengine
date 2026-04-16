#ifndef SHADER_H
#define SHADER_H
#include "../core/common.h"
namespace lina { namespace graphics { namespace backend {
    class shader 
    {
        public:
            b8 load_program(i32 idx, const char* src);
            i32 add_program(const char* src);
            const inline std::vector<std::vector<char>>& get_programs() const {return mprograms;}
        private:
            std::vector<std::vector<char>> mprograms;
    };
}}}
#endif
