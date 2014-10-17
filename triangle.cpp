// Standard c libs
#include <cstdio>
#include <cstdlib>
#include <iostream>
// Mac OpenGL libraries
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
// Controllers
#include "Controllers/Window.h"

// Global variables
GLuint program;
GLint attribute_coord2d;

int init_resources(void)
{
  GLint compile_ok = GL_FALSE, link_ok = GL_FALSE;
  GLuint vs = glCreateShader(GL_VERTEX_SHADER);
  const char *vs_source =
    "#version 120\n"
    "attribute vec2 coord2d;                  "
    "void main(void) {                        "
    "  gl_Position = vec4(coord2d, 0.0, 1.0); "
    "}";
    glShaderSource(vs, 1, &vs_source, NULL);
  glCompileShader(vs);
  glGetShaderiv(vs, GL_COMPILE_STATUS, &compile_ok);

  GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
  const char *fs_source =
    "#version 120           \n"
    "void main(void) {        "
    "  gl_FragColor[0] = 0.5; "
    "  gl_FragColor[1] = 0.5; "
    "  gl_FragColor[2] = 0.5; "
    "}";
  glShaderSource(fs, 1, &fs_source, NULL);
  glCompileShader(fs);
  glGetShaderiv(fs, GL_COMPILE_STATUS, &compile_ok);

program = glCreateProgram();
  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glGetProgramiv(program, GL_LINK_STATUS, &link_ok);

  const char* attribute_name = "coord2d";
  attribute_coord2d = glGetAttribLocation(program, attribute_name);

  return 1;
}
 
void onDisplay()
{
    /* clear the color buffer (resets everything to black) */
    glClear(GL_COLOR_BUFFER_BIT);
    
    /* set the current drawing color to red */
    glColor3f(1, 0, 0);
    
    /* start drawing triangles, each triangle takes 3 vertices */
    glBegin(GL_TRIANGLES);
    
    /* give the 3 triangle vertex coordinates 1 at a time */
    glVertex2f(10, 10);
    glVertex2f(250, 400);
    glVertex2f(400, 10);
    
    /* tell OpenGL we're done drawing triangles */
    glEnd();
    
    /* swap the back and front buffers so we can see what we just drew */
    glutSwapBuffers();
}

void disp()
{
  /* Clear the background as white */
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
 
  glUseProgram(program);
  glEnableVertexAttribArray(attribute_coord2d);
  double a = 0.4;
  GLfloat triangle_vertices[] = {
    -a,  a,
    a, a,
    a, -a,
    -a, -a,
    -a,  a,
    a, -a,
  };
  /* Describe our vertices array to OpenGL (it can't guess its format automatically) */
  glVertexAttribPointer(
    attribute_coord2d, // attribute
    2,                 // number of elements per vertex, here (x,y)
    GL_FLOAT,          // the type of each element
    GL_FALSE,          // take our values as-is
    0,                 // no extra data between each position
    triangle_vertices  // pointer to the C array
  );
 
  /* Push each element in buffer_vertices to the vertex shader */
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glDisableVertexAttribArray(attribute_coord2d);
 
  /* Display the result */
  glutSwapBuffers();
}
 
void free_resources()
{
  glDeleteProgram(program);
}

void reshape(int width, int height)
{
    /* tell OpenGL we want to display in a recangle that is the
     same size as the window
     */
    glViewport(0,0,width,height);
    
    /* switch to the projection matrix */
    glMatrixMode(GL_PROJECTION);
    
    /* clear the projection matrix */
    glLoadIdentity();
    
    /* set the camera view, orthographic projection in 2D */
    gluOrtho2D(0,width,0,height);
    
    /* switch back to the model view matrix */
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    std::cout << (int)key << " (" << x << ", " << y << ")" << std::endl;
    // Exit on escape
    if (key == 27) {
        exit(0);
    }
}

void special(int key, int x, int y)
{
    std::cout << "special " << (int)key << " (" << x << ", " << y << ")" << std::endl;
}

void mouse(int button, int state, int x, int y)
{
    std::cout << button << "[" << state << "]" << " (" << x << ", " << y << ")" << std::endl;
    glutPostRedisplay();
}

void move(int x, int y)
{
    std::cout << "move " << " (" << x << ", " << y << ")" << std::endl;
    glutPostRedisplay();
}
 
int main(int argc, char *argv[])
{
    
    /* Glut-related initialising functions */
    /*
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("My First Triangle");
    */

    Window window(&argc, argv, 100, 100);
    window.openDisplay();

    /*
    glutDisplayFunc(disp);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutMouseFunc(mouse);
    glutMotionFunc(move);
    glutPassiveMotionFunc(move);

//init_resources();

    glutMainLoop();
    */
//free_resources();
    return 0;
}