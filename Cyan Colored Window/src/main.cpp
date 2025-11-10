#include <GL/glut.h>
#include <cmath>

// Global variables
float t = 0.0f;         // Time variable for color transition
bool redOverride = false; // To check if ESC was pressed

// Function to display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    if (redOverride) {
        glColor3f(1.0f, 0.0f, 0.0f); // Red on ESC
    } else {
        // Cyan (0,1,1) to White (1,1,1) transition
        float factor = (sin(t) + 1.0f) / 2.0f;  // Range: 0 → 1
        float r = factor;   // Red increases with factor
        float g = 1.0f;     // Green stays max
        float b = 1.0f;     // Blue stays max
        glColor3f(r, g, b);
    }

    // Upside-down triangle at center
    glVertex2f(-0.5f, 0.5f);  // top-left
    glVertex2f(0.5f, 0.5f);   // top-right
    glVertex2f(0.0f, -0.5f);  // bottom-center (downward tip)

    glEnd();

    glutSwapBuffers();
}

// Timer function to update
void timer(int value) {
    if (!redOverride) {
        t += 0.05f;  // Update time
    }
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // ~60 FPS
}

// Keyboard function
void keyboard(unsigned char key, int x, int y) {
    if (key == 27) { // ESC key
        redOverride = true;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("ID: 202312345");  // <-- Replace with your ID

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
