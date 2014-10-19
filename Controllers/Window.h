// Mac OpenGL libraries
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

class Window
{
private:
    // == Properties ===========================================================
    // Command line related
    int *argc;
    char **argv;
    // Operating system window
    int width;
    int height;
    char *title;
    // OpenGL related
    GLuint program;
    GLint attribute_coord2d;
    // == Methods ==============================================================
    // Object life-cycle
    Window(int *argc, char **argv, int width, int height);
    //Window(Window const &);
public:
    static Window &getSingleton(int *argc, char **argv, int width, int height);
    ~Window();
    Window &operator=(Window const &window);
    // Display window methods
    void openDisplay();
    // Callbacks
    void onDisplayy();
};