#ifndef BACKEND_SETTINGS_H
#define BACKEND_SETTINGS_H
#include "../core/common.h"
namespace lina { namespace graphics { namespace backend {
    inline const std::vector<const char*> grequired_extensions = 
    {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };
    inline const std::vector<const char*> enabled_layers = 
    {
        "VK_LAYER_KHRONOS_validation"
    };
}}}
#endif
