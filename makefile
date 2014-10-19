CC=g++
CFLAGS=-Wno-deprecated-declarations
LDFLAGS=-framework GLUT -framework OpenGL -framework Cocoa \
-I/usr/local/include -I/opt/X11/include -I/opt/X11/lib
PARTS=Controllers/Window.cpp opengl.cpp VertexArray.cpp

all: triangle.cpp $(PARTS)
	$(CC) $(CFLAGS) $(PARTS) triangle.cpp -o triangle $(LDFLAGS)
	./triangle