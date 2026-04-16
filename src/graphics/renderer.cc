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
