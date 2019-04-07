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
#ifndef RRTS_VERTEXBUFFERARRAY_H
#define RRTS_VERTEXBUFFERARRAY_H


namespace rrts
{
    namespace Graphics
    {
        class TargetRenderer;

        enum AttribDataType
        {
                Float
        };

        /**
	 * @author jack martin
	 */
        class VertexBufferArray
	{
	public:
	    VertexBufferArray();
	    ~VertexBufferArray();

	    /**
	     * Binds the vertex buffer array
	     */
	    const void bind();

	    /**
	     * unbinds the vertex buffer array
	     */
	    static void unbind();

	    /**
	     * Initializes the vertex buffer srray
	     */
	    void create();

	    /**
	     * Adds a attribute to the vertex array. this requires shaders made to handle the data
	     * @param type
	     * @param width
	     * @param offset
	     * @param vectorSize
	     */
	    void AddAttribute(AttribDataType type, unsigned int width, void* offset, unsigned int vectorSize);

	    /**
	     * Sets the index count for when the index buffer is stored elsewhere but the count is needed for rendering
	     * @param count
	     */
	    void setIndexCount(unsigned int count);

	    /**
	     * If the vertex buffer array hasn't been initialized or it is not supported by the device, it will return false
	     * @return initialized
	     */
	    bool Initialized();

	private:
	    unsigned int bufferID = -1;
	    unsigned int currentAttributeIndex = 0;

	    unsigned int count = 0;
	    friend TargetRenderer;
	};
    }
}

#endif //RRTS_VERTEXBUFFERARRAY_H
