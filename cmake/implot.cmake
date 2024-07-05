add_library(implot STATIC
    "extern/implot/implot_demo.cpp"
    "extern/implot/implot_internal.h"
    "extern/implot/implot_items.cpp"
    "extern/implot/implot.cpp"
    "extern/implot/implot.h"
)

target_include_directories(implot PUBLIC "extern/implot")
target_include_directories(implot PRIVATE "extern/imgui")
