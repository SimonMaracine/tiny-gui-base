cmake_minimum_required(VERSION 3.20)

project("tiny-gui-base" LANGUAGES C CXX)

set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Variable used to control the build type")

option(GUI_BASE_INCLUDE_FILE_DIALOG "Whether to include ImGuiFileDialog or not" OFF)
option(GUI_BASE_INCLUDE_PLOTTING "Whether to include implot or not" OFF)

include(cmake/dear_imgui.cmake)

if(GUI_BASE_INCLUDE_FILE_DIALOG)
    include(cmake/imgui_file_dialog.cmake)
endif()

if(GUI_BASE_INCLUDE_PLOTTING)
    include(cmake/implot.cmake)
endif()

include(cmake/glad.cmake)

add_subdirectory(extern/glfw)
add_subdirectory(gui_base)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

message(STATUS "gui_base: Including file dialog: ${GUI_BASE_INCLUDE_FILE_DIALOG}")
message(STATUS "gui_base: Including plotting: ${GUI_BASE_INCLUDE_PLOTTING}")
