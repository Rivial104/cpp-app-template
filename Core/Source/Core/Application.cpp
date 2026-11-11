#include "Application.h"

#include "Renderer/GLUtils.h"

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <assert>
#include <iostream>

namespace Core {

    static Application* s_Application = nullptr;

    static void GLFWErrorCallback(int error, const char* description)
    {
        std::cerr << "[GLFW Error]: " << description << std::endl;
    }

    Application::Application(const ApplicationSpecification& specification : m_Specification)
    {
        s_Application = this;

        glfwSetErrorCallback(GLFWErrorCallback);
        glfwInit();

        if (m_Specification.WindowSpec.Title.empty()) m_Specification.WindowSpec.Title = m_Specification.Name;

        m_Window = std::make_shared<Window>(m_Specification.WindowSpec);
        m_Window->Create();

        Renderer::Utils::InitOpenGLDebugMessageCallback();
    }

    Application::~Application()
    {
        m_Window->Destroy();

        glfwTerminate();

        s_Application = nullptr;
    }

    Application::Run()
    {
        m_Running = true;

        float lastTime = GetTime();

        // Main Application Loop
        while(m_Running)
        {

        }

    }

} // namespace Core
