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
#ifndef RRTS_SESSION_H
#define RRTS_SESSION_H

#include <GL/glew.h>
#include <glm.hpp>
#include <memory>
#include <GLFW/glfw3.h>
#include <iostream>

#ifdef linux
#define OS_VERSION "Linux"
#endif
#ifdef EMSCRIPTEN
#define OS_VERSION "Web"
#endif

namespace rrts
{
    namespace Graphics
    {
        class Window;
    }

    namespace User
    {
        struct size
        {
            unsigned int Width;
            unsigned int Height;
        };

        struct versionString
	{
		int minor;
		int major;
		std::string string;
	};

        struct OpenglContext
        {
            versionString version;
            int textureunits = 0;
            bool BufferArraySupported = true;
        };

        void windowResizeCallback(GLFWwindow* window, int width, int height);

        static std::string getCPUID();
        static long getMemorySize();

        /**
	 * @author jack martin
	 */
        class Session
	{
	public:
	    size getWindowSize();
	    void setWindow(rrts::Graphics::Window &window);
	    static Session* getInstance();

	    ~Session();

	    /**
	     * Gets the FPS which is calculated elsewhere
	     * @return FPS
	     */
	    unsigned int getFPS();

	    /**
	     * Method for setting the game fps. This shouldn't be called outside the window class.
	     * @param framecount
	     */
	    void setFPS(unsigned int framecount);

	    /**
	     * Gets the opengl context information such as it's version, what it supports, texture units, etc
	     * @return opengContext
	     */
	    OpenglContext getOpenglInfo();

	    /**
	     * Initalizes important session information
	     */
            void initialize();
	private:
	    Session();

	    rrts::Graphics::Window *window = nullptr;

	    unsigned int fps = 0;

	    // Default to 720p
	    unsigned int windowWidth = 1280;
	    unsigned int windowHeight = 720;

	    OpenglContext openglContext;
	private:
	    static std::unique_ptr<Session> instance;

	    friend void windowResizeCallback(GLFWwindow* window, int width, int height);
	};
    }
}

#endif //RRTS_SESSION_H
