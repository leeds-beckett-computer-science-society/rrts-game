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
#include <IndexBuffer.h>
#include <GL/glew.h>

void rrts::Graphics::IndexBuffer::create(void *indices, unsigned int size)
{
	count = size / sizeof(unsigned int);
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void rrts::Graphics::IndexBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
}

void rrts::Graphics::IndexBuffer::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

rrts::Graphics::IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &bufferID);
}

unsigned int rrts::Graphics::IndexBuffer::getCount()
{
	return count;
}
