#include <GLUT/glut.h>

#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

class VertexArray
{
private:
    GLfloat *array;
    int size;
public:
    VertexArray();
    ~VertexArray();
    GLfloat *getArray();
    int getSize();
    void addPoint(GLfloat x, GLfloat y, GLfloat z);
};

#endif
