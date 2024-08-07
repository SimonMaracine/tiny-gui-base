add_library(dear_imgui STATIC
    "extern/imgui/backends/imgui_impl_glfw.cpp"
    "extern/imgui/backends/imgui_impl_glfw.h"
    "extern/imgui/backends/imgui_impl_opengl3_loader.h"
    "extern/imgui/backends/imgui_impl_opengl3.cpp"
    "extern/imgui/backends/imgui_impl_opengl3.h"
    "extern/imgui/imconfig.h"
    "extern/imgui/imgui_demo.cpp"
    "extern/imgui/imgui_draw.cpp"
    "extern/imgui/imgui_internal.h"
    "extern/imgui/imgui_tables.cpp"
    "extern/imgui/imgui_widgets.cpp"
    "extern/imgui/imgui.cpp"
    "extern/imgui/imgui.h"
    "extern/imgui/imstb_rectpack.h"
    "extern/imgui/imstb_textedit.h"
    "extern/imgui/imstb_truetype.h"
)

target_include_directories(dear_imgui PUBLIC "extern/imgui")
target_include_directories(dear_imgui PRIVATE "extern/glfw/include")

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(dear_imgui PRIVATE "NDEBUG")
endif()
