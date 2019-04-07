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
#include <TargetRenderer.h>
#include <RenderState.h>
#include <VertexBufferArray.h>
#include <Shader.h>
#include <GL/glew.h>
#include <RenderTarget.h>
#include <Texture.h>
#include <ext.hpp>
#include <glm.hpp>

void rrts::Graphics::TargetRenderer::draw(rrts::Graphics::RenderTarget &target)
{
	target.draw(target, *this);
}

void rrts::Graphics::TargetRenderer::draw(rrts::Graphics::VertexBufferArray &buffer, rrts::Graphics::IndexBuffer &index,
                                        rrts::Graphics::RenderState &state)
{
	buffer.bind();
	state.shaderInstance->bind();
	if (state.textureInstance != nullptr)
		state.textureInstance->bind();

	glDrawElements(GL_TRIANGLES, index.getCount(), GL_UNSIGNED_INT, 0);
}
