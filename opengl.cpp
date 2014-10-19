#include "opengl.h"
#include <iostream>
#include "VertexArray.h"

// Global variables
GLuint program;
GLint attribute_coord3d;

int init_resources(void)
{
    GLint compile_ok = GL_FALSE;
    GLint link_ok = GL_FALSE;

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);

    // Vertex shader
    const char *vs_source =
        "#version 120\n"
        "attribute vec3 coord3d;\n"
        "void main(void) {\n"
        "    gl_Position = vec4(coord3d, 1.0);\n"
        "}";
    // Fragment shader
    const char *fs_source =
        "#version 120\n"
        "void main(void) {\n"
        "    gl_FragColor[0] = 0.2;\n"
        "    gl_FragColor[1] = 0.5;\n"
        "    gl_FragColor[2] = 0.5;\n"
        "}";

    glShaderSource(vs, 1, &vs_source, NULL);
    glShaderSource(fs, 1, &fs_source, NULL);
    glCompileShader(vs);
    glCompileShader(fs);
    glGetShaderiv(vs, GL_COMPILE_STATUS, &compile_ok);
    glGetShaderiv(fs, GL_COMPILE_STATUS, &compile_ok);

    program = glCreateProgram();

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &link_ok);

    const char* attribute_name = "coord3d";
    attribute_coord3d = glGetAttribLocation(program, attribute_name);

    return 1;
}

void disp()
{
    /* Clear the background as white */
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
 
    glUseProgram(program);
    glEnableVertexAttribArray(attribute_coord3d);
    double a = 0.4;
    extern VertexArray vertices;
    GLfloat triangle_vertices[] = {
        -a,  a,
        a, a,
        a, -a,
        -a, -a,
        -a,  a,
        a, -a,
        -1.0, -1.0,
        -0.8, -1.0,
        -1.0, -0.8,
    };

    /* Describe our vertices array to OpenGL (it can't guess its format automatically) */
    glVertexAttribPointer(
        attribute_coord3d, // attribute
        3,                 // number of elements per vertex, here (x,y)
        GL_FLOAT,          // the type of each element
        GL_FALSE,          // take our values as-is
        0,                 // no extra data between each position
        //triangle_vertices  // pointer to the C array
        vertices.getArray()  // pointer to the C array
    );

    /* Push each element in buffer_vertices to the vertex shader */
    glDrawArrays(GL_TRIANGLES, 0, vertices.getSize());
    glDisableVertexAttribArray(attribute_coord3d);

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
