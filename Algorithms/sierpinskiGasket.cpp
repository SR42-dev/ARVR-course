/*

sierpinski gasket :

- a shape with a long history in fractal geometry

- sierpinski gasket is an object that can be defined recursively and randomly in 
the limit without all random properties

#### basic algorithm ####

1. pick an initial point p at random inside a triangle
2. select one of the three vertices at random 
3. find the point q halfway between p and the randomly selected vertex
4. display q on the screen as a point
5. replace p with q
6 return to step 2

########

#### pseudocode #### 

main()
{
    initializeTheSystem()
    p = findInitialPoint()

    for (someNumberOfPoints)
    {
        q = generateAPoint(p)
        displayThePoint()
        p = q
    }

    cleanup()
}

########

#### code (draft1, failed attempt) ####

#include <GL/glut.h>
#include <math.h>
#include <cstdio>

float area(float x1, float y1, float x2, float y2, float x3, float y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

bool isInside(float x1, float y1, float x2, float y2, float x3, float y3, float x, float y)
{  
   float A = area (x1, y1, x2, y2, x3, y3);
   float A1 = area (x, y, x2, y2, x3, y3);
   float A2 = area (x1, y1, x, y, x3, y3);
   float A3 = area (x1, y1, x2, y2, x, y);
   return (A == A1 + A2 + A3);
}

void spawnSierpinski(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float pX, pY, qX, qY;
    float verticesX[] = {x1, x2, x3};
    float verticesY[] = {y1, y2, y3};

    int vert;
    float vertX, vertY;


    glClear(GL_COLOR_BUFFER_BIT); // clear the window
    glVertex2d(0, 0);
    glColor3f(1, 1, 1);

    // taking initial arbitrary point inside triangle 
    pX = 30; 
    pY = 25;

    glBegin(GL_POINTS);
    for (int i = 0; i < 100000000000; i++) 
    {
        vert = (rand() % 3);
        vertX = verticesX[vert];
        vertY = verticesY[vert];
        
        qX = (vertX + pX) / 2;
        qY = (vertY + pY) / 2;

        glVertex2f(qX, qY);

        pX = qX;
        pY = qY;
        
    }
    glEnd();  
}

void display()
{

    float x1 = 20;
    float y1 = 20;
    float x2 = 40;
    float y2 = 40;
    float x3 = 40;
    float y3 = 20;

    spawnSierpinski(x1, y1, x2, y2, x3, y3);
    glFlush(); // flush drawing routines to the window
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // can provide no arguments at all

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

    // create and setup window
    glutCreateWindow("3D"); 
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display); // callback function

    // set up projection window
    glMatrixMode(GL_PROJECTION); // selecting projection matrix
    glLoadIdentity();
    gluOrtho2D(0, 500, 500, 0); // 
    glPointSize(5);

    // tell GLUT to wait for the events
    glutMainLoop();
}

########

#### code (draft2, successful attempt) ####

#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
static void display(void)
{
    GLint vx[] = {100, 0, 200};
    GLint vy[] = {0, 200, 200};
    GLint px = 100;
    GLint py = 100;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);

        for (GLint i = 0; i < 10000; i++) 
        {
            int whichV = rand() % 3;
            int newPx = (px + vx[whichV]) / 2;
            int newPy = (py + vy[whichV]) / 2;
            glVertex2i(newPx, newPy);
            px = newPx;
            py = newPy;
        }

    glEnd();
    glFlush();
}

void init() 
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 500, 500, 0);
}

int main(int argc, char *argv[]) 
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Gasket")
    glutDisplayFunc(display)
    init();
    glutMainLoop();
    return 0;
}

########

*/

#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

void display()
{
    int vx[] = {100, 0, 200};
    int vy[] = {0, 200, 200};
    int px = 100;
    int py = 100;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);

        for (int i = 0; i < INT16_MAX; i++) 
        {
            int whichV = rand() % 3;
            int newPx = (px + vx[whichV]) / 2;
            int newPy = (py + vy[whichV]) / 2;
            glVertex2i(newPx, newPy);
            px = newPx;
            py = newPy;
        }

    glEnd();
    glFlush();
}

int main(int argc, char *argv[]) 
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Gasket");
    glutDisplayFunc(display);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(0, 210, 210, 0);
    glutMainLoop();
    return 0;
}


