#include "src/core/types.h"
#include "src/graphics_backend/buffers/vertex_buffer.h"
#include "src/graphics_backend/buffers/vertex_buffer_layout.h"
#include "src/graphics_backend/shader.h"
#include "src/graphics_backend/window.h"
#include "src/tests/tests.h"
#define DBG (0)
#include "src/graphics/render.h"
void run_engine()
{
    lina::graphics::renderer rend;
    lina::graphics::backend::window::window_settings ws = 
    {
        .name = "lina_window",
        .width = 600.,
        .height = 600.,
    };
    lina::graphics::backend::window* w = new lina::graphics::backend::window(ws);
    rend.init(w);
    lina::graphics::backend::shader sh;
    sh.add_program("src/defaults/compiled_shaders/default.vert.spv", lina::graphics::backend::ShaderStage::Vertex);
    sh.add_program("src/defaults/compiled_shaders/default.frag.spv", lina::graphics::backend::ShaderStage::Fragment);
    rend.add_shader(sh);
    lina::graphics::backend::vblayout layout;
    std::vector<f32> data = 
    {
        0., -0.5, 0., 1., 0., 0.,
        -0.5, 0.0, 0., 0., 1., 0.,
        0.5, 0.0, 0., 0., 0., 1.,
    };
    layout.push(lina::graphics::backend::Format::Float3, 0);
    layout.push(lina::graphics::backend::Format::Float3, 1);
    std::vector<u32> inds = {0, 1, 2};
    rend.add_mesh(layout, data, inds);
    rend.add_mapping(0, 0);
    rend.submit_scene();
    while (!w->is_closed())
    {
        rend.begin_draw();
        rend.bind();
        rend.render();
        rend.end_draw();
        w->update();
    }
}
int main()
{
    #if DBG
    std::cerr << "beginning engine\n";
    lina::tests::run_all();
    std::cerr << "ending engine\n";
    #endif
    run_engine();
}
