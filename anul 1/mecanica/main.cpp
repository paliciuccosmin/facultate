#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void drawArchimedesSpiral(float k)
{
    glBegin(GL_LINE_STRIP);
    for (float o = 0; o < 6 * M_PI; o += 0.1f)
    {
        float x = k * o * cos(o);
        float y = k * o * sin(o);
        glVertex3f(x, y, 0);
    }
    glEnd();
}

void render(GLFWwindow* window)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);

    glColor3f(1, 0, 0);
    drawArchimedesSpiral(0.1f);

    glfwSwapBuffers(window);
}

int main()
{
    GLFWwindow* window;

    if (!glfwInit())
    {
        return -1;
    }

    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Archimedes Spiral", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "GLEW initialization failed!" << std::endl;
        return -1;
    }

    while (!glfwWindowShouldClose(window))
    {
        render(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
