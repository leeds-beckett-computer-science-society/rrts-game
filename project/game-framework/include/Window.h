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
#ifndef RRTS_WINDOW_H
#define RRTS_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <functional>
#include <TargetRenderer.h>

namespace rrts
{
    namespace User
    {
        class Session;
    }
    namespace Graphics
    {
#ifdef EMSCRIPTEN
	static void frame(void* inst);
#endif
	class RenderTarget;

	/**
	 * @author jack martin
	 */
	class Window : public TargetRenderer
	{
	public:
	    /**
	     * Creates window and initializes opengl 3.3
	     * @param width
	     * @param height
	     */
	    Window(int width, int height);

	    /**
	     * Creates window, initializes opengl and sets the frame callback
	     * @param width
	     * @param height
	     * @param callback
	     */
	    Window(int width, int height, std::function<void()> callback);

	    ~Window();

	    /**
	     * swaps the window buffer
	     */
	    void swapBuffer();

	    /**
	     * Polls events and updates the input manager
	     * @warning program will halt if not called inside the game loop
	     */
	    void pollEvents();

	    /**
	     * Window while loop, this has to be the main game loop for the sake of compatibility
	     * @param callback
	     */
	    void WhileRunning(std::function<void()> callback);

	    /**
	     * Clears the screen to black
	     */
	    void clear();

	    /**
	     * Clears the screen and sets the colour to the rgb values inputted
	     * @param r
	     * @param g
	     * @param b
	     * @param a
	     */
	    void clear(float r, float g, float b, float a);

	private:

	    void createWindow(int width, int height);

	    void setFrameCallBack(std::function<void()> callback);

	    void runFrame();

	    double previousTime = 0;
	    unsigned int frameCount = 0;

#ifdef EMSCRIPTEN
	    friend void frame(void* inst);
#endif
	    GLFWwindow *window{};
	    std::function<void()> frameCallback;

	    friend rrts::User::Session;
	};

#ifdef EMSCRIPTEN
	static void frame(void* inst)
	{
		auto win = static_cast<Window *>(inst);

		win->runFrame();
	}
#endif
    }
}
#endif
