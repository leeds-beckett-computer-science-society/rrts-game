#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#include <SDL2/SDL_opengl.h>
#endif

#define WinWidth 500
#define WinHeight 500

float r, g, b = 0.0f;
bool Running = true;
SDL_Window *window;

void frame()
{
    SDL_Event Event;
    while (SDL_PollEvent(&Event)) {
        if (Event.type == SDL_KEYDOWN) {
            switch (Event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    Running = 0;
                    break;
                default:
                    break;
            }
        } else if (Event.type == SDL_QUIT) {
            Running = 0;
        }
    }

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

    SDL_GL_SwapWindow(window);
}

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 0);

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
            "window",                  // window title
            SDL_WINDOWPOS_UNDEFINED,           // initial x position
            SDL_WINDOWPOS_UNDEFINED,           // initial y positionSystem
            WinWidth,                               // width, in pixels
            WinHeight,                               // height, in pixels
            SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }
    SDL_GLContext Context = SDL_GL_CreateContext(window);
    glewExperimental = GL_TRUE;
    glewInit();

    SDL_GL_SetSwapInterval(1);

#ifdef EMSCRIPTEN
    emscripten_set_main_loop(frame, 30, true);
#else
    while (Running) {
        frame();
    }
#endif

    SDL_GL_DeleteContext(Context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}