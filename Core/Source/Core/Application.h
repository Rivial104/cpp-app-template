#pragma once

#include "Layer.h"
#include "Window.h"

#include <glm/glm.hpp>

#include <string>
#include <vector>
#include <set>
#include <memory>
#include <type_traits>

namespace Core {

    struct ApplicationSpecification
    {
        std::string Name = "Application";
        WindowSpecs WindowSpec;
    };

    class Application
    {
        public:
            Application(const ApplicationSpecification& specs = ApplicationSpecification());
            ~Application();

            void Run();
            void Stop();

            template<typename TLayer>
            requires(std::is_base_of_v<Layer, TLayer>)
            void PushLayer()
            {
                m_LayerStack.push_back(std::make_unique<TLayer>());
            }

            glm::vec2 GetFramebufferSize() const;

            static Application& Get();
            static float GetTime();

        private:
            ApplicationSpecification m_Specification;
            std::shared_ptr<Window> m_Window;
            bool m_Running = false;

            std::vector<std::unique_ptr<Layer>> m_LayerStack;
    };

}