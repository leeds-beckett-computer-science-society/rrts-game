#include <iostream>
#include <Window.h>

int main(int argc, char *argv[])
{
	float r = 0.0f, g = 0.0f, b = 0.0f;

	rrts::Graphics::Window window(1280, 720);

	window.WhileRunning([&](){
		window.pollEvents();

		if (r >= 1.0f)
			r = 0.1f;
		if (g >= 1.0f)
			g = 0.1f;
		if (b >= 1.0f)
			b = 0.1f;

		r += 0.001f;
		g += 0.005f;
		b += 0.003f;

		glViewport(0, 0, 1280, 720);
		glClearColor(r, g, b, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		window.swapBuffer();
	});

	return 0;
}