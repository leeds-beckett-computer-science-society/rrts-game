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
#ifndef RRTS_VERTEX_H
#define RRTS_VERTEX_H

#include <glm.hpp>

namespace rrts
{
    namespace Graphics
    {
        /**
	 * @author jack martin
	 */
        class Vertex
        {
        public:
            glm::vec3 position;
            glm::vec3 colour;
            glm::vec2 texcoord;
        };
    }
}

#endif //RRTS_VERTEX_H
