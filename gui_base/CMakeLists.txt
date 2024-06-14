cmake_minimum_required(VERSION 3.20)

add_library(gui_base STATIC
    "include/gui_base/gui_base.hpp"
    "src/gui_base.cpp"
)

target_link_libraries(gui_base PRIVATE glfw)
target_link_libraries(gui_base PUBLIC dear_imgui glad)

if(GUI_BASE_INCLUDE_FILE_DIALOG)
    target_link_libraries(gui_base PUBLIC ImGuiFileDialog)
endif()

if(GUI_BASE_INCLUDE_PLOTTING)
    target_link_libraries(gui_base PUBLIC implot)
endif()

target_include_directories(gui_base PUBLIC "include")

target_compile_features(gui_base PRIVATE cxx_std_17)
set_target_properties(gui_base PROPERTIES CXX_EXTENSIONS OFF)

if(UNIX)
    target_compile_options(gui_base PRIVATE "-Wall" "-Wextra" "-Wpedantic" "-Wconversion")
elseif(MSVC)
    target_compile_options(gui_base PRIVATE "/W3")
else()
    message(WARNING "Warnings are not enabled")
endif()
