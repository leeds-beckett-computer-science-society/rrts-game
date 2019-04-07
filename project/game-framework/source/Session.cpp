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
#include <Session.h>
#include <Window.h>
#include <GL/glew.h>
#include <iostream>
#include <Logger.h>
std::unique_ptr<rrts::User::Session> rrts::User::Session::instance;

#ifndef EMSCRIPTEN
#ifdef linux

std::string rrts::User::getCPUID()
{
	// TODO: get cpu information from proc

	return "not implemented";
}

long rrts::User::getMemorySize()
{
	// TODO: get amount of memory in MB from proc

	return 0;
}
#endif
#endif
#ifdef EMSCRIPTEN

std::string rrts::User::getCPUID()
{
	// TODO: get cpu information somehow

	return "not implemented";
}

long rrts::User::getMemorySize()
{
	// TODO: get amount of memory in MB somehow

	return 0;
}

#endif

void rrts::User::windowResizeCallback(GLFWwindow *window, int width, int height)
{
	rrts::User::Session::getInstance()->windowWidth = static_cast<unsigned int>(width);
	rrts::User::Session::getInstance()->windowHeight = static_cast<unsigned int>(height);
}

rrts::User::size rrts::User::Session::getWindowSize()
{
	return {windowWidth, windowHeight};
}

rrts::User::Session *rrts::User::Session::getInstance()
{
	if (instance == nullptr)
		instance.reset(new Session());

	return instance.get();
}

void rrts::User::Session::setWindow(rrts::Graphics::Window &window)
{
	this->window = &window;
	glfwSetWindowSizeCallback(window.window, &windowResizeCallback);
}

rrts::User::Session::Session() = default;

unsigned int rrts::User::Session::getFPS()
{
	return fps;
}

void rrts::User::Session::setFPS(unsigned int framecount)
{
	fps = framecount;
}

rrts::User::OpenglContext rrts::User::Session::getOpenglInfo()
{
	return openglContext;
}

void rrts::User::Session::initialize()
{
	glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &openglContext.textureunits);

	glGetIntegerv(GL_MAJOR_VERSION, &openglContext.version.major);
	glGetIntegerv(GL_MINOR_VERSION, &openglContext.version.minor);
	openglContext.version.string = (char *) glGetString(GL_VERSION);

	LOG("New Session Started");
	LOG(std::string("Operating System: ") + OS_VERSION);
	LOG(std::string("CPU: ") + getCPUID());
	LOG(std::string("Memory: ") + std::to_string(getMemorySize()));
	LOG(std::string("Max Texture Units: ") + std::to_string(openglContext.textureunits) );
	LOG(std::string("Opengl Driver: ") + openglContext.version.string );
}

rrts::User::Session::~Session()
= default;
