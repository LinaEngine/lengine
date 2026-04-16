cmake_minimum_required(VERSION 3.17)

project(lina)

find_package(Vulkan REQUIRED)
set(CMAKE_CXX_COMPILER g++)
set(GCCCompilerFlags "-std=c++23")
set(LDFLAGS "-ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi")
FILE(GLOB SRC
    "main.cc"
    "src/tests/core/*.cc"
    "src/tests/*.cc"
    "src/graphics/*.cc"
    "src/graphics_backend/*.cc"
    "src/ecs/components/*.cc"
    "src/ecs/components/colliders/*.cc"
    )

add_executable(${PROJECT_NAME} ${SRC})
set(CMAKE_BUILD_TYPE Debug)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} GL dl glfw vulkan)

