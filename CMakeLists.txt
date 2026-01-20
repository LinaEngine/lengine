cmake_minimum_required(VERSION 3.17)

project(lina)

find_package(Vulkan REQUIRED)
set(CMAKE_CXX_COMPILER g++)
set(GCCCompilerFlags "-std=c++23")
set(LDFLAGS "-ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi")
FILE(GLOB SRC
    "main.cc"
    "src/tests/core/*.cc"
    "src/tests/core/*.h"
    "src/core/*.h"
    "src/tests/*.h"
    )
add_executable(${PROJECT_NAME} ${SRC})
set(CMAKE_BUILD_TYPE Debug)

target_link_libraries(${PROJECT_NAME} GL dl glfw vulkan)

