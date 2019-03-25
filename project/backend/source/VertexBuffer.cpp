#include <VertexBuffer.h>
#include <GL/glew.h>

void rrts::Graphics::VertexBuffer::create(void * vertices)
{
	if(!bufferID)
		glGenBuffers(1, &bufferID);

	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void rrts::Graphics::VertexBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void rrts::Graphics::VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
}
