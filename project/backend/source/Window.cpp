#include <Window.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

rrts::Graphics::Window::Window(int width, int height)
{
	createWindow(width, height);
}

rrts::Graphics::Window::Window(int width, int height, std::function<void()> callback)
{
	createWindow(width, height);
	setFrameCallBack(std::move(callback));
}

rrts::Graphics::Window::~Window()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void rrts::Graphics::Window::swapBuffer()
{
	glfwSwapBuffers(window);
}

void rrts::Graphics::Window::pollEvents()
{
	glfwPollEvents();
}

void rrts::Graphics::Window::WhileRunning(std::function<void()> callback)
{
	setFrameCallBack(std::move(callback));

#ifdef EMSCRIPTEN
	emscripten_set_main_loop_arg(rrts::Graphics::frame, this, 60, true);
#else
	while (!glfwWindowShouldClose(window)) {
		frameCallback();
	}
#endif
}

void rrts::Graphics::Window::createWindow(int width, int height)
{
	if (!glfwInit()) {
		// Initialization failed
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	window = glfwCreateWindow(width, height, "Window", nullptr, nullptr);
	if (!window) {
		// Window or OpenGL context creation failed
	}
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();
}

void rrts::Graphics::Window::runFrame()
{
	frameCallback();
}

void rrts::Graphics::Window::setFrameCallBack(std::function<void()> callback)
{
	frameCallback = std::move(callback);
}
