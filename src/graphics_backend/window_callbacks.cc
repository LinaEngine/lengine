#include "window_callbacks.h"
#include <GLFW/glfw3.h>
namespace lina { namespace graphics { namespace backend { namespace callbacks{
    void key(GLFWwindow* win, i32 key, i32 scancode, i32 action, i32 mods)
	{
        std::cerr << "key: " << key << '\n';
        auto* p = (window::window_settings*)glfwGetWindowUserPointer(win);
	}
    void mouse_button(GLFWwindow* win, i32 key, i32 action, i32 mods)
	{
        std::cerr << "mouse button: " << key << '\n';
        auto* p = (window::window_settings*)glfwGetWindowUserPointer(win);
	}
    void mouse_move(GLFWwindow* win, f64 x, f64 y)
	{
        std::cerr << "Mouse Move: (" << x << ", " << y << ")" << '\n';
        auto* p = (window::window_settings*)glfwGetWindowUserPointer(win);
	}
    void window_resize(GLFWwindow* win, i32 w, i32 h)
	{
        std::cerr << "width: " <<  w << ", height: " << h << '\n';
        auto* p = (window::window_settings*)glfwGetWindowUserPointer(win);
        p->width = w;
        p->height = h;
        p->resized = true;
	}
}}}}
