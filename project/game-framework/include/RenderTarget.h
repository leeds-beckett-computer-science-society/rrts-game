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
#ifndef RRTS_DRAWTARGET_H
#define RRTS_DRAWTARGET_H

#include <RenderState.h>
#include <VertexBufferArray.h>
#include <IndexBuffer.h>
#include <glm.hpp>
#include <Transformable.h>

namespace rrts
{
    namespace Graphics
    {
        class TargetRenderer;

        /**
	 * @author jack martin
	 */
        class RenderTarget : public Transformable, public RenderState
        {
        protected:

            /**
             * This should be overrided by the render target. When the renderer wants to render the target, it will call
             * back to this method which will handle the render data
             * @param target
             * @param renderer
             */
            virtual void draw(RenderTarget &target, TargetRenderer &renderer)=0;

            friend TargetRenderer;
        };
    }
}


#endif //RRTS_DRAWTARGET_H
