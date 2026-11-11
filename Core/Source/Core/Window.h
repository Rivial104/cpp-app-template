#pragma once

#include <glm/glm.hpp>

#include <cstdint>
#include <string>

struct GLFWwindow;

namespace Core {

    struct WindowSpecs
    {
        std::string Title;
        uint32_t Width = 1280;
        uint32_t Height = 720;
        bool isResizeable = true;
        bool VSync = true;
    };

    class Window
    {
        public:
            Window(const WindowSpecs& specs = WindowSpecs());
            ~Window();

            void Create();
            void Destroy();

            void Update();

            glm::vec2 GetFramebufferSize();

            bool ShouldClose() const;

            GLFWwindow* GetHandle() const { return m_Handle; }

        private:
            WindowSpecs m_specs;

            GLFWwindow* m_Handle = nullptr;
    };

}