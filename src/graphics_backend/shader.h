#ifndef SHADER_H
#define SHADER_H
#include "../core/common.h"
namespace lina { namespace graphics { namespace backend {
    enum class ShaderStage
    {
        Vertex = VK_SHADER_STAGE_VERTEX_BIT,
        Fragment = VK_SHADER_STAGE_FRAGMENT_BIT,
        All = VK_SHADER_STAGE_ALL
    };
    struct PushConstant
    {
        ShaderStage stage;   
        u32 offset;
        u32 size;
    };
    enum class UniformType
    {
        Static,
        Dynamic,
    };
    struct Uniform
    {
        std::string name = "";
        u32 binding;
        ShaderStage stage;
        UniformType type = UniformType::Static;
        u32 size;
        u32 count = 1;
    };

    class shader 
    {
        public:
            b8 load_program(i32 idx, const char* src);
            i32 add_program(const char* src);
            const inline std::vector<std::vector<char>>& get_programs() const {return mprograms;}
            void add_uniform(Uniform&& u);
            void add_ps(PushConstant&& ps);
            void combine_uniforms();
            inline u32 get_binding_count() const;
            inline u32 get_uniform_count() const;
        private:
            std::vector<std::vector<char>> mprograms;
            std::vector<PushConstant> m_push_constants;
            std::vector<Uniform> m_uniforms;
            std::vector<Uniform> m_static_uniforms;
            std::vector<Uniform> m_dynamic_uniforms;
    };
    u32 shader::get_binding_count()const {return m_static_uniforms.size() + m_dynamic_uniforms.size();}
    u32 shader::get_uniform_count()const {return m_static_uniforms.size() + m_dynamic_uniforms.size();}
}}}
#endif
