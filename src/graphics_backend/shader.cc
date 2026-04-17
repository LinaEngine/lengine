#include "shader.h"
#include <fstream>
namespace lina { namespace graphics { namespace backend {
    i32 shader::add_program(const char* src, ShaderStage st)
    {
        auto idx = mprograms.size();
        mprograms.emplace_back();
        if (load_program(idx, src, st))
        {
            return idx;
        }
        return -1;
    }
    b8 shader::load_program(i32 idx, const char* src, ShaderStage st)
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
        mprograms[idx].program.resize(file_size);
        file.seekg(0);
        file.read(mprograms[idx].program.data(), file_size);
        file.close();
        mprograms[idx].stage = st;
        return true;
    }
    void shader::combine_uniforms()
    {
        m_uniforms.clear();
        m_uniforms.reserve(m_static_uniforms.size() + m_dynamic_uniforms.size());
        for (auto& u : m_static_uniforms)
        {
            m_uniforms.push_back(u);
        }
        for (auto& u : m_dynamic_uniforms)
        {
            m_uniforms.push_back(u);
        }
    }
    void shader::add_uniform(Uniform&& u)
    {
        switch(u.type)
        {
            case UniformType::Static:
                {
                    m_static_uniforms.push_back(u);
                }
                break;
            case UniformType::Dynamic:
                {
                    m_dynamic_uniforms.push_back(u);
                }
        };
    }
    void shader::add_ps(PushConstant&& ps)
    {
        m_push_constants.push_back(ps);
    }
}}}
