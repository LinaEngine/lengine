#ifndef ECS_TRANSFORM_H
#define ECS_TRANSFORM_H
#include <lmath/all.h>
#include <lmath/transformations.h>
namespace lina { namespace ecs {  namespace components{
    class transform
    {
        public: 
            transform() :m_computed(false), mscale(math::vector3d(1., 1., 1.)){}

            inline void set_pos(math::vector3d&& p);
            inline void set_rot(math::vector3d&& p);
            inline void set_scale(math::vector3d&& p);
            inline const math::vector3d& get_pos() const;
            inline const math::vector3d& get_rot() const;
            inline const math::vector3d& get_scale() const;
        public:
            inline void move(math::vector3d&& inc);
            inline void rotate(math::vector3d&& inc);
            inline void expand(math::vector3d&& inc);
            void compute_matrix(bool compute_inv = true);
            math::mat4 get_transformation_matrix();
            math::mat4 get_inv_transformation_matrix();
        private:
            math::vector3d mpos;
            math::vector3d mrot;
            math::vector3d mscale;
            math::mat4 m_tarns_matrix;
            math::mat4 m_inv_matrix;
            bool m_computed;
    };
    inline void transform::move(math::vector3d&& inc) {mpos += inc; m_computed = false;}
    inline void transform::rotate(math::vector3d&& inc) {mrot += inc; m_computed = false;}
    inline void transform::expand(math::vector3d&& inc) {mscale = mscale * inc; m_computed = false;}
    inline void transform::set_pos(math::vector3d&& v) {mpos = v; m_computed = false;}
    inline void transform::set_rot(math::vector3d&& v) {mrot = v; m_computed = false;}
    inline void transform::set_scale(math::vector3d&& v) {mscale = v; m_computed = false;}
    inline const math::vector3d& transform::get_pos() const
    {
        return mpos;
    }
    inline const math::vector3d& transform::get_rot() const
    {
        return mrot;
    }
    inline const math::vector3d& transform::get_scale() const
    {
        return mscale;
    }
}}}
#endif
