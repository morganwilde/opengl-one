CC=g++
CFLAGS=-Wno-deprecated-declarations
LDFLAGS=-framework GLUT -framework OpenGL -framework Cocoa \
-I/usr/local/include -I/opt/X11/include -L/usr/local/lib -I/opt/X11/lib
PARTS=Controllers/Window.cpp

all: triangle.cpp $(PARTS)
	$(CC) $(CFLAGS) Controllers/Window.cpp triangle.cpp -o triangle $(LDFLAGS)
	./triangle