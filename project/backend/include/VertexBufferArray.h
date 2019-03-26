#ifndef RRTS_VERTEXBUFFERARRAY_H
#define RRTS_VERTEXBUFFERARRAY_H


namespace rrts
{
    namespace Graphics
    {
        enum AttribDataType
        {
                Float
        };

	class VertexBufferArray
	{
	public:
	    VertexBufferArray();
	    ~VertexBufferArray();

	    void bind();
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

	private:
	    unsigned int bufferID;
	    unsigned int currentAttributeIndex = 0;


	};
    }
}

#endif //RRTS_VERTEXBUFFERARRAY_H
