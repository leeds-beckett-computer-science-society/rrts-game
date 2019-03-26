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

	    void create();

	    void AddAttribute(AttribDataType type, unsigned int width, void* offset, unsigned int vectorSize);

	private:
	    unsigned int bufferID;
	    unsigned int currentAttributeIndex = 0;


	};
    }
}

#endif //RRTS_VERTEXBUFFERARRAY_H
