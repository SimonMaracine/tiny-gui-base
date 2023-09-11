# tiny-gui-base

It is a small library used to create GUI applications using GLFW and Dear ImGui. I built it for myself.

I tested it on `GCC 13` and `MSVC 19.36`. It requires `C++ 17`.

The easiest way to use this library is to include this repository as a submodule in your project with

```text
git submodule add <repository_link> <repository_path>
```

and then to use CMake like so:

```cmake
add_subdirectory(<path_to_submodule>)
target_link_libraries(<target> PRIVATE gui_base)
```
