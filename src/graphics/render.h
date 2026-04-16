#ifndef RENDERER_H
#define RENDERER_H
#include "../graphics_backend/backend_manager.h"
#include "../graphics_backend/buffers/vertex_buffer.h"
#include "../graphics_backend/buffers/index_buffer.h"
namespace lina { namespace graphics {
    class renderer
    {
        public: 
            inline b8 init(backend::window* w) {return mmanger.init(w);}
            void begin_draw();
            void end_draw();
            void bind(u32 idx = 0);
            void load_default_shaders();
            u32 add_shader(const backend::shader& s);
            u32 add_mesh(backend::vblayout& layout, const std::vector<f64>& verts, const std::vector<u32>&);
        private:
            backend::manager mmanger;
            std::vector<backend::buffers::vertex> mvertex_buffers;
            std::vector<backend::buffers::index> mindex_buffers;
            std::vector<backend::shader> mshaders;
            std::vector<i32> shader_ids;
    };
}}
#endif
