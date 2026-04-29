#ifndef RENDERER_H
#define RENDERER_H
#include "../graphics_backend/backend_manager.h"
#include "../graphics_backend/buffers/vertex_buffer.h"
#include "../graphics_backend/buffers/index_buffer.h"
#include "render_settings.h"
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
            template<typename T>
            u32 add_mesh(
                    backend::vblayout& layout, const std::vector<T>& verts, const std::vector<u32>&ind);
            u32 add_mapping(u32 vidx, u32 sidx);
            inline void set_mesh_shader(i32 mesh_id, i32 shader_id);
            void submit_scene();
            void render();
            inline void set_wireframe();
            inline void set_solid();
            inline void set_point();
        private:
            backend::manager mmanger;
            std::vector<backend::buffers::vertex> mvertex_buffers;
            std::vector<backend::buffers::index> mindex_buffers;
            std::vector<backend::shader> mshaders;
            std::vector<std::pair<i32, i32>> mshader_mappings;
            u32 mcurr_pipeline = 0;
            renderer_settings msettings;
    };
    inline void renderer::set_wireframe() {msettings.sdraw = draw_mode::wireframe;}
    inline void renderer::set_solid() {msettings.sdraw = draw_mode::solid;}
    inline void renderer::set_point() {msettings.sdraw = draw_mode::point;}
    template<typename T>
    u32 renderer::add_mesh(
                    backend::vblayout& layout, const std::vector<T>& verts, const std::vector<u32>&indices)
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

}}
#endif
