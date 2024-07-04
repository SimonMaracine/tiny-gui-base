cmake_minimum_required(VERSION 3.20)

project("tiny-gui-base" LANGUAGES C CXX)

set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Variable used to control the build type")

option(GUI_BASE_INCLUDE_FILE_DIALOG "Whether to include ImGuiFileDialog or not" OFF)
option(GUI_BASE_INCLUDE_PLOTTING "Whether to include implot or not" OFF)

# Dear ImGui
add_library(dear_imgui STATIC
    "extern/imgui/imgui_demo.cpp"
    "extern/imgui/imgui_draw.cpp"
    "extern/imgui/imgui_tables.cpp"
    "extern/imgui/imgui_widgets.cpp"
    "extern/imgui/imgui.cpp"
    "extern/imgui/imgui.h"
    "extern/imgui/imgui_internal.h"

    "extern/imgui/backends/imgui_impl_glfw.cpp"
    "extern/imgui/backends/imgui_impl_opengl3.cpp"
    "extern/imgui/backends/imgui_impl_glfw.h"
    "extern/imgui/backends/imgui_impl_opengl3.h"
)

target_include_directories(dear_imgui PUBLIC "extern/imgui")
target_include_directories(dear_imgui PRIVATE "extern/glfw/include")

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(dear_imgui PRIVATE "NDEBUG")
endif()

# Optional ImGuiFileDialog
if(GUI_BASE_INCLUDE_FILE_DIALOG)
    add_subdirectory(extern/ImGuiFileDialog)
    target_include_directories(ImGuiFileDialog PRIVATE "extern/imgui")
endif()

# Optional implot
if(GUI_BASE_INCLUDE_PLOTTING)
    add_library(implot STATIC
        "extern/implot/implot_demo.cpp"
        "extern/implot/implot_internal.h"
        "extern/implot/implot_items.cpp"
        "extern/implot/implot.cpp"
        "extern/implot/implot.h"
    )
    target_include_directories(implot PUBLIC "extern/implot" "extern/imgui")
endif()

# glad
add_library(glad STATIC "extern/glad/src/glad.c")
target_include_directories(glad PUBLIC "extern/glad/include")

add_subdirectory(extern/glfw)
add_subdirectory(gui_base)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

message(STATUS "gui_base: Including file dialog: ${GUI_BASE_INCLUDE_FILE_DIALOG}")
message(STATUS "gui_base: Including plotting: ${GUI_BASE_INCLUDE_PLOTTING}")
