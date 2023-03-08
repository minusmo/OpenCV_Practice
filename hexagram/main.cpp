#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "OpenGL/gl.h"

#define ORIGIN 0.0f
#define POINTS 3
#define EDGE_SIZE 1.0f
const float vertices[POINTS][2] = {
        {-EDGE_SIZE/2, -EDGE_SIZE/2},
        {EDGE_SIZE/2, -EDGE_SIZE/2},
        {ORIGIN, EDGE_SIZE/2}
};

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(640, 480, "Hexagram", NULL, NULL);

    if (!window) { glfwTerminate(); return -1; }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) { glfwTerminate(); return -1; }

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);

        for (auto point : vertices) {
            glVertex2f(point[0], point[1]);
        }
        for (auto point : vertices) {
            glVertex2f(point[0], -point[1] - EDGE_SIZE/4);
        }
        glEnd();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
