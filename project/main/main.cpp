#include <iostream>
#include <Window.h>
#include <Shader.h>

int main(int argc, char *argv[])
{
	rrts::Graphics::Window window(1280, 720);

	rrts::Graphics::Shader shader;
	shader.loadFromFile("shaders/fragment.glsl", "shaders/vertex.glsl", "");

	window.WhileRunning([&](){
		window.pollEvents();

		window.clear();



		window.swapBuffer();
	});

	return 0;
}