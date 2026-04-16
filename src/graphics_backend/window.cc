#include "window.h"
#include "window_callbacks.h"
#include <GLFW/glfw3.h>

namespace lina { namespace graphics { namespace backend { 
    window::window(window_settings& s) : msettings(s), mwindow(nullptr)
    {
        create();
    }
    window::~window()
    {
        if (mwindow)
        {
            glfwDestroyWindow(mwindow);
        }
        glfwTerminate();
    }
    b8 window::create()
    {
        if (!init())
        {
            return false;
            glfwTerminate();
        }
        return true;
    }

    b8 window::init()
    {
        if (!glfwInit())
        {
            return false;
        }
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // pure vulkan
        glfwWindowHint(GLFW_RESIZABLE, msettings.resizable);
        glfwGetError(nullptr);
        mwindow = glfwCreateWindow(
                msettings.width,
                msettings.height, msettings.name,
                NULL, NULL);
        if (!mwindow) return false;
        glfwSwapInterval(4);
        register_callbacks();
        return true;
    }
    void window::register_callbacks()
    {
        glfwSetWindowUserPointer(mwindow, &msettings);
        glfwSetWindowSizeCallback(mwindow, callbacks::window_resize);
        glfwSetKeyCallback(mwindow, callbacks::key);
        glfwSetCursorPosCallback(mwindow, callbacks::mouse_move);
        glfwSetMouseButtonCallback(mwindow, callbacks::mouse_button);
    }
    void window::update()
    {
        glfwPollEvents();
        glfwGetFramebufferSize(mwindow, (i32*)&msettings.width,  (i32*)&msettings.height);
        glfwSwapBuffers(mwindow);
    }
}}}
