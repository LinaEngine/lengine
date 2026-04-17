#include "resource_manager.h"
namespace lina { namespace graphics { namespace backend {
    VkPipelineShaderStageCreateInfo* resource_manager::get_shader_info_pointer(i64 shader_idx)
    {
        if (shader_idx > m_shader_offsets.size())
        {
            m_shader_offsets.push_back((shader_offset){.stage_info = (i64)m_shader_resrouces.shader_stage_infos.size()});
            return nullptr;
        }
        else if (m_shader_offsets[shader_idx].stage_info == -1)
        {
            m_shader_offsets[shader_idx].stage_info = m_shader_resrouces.shader_stage_infos.size();
            return nullptr;
        }
        return &m_shader_resrouces.shader_stage_infos[m_shader_offsets[shader_idx].stage_info];
    }
    VkPushConstantRange* resource_manager::get_ps_range_pointer(i64 shader_idx)
    {
        if (shader_idx > m_shader_offsets.size())
        {
            m_shader_offsets.push_back((shader_offset){.ps_range = (i64)m_shader_resrouces.ps_ranges.size()});
            return nullptr;
        }
        else if (m_shader_offsets[shader_idx].ps_range == -1)
        {
            m_shader_offsets[shader_idx].ps_range = m_shader_resrouces.ps_ranges.size();
            return nullptr;
        }
        return &m_shader_resrouces.ps_ranges[m_shader_offsets[shader_idx].ps_range];
    }
    VkPipelineVertexInputStateCreateInfo* resource_manager::get_vertex_info_pointer(i64 vertex_idx)
    {
        if (vertex_idx > m_vertex_offsets.size())
        {
            m_vertex_offsets.push_back(m_vert_input_infos.size());
            return nullptr;
        }
        return &m_vert_input_infos[m_vertex_offsets[vertex_idx]];
    }
    VkDescriptorSetLayout* resource_manager::get_dset_layout_pointer(i64 shader_idx)
    {
        if (shader_idx > m_shader_offsets.size())
        {
            m_shader_offsets.push_back((shader_offset){.dset_layout = (i64)m_shader_resrouces.dset_layout.size()});
            return nullptr;
        }
        else if (m_shader_offsets[shader_idx].dset_layout == -1 || m_shader_offsets[shader_idx].dset_layout >= m_shader_resrouces.dset_layout.size())
        {
            m_shader_offsets[shader_idx].dset_layout = m_shader_resrouces.dset_layout.size();
            return nullptr;
        }
        return &m_shader_resrouces.dset_layout[m_shader_offsets[shader_idx].dset_layout];
    }
}}}
