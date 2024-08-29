cmake_minimum_required(VERSION 3.20)

add_executable(test "src/main.cpp")

target_link_libraries(test PRIVATE gui_base)

target_compile_features(test PRIVATE cxx_std_17)
set_target_properties(test PROPERTIES CXX_EXTENSIONS OFF)

if(UNIX)
    target_compile_options(test PRIVATE "-Wall" "-Wextra" "-Wpedantic" "-Wconversion")
elseif(MSVC)
    target_compile_options(test PRIVATE "/W4")
else()
    message(WARNING "Warnings are not enabled")
endif()
