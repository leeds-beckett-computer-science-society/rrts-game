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
#ifndef RRTS_RENDERSTATE_H
#define RRTS_RENDERSTATE_H

#include <glm.hpp>

namespace rrts
{
    namespace Graphics
    {
        class Texture;
        class Shader;
        class TargetRenderer;
        class RenderTarget;

        /**
	 * @author jack martin
	 */
        class RenderState
        {
        public:
            RenderState();

            /**
             * sets the shader of the objects state
             * @param instance
             */
            void setShader(Shader* instance);

            /**
             * sets the texture of the objects state
             * @param instance
             */
            void setTexture(Texture* instance);

            Shader* getShader();
        private:

            // Ideally these should be const
            Shader* shaderInstance;
            Texture* textureInstance;

            glm::mat4 model;
            glm::mat4 projection;
            glm::mat4 view;

            friend TargetRenderer;
            friend RenderTarget;
        };

    }
}

#endif //RRTS_RENDERSTATE_H
