#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // clear the window

    glBegin(GL_POINTS);

    glColor3f(1, 0, 0);
    for(int i = 0; i < 250; i++) glVertex2f(i, i);

    glColor3f(0, 1, 0);
    for(int i = 250; i < 500; i++) glVertex2f(i, (500 - i));

    glColor3f(0, 0, 1);
    for(int i = 500; i > 0; i--) glVertex2f(i, 5);

    glEnd();

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

    // set up projection window
    glMatrixMode(GL_PROJECTION); // selecting projection matrix
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
    glPointSize(10);

    // tell GLUT to wait for the events
    glutMainLoop();
}