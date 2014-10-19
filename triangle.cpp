// Standard c libs
#include <cstdio>
#include <cstdlib>
#include <iostream>
// Mac OpenGL libraries
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

#include "VertexArray.h"

VertexArray vertices;

#include "opengl.h"

 
int main(int argc, char *argv[])
{
    // Glut-related initialising functions
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("My First Triangle");

    glutDisplayFunc(disp);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutMouseFunc(mouse);
    glutMotionFunc(move);
    glutPassiveMotionFunc(move);

    init_resources();

    vertices.addPoint(1.0, 1.0, 0.0);
    vertices.addPoint(0.0, 1.0, 0.0);
    vertices.addPoint(1.0, -1.0, 0.0);

    vertices.addPoint(-1.0, -1.0, 0.0);
    vertices.addPoint(0.0, -1.0, 0.0);
    vertices.addPoint(-1.0, 1.0, 0.0);

    glutMainLoop();

    free_resources();

    return 0;
}
