#include <iostream>
#include <Window.h>
#include <Shader.h>

int main(int argc, char *argv[])
{
	float r = 0.0f, g = 0.0f, b = 0.0f;
	rrts::Graphics::Window window(1280, 720);

	rrts::Graphics::Shader shader;
	shader.loadFromFile("shaders/fragment.glsl", "shaders/vertex.glsl", "");

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

		window.clear(r, g, b, 1.f);

		window.swapBuffer();
	});

	return 0;
}