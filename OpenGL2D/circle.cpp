#include <GL/glut.h>
#include <math.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // clear the window

    glBegin(GL_POINTS);

    glColor3f(1, 0, 0);
    float r = 50; float theta;
    for(int i = 0; i < 360; i++) 
    {
        theta = i * (M_PI / 180);
        glVertex2f((r * cos(theta)) + 250, (r * sin(theta)) + 250);
    }

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
    glPointSize(5);

    // tell GLUT to wait for the events
    glutMainLoop();
}