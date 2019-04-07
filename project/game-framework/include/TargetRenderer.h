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
#ifndef RRTS_RENDERTARGET_H
#define RRTS_RENDERTARGET_H

#include <glm.hpp>
#include <IndexBuffer.h>

namespace rrts
{
    namespace Graphics
    {
        class RenderState;
        class RenderTarget;
        class VertexBufferArray;

        /**
	 * @author jack martin
	 */
        class TargetRenderer
	{
	public:

	    /**
	     * Renders a VertexBufferArray using a IndexBuffer and a RenderState
	     * @param buffer
	     * @param index
	     * @param state
	     * @warning if the session reports that VertexBufferArrays aren't supported, this should never be called
	     */
	    static void draw(VertexBufferArray &buffer, IndexBuffer &index, RenderState &state);


	    void draw(RenderTarget &target);
	};
    }
}

#endif //RRTS_RENDERTARGET_H

