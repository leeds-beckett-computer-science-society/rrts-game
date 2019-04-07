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
#ifndef RRTS_VERTEXBUFFER_H
#define RRTS_VERTEXBUFFER_H

#include <Vertex.h>

namespace rrts
{
    namespace Graphics
    {
	enum DrawType
	{
	    Static, Dynamic, Stream
	};

        /**
	 * @author jack martin
	 */
        class VertexBuffer
	{
	public:
	    ~VertexBuffer();

	    /**
	     * Creates the vertex buffer using the vertices and the size of the array
	     * @param vertices
	     * @param size
	     */
	    void create(void *vertices, unsigned int size);
	private:

	    /**
	     * Binds the vertex buffer
	     */
	    void bind() const;

	    /**
	     * Unbinds all vertex buffers
	     */
	    static void unbind();


	private:
	    unsigned int bufferID;
	    int size;
	    DrawType type;
	};
    }
}

#endif //RRTS_VERTEXBUFFER_H
