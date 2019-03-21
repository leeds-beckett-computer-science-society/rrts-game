#include <VertexBuffer.h>
#include <GL/glew.h>

void rrts::Graphics::VertexBuffer::create()
{
	if(!bufferID)
		glGenBuffers(1, &bufferID);

	glBindBuffer(GL_ARRAY_BUFFER, bufferID);

}

void rrts::Graphics::VertexBuffer::bind()
{

}
