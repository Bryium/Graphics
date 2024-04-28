#include <GL/glut.h>
#include <cmath>

float position5 = 0.0f;

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(position5, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    float angle41;
    for (int i = 0; i < 360; i++)
    {
        angle41 = i * 3.1416 / 180;
        glVertex2f(0.8 + 0.04 * cos(angle41), 0.7 + 0.02 * sin(angle41));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    float angle42;
    for (int i = 0; i < 360; i++)
    {
        angle42 = i * 3.1416 / 180;
        glVertex2f(0.75 + 0.02 * cos(angle42), 0.71 + 0.02 * sin(angle42));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    float angle43;
    for (int i = 0; i < 360; i++)
    {
        angle43 = i * 3.1416 / 180;
        glVertex2f(0.74 + 0.005 * cos(angle43), 0.71 + 0.005 * sin(angle43));
    }
    glEnd();

    // Wing
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.8f, 0.75f);
    glVertex2f(0.79f, 0.71f);
    glVertex2f(0.785f, 0.8f);
    glEnd();

    // Lip
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0);
    glVertex2f(0.73f, 0.72f);
    glVertex2f(0.69f, 0.71f);
    glVertex2f(0.73f, 0.70f);
    glEnd();

    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Birds");
    glutDisplayFunc(display);
    glutMainLoop();

}
