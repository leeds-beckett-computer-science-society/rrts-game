/*
Copyright (C) 2019 Leeds Beckett Computer Science Society

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/
#include <Window.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <Session.h>
#include <RenderTarget.h>
#include <Logger.h>
#include <sstream>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

rrts::Graphics::Window::Window(int width, int height) : TargetRenderer()
{
	createWindow(width, height);
	rrts::User::Session::getInstance()->setWindow(*this);
}

rrts::Graphics::Window::Window(int width, int height, std::function<void()> callback) : TargetRenderer()
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
	glFlush();

	rrts::User::Logger::flush();

	double currentTime = glfwGetTime();
	frameCount++;

	if ( currentTime - previousTime >= 1.0 )
	{
		rrts::User::Session::getInstance()->setFPS(frameCount);
		glfwSetWindowTitle(window, std::string("Window ( FPS:" + std::to_string(frameCount) + " )").c_str());

		frameCount = 0;
		previousTime = currentTime;
	}
}

void rrts::Graphics::Window::pollEvents()
{
	glfwPollEvents();
}

void rrts::Graphics::Window::WhileRunning(std::function<void()> callback)
{
	setFrameCallBack(std::move(callback));

#ifdef EMSCRIPTEN
	emscripten_set_main_loop_arg(rrts::Graphics::frame, this, 0, true);
#else
	while (!glfwWindowShouldClose(window)) {
		frameCallback();
	}
#endif
}
#ifndef EMSCRIPTEN
void GLAPIENTRY MessageCallback( GLenum source,
	GLenum type, GLuint id, GLenum severity,
	GLsizei length, const GLchar* message, const void* userParam )
{
	if (type == GL_DEBUG_TYPE_ERROR)
	{
		std::stringstream stream;

		stream << "type = " << type << " severity = " << severity << " message = " << message;
		FATAL(stream.str())
	}
	else
	{
		std::stringstream stream;

		stream << "type = " << type << " severity = " << severity << " message = " << message;
		LOG(stream.str())
	}
}
#endif

void rrts::Graphics::Window::createWindow(int width, int height)
{
	previousTime = glfwGetTime();

	rrts::User::Logger::info("Initialized Window");

	if (!glfwInit()) {
		FATAL("GLFW Failed to initialize")
	}

#ifndef EMSCRIPTEN
#else
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#endif
//      attempting to support opengl es 2 and opengl 3

//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	window = glfwCreateWindow(width, height, "Window", nullptr, nullptr);
	if (!window) {
		FATAL("glfwCreateWindow failed")
	}
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	GLenum err=glewInit();
	if(err!=GLEW_OK) {
		FATAL(std::string("glewInit failed: ") + std::string((char *)glewGetErrorString(err)))
	}
#ifndef EMSCRIPTEN
	glEnable              ( GL_DEBUG_OUTPUT );
	glDebugMessageCallback( MessageCallback, nullptr );
#endif
	glfwSwapInterval( 0 );

	rrts::User::Session::getInstance()->initialize();
}

void rrts::Graphics::Window::runFrame()
{
	frameCallback();
}

void rrts::Graphics::Window::setFrameCallBack(std::function<void()> callback)
{
	frameCallback = std::move(callback);
}

void rrts::Graphics::Window::clear(float r, float g, float b, float a)
{
	glViewport(0, 0, rrts::User::Session::getInstance()->getWindowSize().Width,
		rrts::User::Session::getInstance()->getWindowSize().Height);
	glClearColor(r, g, b, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void rrts::Graphics::Window::clear()
{
	clear(0.f,0.f,0.f,1.f);
}
