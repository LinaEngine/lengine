#ifndef WINDOW_H
#define WINDOW_H
#include "../core/common.h"
namespace lina { namespace graphics { namespace backend { 
    class window 
    {
        public:
            struct window_settings
            {
                const char* name;
                f64 width;
                f64 height;
                b8 resizable = false;
                b8 resized = false;
            };
            window(window_settings& s);
            ~window();
            b8 create();
            void update();

            inline std::string get_name() {return std::string(msettings.name);};
            inline f32 get_width() {return msettings.width;}
            inline f32 get_height() {return msettings.height;}
            inline GLFWwindow* get_window() {return mwindow;}
            inline b8 is_resized() {return msettings.resized;};
            inline b8 is_closed() {return glfwWindowShouldClose(mwindow);};

            inline void set_resized(bool val) {msettings.resized = val;}
        private:
            b8 init();
            void register_callbacks();
        private:
            window_settings msettings;
            GLFWwindow* mwindow;

    };
}}}
#endif
