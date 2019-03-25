#ifndef RRTS_INDEXBUFFER_H
#define RRTS_INDEXBUFFER_H


class IndexBuffer
{
    public:

    private:
	void bind() const;
	void unbind() const;

	void create(void * indices, unsigned int count);
    private:
	unsigned int bufferID;
	int size;
};


#endif //RRTS_INDEXBUFFER_H
