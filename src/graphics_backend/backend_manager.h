#ifndef BACKEND_MANAGER_H
#define BACKEND_MANAGER_H
#include "../core/common.h"
#include "shader.h"
#include "window.h"
#include <vulkan/vulkan_core.h>
#include "backend_settings.h"
namespace lina { namespace graphics { namespace backend {
    class manager 
    {
        struct vk_physical_device 
        {
            VkPhysicalDeviceProperties properties;
            VkPhysicalDeviceMemoryProperties memory_properties;
        };
        struct vk_queues 
        {
            VkQueue present_queue;
            VkQueue graphics_queue;
        };
        struct vk_swap_chain_details
        {
            std::vector<VkPresentModeKHR> present_modes;
            std::vector<VkSurfaceFormatKHR> surface_formats;
            VkSurfaceCapabilitiesKHR capabilities;
            VkSurfaceFormatKHR chosen_format;
            VkPresentModeKHR chosen_present_mode;
        };
        struct vk_sync_object
        {
            VkSemaphore simage_available;
            VkSemaphore srender_finished;
            VkFence finflight;
        };
        struct vk_render_pass_data 
        {
            i32 subpass_count;
            
        };
        struct vk_image
        {
            VkImage img;
            VkImageView view;
            VkDeviceMemory memory;
        };
        public:
            manager() : mwindow(nullptr){}
            b8 init(window* win);
            inline b8 request_render_pass() {return false;};
            b8 create_default_graphics_pipeline();
            b8 create_shader(const shader& shader);
            void begin_draw();
            void bind(u32 idx = 0);
            void end_draw();
            b8 create_default_render_pass();
        private:
            b8 create_device();
            b8 create_vulkan_instance();
            b8 create_swap_chain();
            b8 create_sync_objects();
            b8 create_frame_buffers(u32 idx = 0);
            b8 create_command_structures();
            void clear_swap_chain();
            b8 recreate_swap_chain();
        private:
            window* mwindow;
            VkInstance mvkinstance;
            VkSurfaceKHR mvksurface;
            vk_physical_device mpd;
            vk_swap_chain_details mswap_details;
            vk_queues mqueues;
            VkDevice mvkdevice;
            i32 mvk_present_idx = -1;
            i32 mvk_graphics_idx = -1;
            std::vector<VkImage> mvk_swap_images;
            std::vector<VkImageView> mvk_swap_image_views;
            VkSwapchainKHR mvk_swapchain;
            vk_sync_object msync;
            std::vector<VkRenderPass> mvk_render_passes;
            std::vector<VkFramebuffer> mvk_frame_buffers;
            VkExtent2D mvk_extent;

            VkCommandBuffer mvk_command_buffer;
            VkCommandPool mvk_command_pool;
            std::vector<VkShaderModule> mvk_shader_modules;
            std::vector<VkPipelineLayout> mvk_pipeline_layout;
            std::vector<VkPipeline> mvk_pipeline;
            u32 mcurr_img_idx;
            u32 mcurr_render_pass;
            u32 mcurr_pipeline;
            std::vector<vk_image> mcol_images;
            std::vector<vk_image> mdepth_images;

    };
}}}
#endif
