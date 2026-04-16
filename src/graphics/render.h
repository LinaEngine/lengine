#ifndef RENDERER_H
#define RENDERER_H
#include "../graphics_backend/backend_manager.h"
namespace lina { namespace graphics {
    class renderer
    {
        public: 
            inline b8 init(backend::window* w) {return mmanger.init(w);}
            void begin_draw();
            void end_draw();
            void bind(u32 idx = 0);
            void load_default_shaders();
        private:
            backend::manager mmanger;
    };
}}
#endif
