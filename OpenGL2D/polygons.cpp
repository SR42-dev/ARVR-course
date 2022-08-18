#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // clear the window

    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex2f(250, 250);
    glVertex2f(100,100);

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(0, 1, 0);
    glVertex2f(200, 490);
    glVertex2f(100,10);
    glVertex2f(100, 300);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0, 0, 1);
    glVertex2f(260, 260);
    glVertex2f(260,100);
    glVertex2f(360, 100);
    glVertex2f(360, 260);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1, 1, 1);
    glVertex2f(400, 400);
    glVertex2f(400, 440);
    glVertex2f(380, 480);
    glVertex2f(360, 440);
    glVertex2f(360, 400);
    glVertex2f(380, 360);

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