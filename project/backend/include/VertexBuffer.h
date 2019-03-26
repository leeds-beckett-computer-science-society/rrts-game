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

	class VertexBuffer
	{
	public:
	    ~VertexBuffer();
	    void create(void *vertices, unsigned int size);
	private:
	    void bind() const;

	    void unbind() const;


	private:
	    unsigned int bufferID;
	    int size;
	    DrawType type;
	};
    }
}

#endif //RRTS_VERTEXBUFFER_H
