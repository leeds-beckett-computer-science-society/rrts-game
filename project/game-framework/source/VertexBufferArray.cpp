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
#include <VertexBufferArray.h>
#include <GL/glew.h>

rrts::Graphics::VertexBufferArray::VertexBufferArray()
{
	create();
}

rrts::Graphics::VertexBufferArray::~VertexBufferArray()
{
	glDeleteVertexArrays(1, &bufferID);
}

const void rrts::Graphics::VertexBufferArray::bind()
{
	glBindVertexArray(bufferID);
}

void rrts::Graphics::VertexBufferArray::unbind()
{
	glBindVertexArray(0);
}

void rrts::Graphics::VertexBufferArray::create()
{
	glGenVertexArrays(1, &bufferID);
	bind();
}

void
rrts::Graphics::VertexBufferArray::AddAttribute(rrts::Graphics::AttribDataType type, unsigned int width,
                                                void *offset, unsigned int vectorSize)
{
	switch (type) {
		case Float: {
			bind();
			glVertexAttribPointer(currentAttributeIndex, vectorSize, GL_FLOAT, GL_FALSE,
			                      width, offset);
			glEnableVertexAttribArray(currentAttributeIndex);
			unbind();
			currentAttributeIndex++;
		}
			break;
	}
}

void rrts::Graphics::VertexBufferArray::setIndexCount(unsigned int count)
{
	count = count;
}

bool rrts::Graphics::VertexBufferArray::Initialized()
{
	return (bufferID >= -1);
}
