#include <iostream>

#include <gui_base/gui_base.hpp>

struct TestApplication : gui_base::GuiApplication {
    explicit TestApplication(const gui_base::WindowProperties& properties)
        : gui_base::GuiApplication(properties) {}

    void start() override {

    }

    void stop() override {

    }

    void update() override {
        ImGui::ShowDemoWindow();
    }
};

int main() {
    try {
        TestApplication application {gui_base::WindowProperties()};
        return application.run();
    } catch (const gui_base::InitializationError& e) {
        std::cerr << e.what() << '\n';
    }
}
