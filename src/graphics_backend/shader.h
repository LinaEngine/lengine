#ifndef SHADER_H
#define SHADER_H
#include "../core/common.h"
#include <vulkan/vulkan_core.h>
namespace lina { namespace graphics { namespace backend {
    enum class ShaderStage
    {
        None,
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
    struct Program 
    {
        ShaderStage stage;
        std::vector<char> program;
    };
    enum class UniformType
    {
        Static = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
        Dynamic = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC,
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
            b8 load_program(i32 idx, const char* src, ShaderStage st);
            i32 add_program(const char* src, ShaderStage st);
            void add_uniform(Uniform&& u);
            void add_ps(PushConstant&& ps);
            void combine_uniforms();
            inline u32 get_binding_count() const;
            inline u32 get_uniform_count() const;
            const inline std::vector<Program>& get_programs() const;
            const inline std::vector<PushConstant>& get_ps() const;
            const inline std::vector<Uniform>& get_uniforms() const;

        private:
            std::vector<Program> mprograms;
            std::vector<PushConstant> m_push_constants;
            std::vector<Uniform> m_uniforms;
            std::vector<Uniform> m_static_uniforms;
            std::vector<Uniform> m_dynamic_uniforms;
    };
    u32 shader::get_binding_count()const {return m_static_uniforms.size() + m_dynamic_uniforms.size();}
    u32 shader::get_uniform_count()const {return m_static_uniforms.size() + m_dynamic_uniforms.size();}
    const inline std::vector<Program>& shader::get_programs() const {return mprograms;}
    const inline std::vector<PushConstant>& shader::get_ps()const {return m_push_constants;}
    const inline std::vector<Uniform>& shader::get_uniforms() const {return m_uniforms;};
}}}
#endif
