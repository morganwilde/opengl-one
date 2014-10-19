#include "Window.h"
#include <iostream>

// Private

void onDisplay()
{
    Window window = Window::getSingleton(0, 0, 0, 0);
    window.onDisplayy();
}

void Window::onDisplayy()
{
    /* Clear the background as white */
    glClearColor(0.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(this->program);
    glEnableVertexAttribArray(this->attribute_coord2d);
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
    this->attribute_coord2d, // attribute
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

// Public

Window &Window::getSingleton(int *argc, char **argv, int width, int height)
{
    static Window singleton(argc, argv, width, height);
    return singleton;
}

Window &Window::operator=(Window const &window)
{
    return *this;
}

Window::Window(int *argc, char **argv, int width, int height)
{
    // Init the Window object
    this->argc = argc;
    this->argv = argv;
    this->width = width;
    this->height = height;

    glutInit(this->argc, this->argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(this->width, this->height);
    glutCreateWindow("My First Triangle");

    glutDisplayFunc(onDisplay);
}

Window::~Window()
{
    //glDeleteProgram(this->program);
}

void Window::openDisplay()
{
    // Error flags
    GLint compile_ok = GL_FALSE;
    GLint link_ok = GL_FALSE;

    // Shaders
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);

    // Shader source
    const char *vs_source =
        "#version 120\n"
        "attribute vec2 coord2d;\n"
        "void main(void) {"
        "gl_Position = vec4(coord2d, 0.0, 1.0);"
        "}";
    const char *fs_source =
        "#version 120\n"
        "void main(void) {"
        "gl_FragColor[0] = 0.5;"
        "gl_FragColor[1] = 0.5;"
        "gl_FragColor[2] = 0.5;"
        "}";

    glShaderSource(vs, 1, &vs_source, NULL);
    glCompileShader(vs);
    glGetShaderiv(vs, GL_COMPILE_STATUS, &compile_ok);
    
    glShaderSource(fs, 1, &fs_source, NULL);
    glCompileShader(fs);
    glGetShaderiv(fs, GL_COMPILE_STATUS, &compile_ok);

    this->program = glCreateProgram();
    glAttachShader(this->program, vs);
    glAttachShader(this->program, fs);
    glLinkProgram(this->program);
    glGetProgramiv(this->program, GL_LINK_STATUS, &link_ok);

    const char *attribute_name = "coord2d";
    this->attribute_coord2d = glGetAttribLocation(this->program, attribute_name);

    // The main loop
    glutMainLoop();
}