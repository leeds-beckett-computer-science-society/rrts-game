#include <iostream>
#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

#define WinWidth 1280
#define WinHeight 720

float r, g, b = 0.0f;
GLFWwindow* window;

void frame()
{
    glfwPollEvents();

    if (r >= 1.0f)
        r = 0.1f;
    if (g >= 1.0f)
        g = 0.1f;
    if (b >= 1.0f)
        b = 0.1f;

    r += 0.001f;
    g += 0.005f;
    b += 0.003f;

    glViewport(0, 0, WinWidth, WinHeight);
    glClearColor(r,g,b, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
}

int main(int argc, char *argv[]) {
    if (!glfwInit())
    {
        // Initialization failed
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(640, 480, "Window", NULL, NULL);
    if (!window)
    {
        // Window or OpenGL context creation failed
    }
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    glewInit();

#ifdef EMSCRIPTEN
    emscripten_set_main_loop(frame, 60, true);
#else
    while (!glfwWindowShouldClose(window))
    {
        frame();
    }
#endif
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}