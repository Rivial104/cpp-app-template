#include "AppLayer.h"

#include "Core/Application.h"

#include "Core/Renderer/Renderer.h"
#include "Core/Renderer/Shader.h"

#include <glm/glm.hpp>

AppLayer::AppLayer()
{
    m_Shader = Renderer::CreateGraphicsShader(APP_SHADER_DIR "Vertex.glsl", APP_SHADER_DIR "Fragment.glsl");

    glCreateVertexArrays(1, &m_VertexArray);
    glCreateBuffers(1, &m_VertexBuffer);

    struct Vertex
    {
        glm::vec2 Position;
        glm::vec3 Color;
    };

    // Triangle (red)
    Vertex vertices[] = {
        {{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}}, // bottom left
        {{ 0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}}, // bottom right
        {{ 0.0f,  0.5f}, {1.0f, 0.0f, 0.0f}}, // top 
    };

    glNamedBufferData(m_VertexBuffer, sizeof(vertices), vertices, GL_STATIC_DRAW); // GL_DYNAMIC_DRAW

    // Bind the VBO to VAO at binding index 0
	glVertexArrayVertexBuffer(m_VertexArray, 0, m_VertexBuffer, 0, sizeof(Vertex));

    glEnableVertexArrayAttrib(m_VertexArray, 0); // position
	glEnableVertexArrayAttrib(m_VertexArray, 1); // color

    // Format: location, size, type, normalized, relative offset
	glVertexArrayAttribFormat(m_VertexArray, 0, 2, GL_FLOAT, GL_FALSE, static_cast<GLuint>(offsetof(Vertex, Position)));
	glVertexArrayAttribFormat(m_VertexArray, 1, 3, GL_FLOAT, GL_FALSE, static_cast<GLuint>(offsetof(Vertex, Color)));

	// Link attribute locations to binding index 0
	glVertexArrayAttribBinding(m_VertexArray, 0, 0);
	glVertexArrayAttribBinding(m_VertexArray, 1, 0);
}

AppLayer::~AppLayer()
{
	glDeleteVertexArrays(1, &m_VertexArray);
	glDeleteBuffers(1, &m_VertexBuffer);

	glDeleteProgram(m_Shader);
}

void AppLayer::OnUpdate(float ts)
{
}

void AppLayer::OnRender()
{
	glm::vec2 framebufferSize = Core::Application::Get().GetFramebufferSize();

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glViewport(0, 0, static_cast<GLsizei>(framebufferSize.x), static_cast<GLsizei>(framebufferSize.y));

	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Triangle
	glUseProgram(m_Shader);
	glBindVertexArray(m_VertexArray);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}