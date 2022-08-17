#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // clear the window

    glColor3f(1, 0, 0);
    glutWireTeapot(0.25);

    glFlush(); // flush drawing routines to the window
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // can provide no arguments at all

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_RGB);

    // create and setup window
    glutCreateWindow("Hello world"); 
    glutDisplayFunc(display); // callback function

    // tell GLUT to wait for the events
    glutMainLoop();
}