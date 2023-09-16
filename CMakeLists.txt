cmake_minimum_required(VERSION 3.20)

option(GUI_BASE_INCLUDE_FILE_DIALOG "Wether to include ImGuiFileDialog or not" OFF)

project("tiny-gui-base" LANGUAGES C CXX)

add_library(dear_imgui STATIC
    "extern/imgui/imgui.h"
    "extern/imgui/imgui.cpp"
    "extern/imgui/imgui_widgets.cpp"
    "extern/imgui/imgui_tables.cpp"
    "extern/imgui/imgui_draw.cpp"
    "extern/imgui/imgui_demo.cpp"
    "extern/imgui/imgui_internal.h"

    "extern/imgui/backends/imgui_impl_glfw.h"
    "extern/imgui/backends/imgui_impl_glfw.cpp"
    "extern/imgui/backends/imgui_impl_opengl3.h"
    "extern/imgui/backends/imgui_impl_opengl3.cpp"
)

target_include_directories(dear_imgui PUBLIC "extern/imgui")
target_include_directories(dear_imgui PRIVATE "extern/glfw/include")

add_library(glad STATIC "extern/glad/src/glad.c")
target_include_directories(glad PUBLIC "extern/glad/include")

add_subdirectory(extern/glfw)

if(GUI_BASE_INCLUDE_FILE_DIALOG)
    add_subdirectory(extern/ImGuiFileDialog)
    target_include_directories(ImGuiFileDialog PRIVATE "extern/imgui")
endif()

add_subdirectory(gui_base)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

message(STATUS "gui_base: Including file dialog: ${GUI_BASE_INCLUDE_FILE_DIALOG}")
