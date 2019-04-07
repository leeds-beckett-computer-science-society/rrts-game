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
#include <VertexBuffer.h>
#include <GL/glew.h>

void rrts::Graphics::VertexBuffer::create(void * vertices, unsigned int size)
{
	this->size = size;

	if(!bufferID)
		glGenBuffers(1, &bufferID);

	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void rrts::Graphics::VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
}

rrts::Graphics::VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(GL_ARRAY_BUFFER, &bufferID);
}

void rrts::Graphics::VertexBuffer::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
