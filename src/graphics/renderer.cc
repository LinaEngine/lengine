#include "render.h"
#include <utility>
#include <vulkan/vulkan_core.h>

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
        PFN_vkCmdSetPolygonModeEXT vkCmdSetPolygonModeEXT = 
            reinterpret_cast<PFN_vkCmdSetPolygonModeEXT>(vkGetDeviceProcAddr(
                        mmanger.mvkdevice, "vkCmdSetPolygonModeEXT"));
        vkCmdSetPrimitiveTopology(mmanger.mvk_command_buffer,
                (VkPrimitiveTopology)msettings.sprimitive);
        vkCmdSetPolygonModeEXT(mmanger.mvk_command_buffer,
                (VkPolygonMode)msettings.sdraw);
        auto vertId = mshader_mappings[mcurr_pipeline].second;
        auto vb = mvertex_buffers[vertId];
        auto ib = mindex_buffers[vertId];
        VkBuffer vbs[] = {vb.get_buffer()};
        VkBuffer ib_buf = ib.get_buffer();
        VkDeviceSize offsets[] = {0};

        vkCmdBindVertexBuffers(mmanger.mvk_command_buffer, 0,  1, vbs, offsets);

        vkCmdBindIndexBuffer(mmanger.mvk_command_buffer,
                ib_buf, 0, VK_INDEX_TYPE_UINT32);

        vkCmdDrawIndexed(
                mmanger.mvk_command_buffer,
                ib.get_count(), 1, 0, 0, 0);
    }
    u32 renderer::add_shader(const backend::shader& s)
    {
        mshaders.push_back(s);
        return mshaders.size() - 1;
    }
    u32 renderer::add_mapping(u32 vidx, u32 sidx)
    {
        mshader_mappings.push_back(std::make_pair(vidx, sidx));
        return 0;
    }

    void renderer::submit_scene()
    {
        mmanger.create_default_render_pass();
        for (const auto& [vidx, sidx] : mshader_mappings)
        {
            mmanger.create_graphics_pipeline(&mvertex_buffers[vidx], &mshaders[sidx], vidx, sidx);
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
