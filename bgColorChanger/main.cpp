#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

const unsigned int WINDOW_WIDTH = 400;
const unsigned int WINDOW_HEIGHT = 300;

// this is a callback for resize openGL rendering
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {
    // initialize libraries
    if (!glfwInit()) { printf("glfw init failed"); return -1; }

    // give hint to glfw window
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "My Window", NULL, NULL);
    if (window == NULL) { printf("window init failed"); return -1; }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // should GL loader calling by glad should be just before gl main loop
    if (!gladLoadGL()) { printf("glad load failed"); return -1; }
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) { printf("glad load GL loader failed"); return -1; }

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
