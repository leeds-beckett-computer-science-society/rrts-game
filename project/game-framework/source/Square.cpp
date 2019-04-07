/*
Copyright (C) 2019 Leeds Beckett Computer Science Society

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/
#include <Square.h>
#include <Vertex.h>
#include <glm.hpp>
#include <VertexBuffer.h>
#include <VertexBufferArray.h>
#include <IndexBuffer.h>
#include <Shader.h>
#include <TargetRenderer.h>

/* Texture coordinate layout
	0,1------------1,1
	 |              |
	 |              |
	 |              |
	 |              |
	0,0------------1,0
*/
rrts::Graphics::Vertex vertices[] = {
	glm::vec3(-0.5f, 0.5f, 0.f), glm::vec3(1.0f, 0.0f, 0.f), glm::vec2(0.0f, 0.f), //LEFT-DOWN
	glm::vec3(-0.5f, -0.5f, 0.f),glm::vec3(0.0f, 1.0f, 0.f), glm::vec2(0.0f, 1.f), //LEFT-UP
	glm::vec3(0.5f, -0.5f, 0.f), glm::vec3(0.0f, 0.0f, 1.f), glm::vec2(1.0f, 1.f), //RIGHT-UP
	glm::vec3(0.5f, 0.5f, 0.f),  glm::vec3(0.0f, 0.0f, 1.f), glm::vec2(1.0f, 0.f), //RIGHT-DOWN
};
unsigned int indices[] = {
	0, 1, 2,
	0, 2, 3
};

rrts::Graphics::Square::Square()
{
	this->setShader(new rrts::Graphics::Shader);
	this->getShader()->loadFromFile("shaders/es.vs", "shaders/es.fs");

	if (!vertexBufferArray.Initialized()) {
		vertexBufferArray.bind();
	}
	vertexBuffer.create(&vertices, sizeof(vertices));

	if (!vertexBufferArray.Initialized())
	{
		indexBuffer.create(indices, sizeof(indices));

		vertexBufferArray.AddAttribute(rrts::Graphics::AttribDataType::Float, sizeof(rrts::Graphics::Vertex),
		                               (void*)offsetof(rrts::Graphics::Vertex, position), 3);

		vertexBufferArray.AddAttribute(rrts::Graphics::AttribDataType::Float, sizeof(rrts::Graphics::Vertex),
		                               (void*)offsetof(rrts::Graphics::Vertex, colour), 3);

		vertexBufferArray.AddAttribute(rrts::Graphics::AttribDataType::Float, sizeof(rrts::Graphics::Vertex),
		                               (void*)offsetof(rrts::Graphics::Vertex, texcoord), 2);

		vertexBufferArray.setIndexCount(indexBuffer.getCount());

		rrts::Graphics::VertexBufferArray::unbind();
	}
}

void rrts::Graphics::Square::draw(rrts::Graphics::RenderTarget &target, rrts::Graphics::TargetRenderer &renderer)
{
	
	
	renderer.draw(vertexBufferArray, indexBuffer, *this);
}
