#pragma once

#include <stdexcept>

// Include this for the user
#include <imgui.h>

struct GLFWwindow;

namespace gui_base {
    struct WindowProperties {
        int width {1280};
        int height {720};
        int min_width {-1};
        int min_height {-1};
        const char* title {"tiny-gui-base"};
        bool resizable {true};
    };

    class GuiApplication {
    public:
        explicit GuiApplication(const WindowProperties& window_properties);
        virtual ~GuiApplication();

        int run();
    protected:
        virtual void start() = 0;
        virtual void update() = 0;
        virtual void stop() = 0;

        void quit() const;
        void set_title(const char* title) const;

        int exit_code {};
    private:
        void loop();
        void initialize(const WindowProperties& window_properties);
        void uninitialize() const;

        GLFWwindow* window {nullptr};
    };

    struct InitializationError : public std::runtime_error {
        explicit InitializationError(const char* message)
            : std::runtime_error(message) {}
    };

    inline constexpr unsigned int VERSION_MAJOR {0};
    inline constexpr unsigned int VERSION_MINOR {8};
    inline constexpr unsigned int VERSION_PATCH {0};
}
