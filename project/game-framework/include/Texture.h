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
#ifndef RRTS_TEXTURE_H
#define RRTS_TEXTURE_H

#include <iostream>
#include <vec2.hpp>

namespace rrts
{
    namespace Graphics
    {

        /**
	 * @author jack martin
	 */
        class Texture
        {
        public:
            Texture();
            ~Texture();
            void loadFromFile(std::string path);

            void bind() const;
            static void unbind();

            glm::vec2 getSize();
        private:
            unsigned int id;
            unsigned int width;
            unsigned int height;
        };
    }
}
#endif //RRTS_TEXTURE_H
