#ifndef ECS_MESH_COLLIDER_H
#define ECS_MESH_COLLIDER_H
#include "../collider.h"
#include "../gjk.h"
namespace lina { namespace ecs { namespace components { namespace colliders {
    class mesh : public collider
    {
        public:
            virtual bool check_collision(collider* c) override;
            virtual math::vector3d furthest_point(const math::vector3d& d) override;
            virtual void compute_BVH() override;
            virtual void compute_bounding_box() override;
        private:
            std::pair<math::vector3d, math::vector3d> compute_bounding_box(u32 idxBegin, u32 idxEnd);

        private:
                gjk::Info m_info;
                std::vector<f32> m_vertices;
                std::vector<u32> m_indices;


    };
}}}}
#endif
