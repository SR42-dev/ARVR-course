// not in working condition
#include <GL/glut.h>

// supports only three argument models
void spawnModel(float r, float g, float b, void (*model)(), float a, float b, float c)
{
    glColor3f(r, g, b);
    glPushMatrix();

        glTranslatef(0.5, 0, 0);
        (*model)(a, b, c);

    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // clear the window

    spawnModel(255, 0, 0, glutSolidCube, 1, 1, 1);

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