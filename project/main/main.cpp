#include <iostream>
#include <Window.h>
#include <Shader.h>
#include <Vertex.h>
#include <vec3.hpp>
#include <GL/glew.h>
#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

rrts::Graphics::Vertex vertices[] = {
	glm::vec3(-0.5f, 0.5f, 0.f), glm::vec3(1.0f, 0.0f, 0.f),  glm::vec2(0.0f, 1.f),
	glm::vec3(-0.5f, -0.5f, 0.f), glm::vec3(0.0f, 1.0f, 0.f),glm::vec2(0.0f, 0.f),
	glm::vec3(0.5f, -0.5f, 0.f), glm::vec3(0.0f, 0.0f, 1.f), glm::vec2(1.0f, 0.f),
	glm::vec3(0.5f, 0.5f, 0.f), glm::vec3(0.0f, 0.0f, 1.f), glm::vec2(1.0f, 0.f),
};
unsigned int vert_size = sizeof(vertices) / sizeof(rrts::Graphics::Vertex);
unsigned int indices[] = {
	0, 1, 2,
	0, 2, 3
};

unsigned int in_size = sizeof(indices) / sizeof(unsigned int);

int main(int argc, char *argv[])
{
	float r = 0.0f, g = 0.0f, b = 0.0f;
	rrts::Graphics::Window window(1280, 720);

	rrts::Graphics::Shader shader;
	shader.loadFromFile("shaders/vertex.glsl", "shaders/fragment.glsl", "");

	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
		sizeof(rrts::Graphics::Vertex), (void*)offsetof(rrts::Graphics::Vertex, position));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
	                      sizeof(rrts::Graphics::Vertex), (void*)offsetof(rrts::Graphics::Vertex, colour));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
	                      sizeof(rrts::Graphics::Vertex), (void*)offsetof(rrts::Graphics::Vertex, texcoord));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	window.WhileRunning([&](){
		window.pollEvents();

		window.clear();

		shader.bind();
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, in_size, GL_UNSIGNED_INT, 0);

		window.swapBuffer();
		glFlush();
	});

	return 0;
}