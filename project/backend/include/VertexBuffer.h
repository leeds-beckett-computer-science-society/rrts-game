#ifndef RRTS_VERTEXBUFFER_H
#define RRTS_VERTEXBUFFER_H

#include <Vertex.h>

namespace rrts::Graphics
{
    enum DrawType
    {
        Static, Dynamic, Stream
    };

    class VertexBuffer
    {
    public:

    private:
        void bind();

        void create();
    private:
        unsigned int bufferID;
        int size;
        DrawType type;
    };
}

#endif //RRTS_VERTEXBUFFER_H
