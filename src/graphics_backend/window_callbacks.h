#ifndef WINDOW_CALLBACKS_H
#define WINDOW_CALLBACKS_H
#include <GLFW/glfw3.h>
#include "../core/common.h"
#include "window.h"
namespace lina { namespace graphics { namespace backend { namespace callbacks{
    void key(GLFWwindow* win, i32 key, i32 scancode, i32 action, i32 mods);
    void mouse_button(GLFWwindow* win, i32 key, i32 action, i32 mods);
    void mouse_move(GLFWwindow* win, f64 x, f64 y);
    void window_resize(GLFWwindow* win, i32 w, i32 h);
}}}}
#endif
