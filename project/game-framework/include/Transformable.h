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
#ifndef RRTS_TRANSFORMABLE_H
#define RRTS_TRANSFORMABLE_H

#include <glm.hpp>

namespace rrts
{
    namespace Graphics
    {
        /**
	 * @author jack martin
	 */
        class Transformable
	{
	public:
	    Transformable();

	    void rotate(float by);
	    void scale(float by);
	    void setSize(int width, int height);
	    void setPosition(int x, int y);

	protected:

	    glm::mat4 model{};

	    glm::vec2 size{};
	    glm::vec2 position{};
	    float rotation{};
	};
    }
}

#endif //RRTS_TRANSFORMABLE_H
