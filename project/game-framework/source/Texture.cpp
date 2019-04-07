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
#include <Texture.h>
#include <GL/glew.h>

#define STB_IMAGE_IMPLEMENTATION 1
#include <stb_image.h>

rrts::Graphics::Texture::Texture()
{
	glGenTextures(1, &id);
}

rrts::Graphics::Texture::~Texture()
{
	glDeleteTextures(1, &id);
}

void rrts::Graphics::Texture::loadFromFile(std::string path)
{
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, STBI_rgb);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}

void rrts::Graphics::Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, id);
}

void rrts::Graphics::Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

glm::vec2 rrts::Graphics::Texture::getSize()
{
	return {width, height};
}
