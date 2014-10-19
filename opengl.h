#include <GLUT/glut.h>

#ifndef OPENGL_H
#define OPENGL_H

int init_resources(void);
void disp();
void free_resources();
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
void special(int key, int x, int y);
void mouse(int button, int state, int x, int y);
void move(int x, int y);

#endif
