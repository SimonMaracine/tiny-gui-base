add_library(ImGuiFileDialog STATIC
    "extern/imgui_file_dialog/ImGuiFileDialog.cpp"
    "extern/imgui_file_dialog/ImGuiFileDialog.h"
    "extern/imgui_file_dialog/ImGuiFileDialogConfig.h"
)

target_include_directories(ImGuiFileDialog PUBLIC "extern/imgui_file_dialog")
target_include_directories(ImGuiFileDialog PRIVATE "extern/imgui")

if(UNIX)
    target_compile_options(ImGuiFileDialog PUBLIC "-Wno-unknown-pragmas")
endif()
