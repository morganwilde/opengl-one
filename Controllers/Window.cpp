#include "Window.h"
#include <iostream>

// Private

void Window::onDisplay()
{

}

// Public

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

    glutDisplayFunc(this->onDisplay);
/*
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
    attribute_coord2d = glGetAttribLocation(this->program, attribute_name);
    */
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
    attribute_coord2d = glGetAttribLocation(this->program, attribute_name);

    // The main loop
    glutMainLoop();
}