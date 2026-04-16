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
        mmanger.bind(idx);
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

    void renderer::load_default_shaders()
    {
        backend::shader shader;
        mmanger.create_default_render_pass();
        shader.add_program("src/defaults/compiled_shaders/default.vert.spv");
        shader.add_program("src/defaults/compiled_shaders/default.frag.spv");
        mmanger.create_shader(shader);
        mmanger.create_default_graphics_pipeline();
    }
}}
