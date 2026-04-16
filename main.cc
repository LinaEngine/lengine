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
    rend.load_default_shaders();
    while (!w->is_closed())
    {
        rend.begin_draw();
        rend.bind();
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
