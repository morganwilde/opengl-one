#include "VertexArray.h"
#include <cstdlib>

VertexArray::VertexArray()
{
    this->array = (GLfloat *)malloc(sizeof(GLfloat) * 0);
}

VertexArray::~VertexArray()
{
    free(this->array);
}

GLfloat *VertexArray::getArray()
{
    return this->array;
}

int VertexArray::getSize()
{
    return this->size;
}

void VertexArray::addPoint(GLfloat x, GLfloat y, GLfloat z)
{
    this->size += 3;
    this->array = (GLfloat *)realloc(this->array, sizeof(GLfloat) * this->size);
    // Set the coordinates
    this->array[this->size - 3] = x;
    this->array[this->size - 2] = y;
    this->array[this->size - 1] = z;
}
