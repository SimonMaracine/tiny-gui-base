#include "gui_base/gui_base.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

namespace gui_base {
    GuiApplication::GuiApplication(const WindowProperties& window_properties) {
        initialize(window_properties);
    }

    GuiApplication::~GuiApplication() {
        uninitialize();
    }

    int GuiApplication::run() {
        start();
        loop();
        stop();

        return exit_code;
    }

    void GuiApplication::quit() const {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    void GuiApplication::set_title(const char* title) const {
        glfwSetWindowTitle(window, title);
    }

    void GuiApplication::loop() {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            update();

            ImGui::Render();

            int display_w, display_h;
            glfwGetFramebufferSize(window, &display_w, &display_h);

            glViewport(0, 0, display_w, display_h);
            glClear(GL_COLOR_BUFFER_BIT);

            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(window);
        }
    }

    void GuiApplication::initialize(const WindowProperties& window_properties) {
        if (!glfwInit()) {
            throw InitializationError("Could not initialize GLFW");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
        glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
        glfwWindowHint(GLFW_RESIZABLE, window_properties.resizable ? GLFW_TRUE : GLFW_FALSE);

        window = glfwCreateWindow(
            window_properties.width,
            window_properties.height,
            window_properties.title,
            nullptr,
            nullptr
        );

        if (window == nullptr) {
            glfwTerminate();
            throw InitializationError("Could not create window");
        }

        glfwSetWindowSizeLimits(
            window,
            window_properties.min_width < 0 ? GLFW_DONT_CARE : window_properties.min_width,
            window_properties.min_height < 0 ? GLFW_DONT_CARE : window_properties.min_height,
            GLFW_DONT_CARE,
            GLFW_DONT_CARE
        );

        glfwMakeContextCurrent(window);

        if (!gladLoadGL()) {
            glfwTerminate();
            throw InitializationError("Could not initialize GLAD");
        }

        glfwSwapInterval(1);

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 430 core");
    }

    void GuiApplication::uninitialize() const {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(window);
        glfwTerminate();
    }
}
