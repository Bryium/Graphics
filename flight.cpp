#include <GL/glut.h>
#include <math.h>

// Viewport dimensions
int windowWidth = 800;
int windowHeight = 600;

// Plane position variables
float planeX = 0.0;
float planeY = 0.0;

// Function to handle key press events
void handleKeypress(unsigned char key, int x, int y)
{
    // Move the plane based on key press
    switch (key)
    {
        case 'w': // Move up
            if (planeY < 0.9)
                planeY += 0.05;
            break;
        case 'a': // Move left
            if (planeX > -0.9)
                planeX -= 0.05;
            break;
        case 'd': // Move right
            if (planeX < 0.9)
                planeX += 0.05;
            break;
        case 's': // Move down
            if (planeY > -0.9)
                planeY -= 0.05;
            break;
    }

    glutPostRedisplay(); // Notify GLUT to redraw the scene
}

// Function to handle display rendering
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the plane
    glPushMatrix();
    glTranslatef(planeX, planeY, 0.0);

    // Airplane outer body
    glBegin(GL_POLYGON);
    glColor3ub(234, 229, 229); // white
    glVertex2f(-0.3f, 0.2f);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.4f, 0.3f);
    glVertex2f(0.45f, 0.4f);
    glVertex2f(0.45f, 0.5f);
    glVertex2f(0.3f, 0.4f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(-0.3f, 0.4f);
    glVertex2f(-0.35f, 0.38f);
    glVertex2f(-0.4f, 0.3f);
    glVertex2f(-0.35f, 0.23f);
    glVertex2f(-0.3f, 0.2f);
    glEnd();

    // Airplane front window
    glBegin(GL_POLYGON);
    glColor3ub(117, 69, 160); // purple one
    glVertex2f(-0.37f, 0.35f);
    glVertex2f(-0.32f, 0.35f);
    glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.3f, 0.38f);
    glVertex2f(-0.35f, 0.38f);
    glEnd();

    // Airplane front window lines
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255); // white
    glVertex2f(-0.35f, 0.35f);
    glVertex2f(-0.33f, 0.38f);
    glVertex2f(-0.33f, 0.35f);
    glVertex2f(-0.31f, 0.38f);
    glEnd();

    // Airplane front door
    glBegin(GL_LINES);
    glColor3ub(144, 126, 181); // purple one
    glVertex2f(-0.25f, 0.26f);
    glVertex2f(-0.23f, 0.24f);
    glVertex2f(-0.23f, 0.24f);
    glVertex2f(-0.18f, 0.24f);
    glVertex2f(-0.18f, 0.24f);
    glVertex2f(-0.16f, 0.26f);
    glVertex2f(-0.16f, 0.26f);
    glVertex2f(-0.16f, 0.36f);
    glVertex2f(-0.16f, 0.36f);
    glVertex2f(-0.18f, 0.38f);
    glVertex2f(-0.18f, 0.38f);
    glVertex2f(-0.23f, 0.38f);
    glVertex2f(-0.23f, 0.38f);
    glVertex2f(-0.25f, 0.36f);
    glVertex2f(-0.25f, 0.36f);
    glVertex2f(-0.25f, 0.26f);
    glEnd();

    // Airplane front wind
    glBegin(GL_QUADS);
    glColor3ub(117, 69, 160); // purple one
    glVertex2f(0.02f, 0.15f);
    glVertex2f(0.05f, 0.15f);
    glVertex2f(-0.03f, 0.26f);
    glVertex2f(-0.1f, 0.26f);
    glEnd();

    // Airplane back wind
    glBegin(GL_QUADS);
    glColor3ub(117, 69, 160); // purple one
    glVertex2f(-0.08f, 0.4f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.07f, 0.49f);
    glVertex2f(0.04f, 0.49f);
    glEnd();

    // Airplane window
    glColor3ub(117, 69, 160); // purple one
    GLfloat x2 = -0.09f;
    GLfloat y2 = 0.35f;
    GLfloat radius1 = .02f;
    int triangleAmount1 = 100;
    GLfloat twicePi1 = 2.0f * 3.14159;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2);
    for (int i = 0; i <= triangleAmount1; i++)
    {
        glVertex2f(
            x2 + (radius1 * cos(i * twicePi1 / triangleAmount1)),
            y2 + (radius1 * sin(i * twicePi1 / triangleAmount1))
        );
    }
    glEnd();

    glPopMatrix();

    glFlush();
}

// Function to handle window resizing
void reshape(int width, int height)
{
    windowWidth = width;
    windowHeight = height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Flight Simulator");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(handleKeypress);

    glClearColor(1.0, 1.0, 1.0, 1.0);

    glutMainLoop();

    return 0;
}
