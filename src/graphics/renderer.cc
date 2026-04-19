#include "render.h"

namespace lina { namespace graphics {
    void renderer::begin_draw()
    {
        mmanger.begin_draw();
    }
    void renderer::end_draw()
    {
        mmanger.end_draw();
    }
    void renderer::bind(u32 idx)
    {
        mcurr_pipeline = idx;
        mmanger.bind(idx);
    }
    void renderer::render()
    {
        auto vertId = mshader_mappings[mcurr_pipeline].second;
        auto vb = mvertex_buffers[vertId];
        auto ib = mindex_buffers[vertId];
        VkBuffer vbs[] = vb.m_specs.buffer;
        VkDeviceSize offsets[] = {0};

        vkCmdBindVertexBuffers(mmanger.mvk_command_buffer, 0,  1, vbs, offsets);

        vkCmdBindIndexBuffer(mmanger.mvk_command_buffer,
                ib.m_specs.buffer, 0, VK_INDEX_TYPE_UINT32);

        vkCmdDrawIndexed(
                mmanger.mvk_command_buffer,
                ib.m_count, 1, 0, 0, 0);
    }
    u32 renderer::add_mesh(backend::vblayout& layout, const std::vector<f64>& verts, const std::vector<u32>& indices)
    {
        backend::buffers::vertex vb;
        vb.init(&mmanger, layout);
        vb.construct(&verts[0],
                verts.size() * sizeof(verts[0]));
        mvertex_buffers.push_back(vb);

        backend::buffers::index ib;
        ib.init(&mmanger);
        ib.construct(&indices[0],
                indices.size() * sizeof(indices[0]));
        mindex_buffers.push_back(ib);

        return mindex_buffers.size() - 1;
    }
    u32 renderer::add_shader(const backend::shader& s)
    {
        mshaders.push_back(s);
        return mshaders.size() - 1;
    }
    u32 renderer::add_mapping(u32 vidx, u32 sidx)
    {
        mshader_mappings.push_back({vidx, sidx});
    }

    void renderer::submit_scene()
    {
        mmanger.create_default_render_pass();
        for (const auto& [vidx, sidx] : mshader_mappings)
        {
            mmanger.create_pipeline(mvertex_buffers[vidx], mshaders[sidx], vidx, sidx);
        }
    }

    void renderer::load_default_shaders()
    {
        /*
        backend::shader shader;
        mmanger.create_default_render_pass();
        shader.add_program("src/defaults/compiled_shaders/default.vert.spv", backend::ShaderStage::Vertex);
        shader.add_program("src/defaults/compiled_shaders/default.frag.spv", backend::ShaderStage::Fragment);
        mmanger.create_shader(shader);
        mmanger.create_default_graphics_pipeline();
        */
    }
}}
