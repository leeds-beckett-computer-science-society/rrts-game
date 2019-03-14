#include <utility>

#include <Shader.h>
#include <GL/glew.h>
#include <string>
#include <fstream>
#include <streambuf>

rrts::Graphics::Shader::Shader() = default;

rrts::Graphics::Shader::~Shader()
{
	glDeleteProgram(programID);
}

void rrts::Graphics::Shader::loadFromFile(std::string vertex, std::string fragment, std::string geometry)
{
	if (programID)
		glDeleteProgram(programID);

	programID = glCreateProgram();
	if (!vertex.empty())
	{
		vertexid = glCreateShader(GL_VERTEX_SHADER);
		compileShader( LoadFile(std::move(vertex)), vertexid, GL_VERTEX_SHADER);
		glAttachShader(programID, vertexid);
		glDeleteShader(vertexid);
	}
	if (!fragment.empty())
	{
		fragmentid = glCreateShader(GL_FRAGMENT_SHADER);
		compileShader(LoadFile(std::move(fragment)), fragmentid, GL_FRAGMENT_SHADER);
		glAttachShader(programID, fragmentid);
		glDeleteShader(fragmentid);
	}
//	if (!geometry.empty())
//	{
//		geometryid = glCreateShader(GL_GEOMETRY_SHADER);
//		compileShader(LoadFile(std::move(geometry)), geometryid, GL_GEOMETRY_SHADER);
//		glAttachShader(programID, geometryid);
//	}
	glLinkProgram(programID);

	std::string error;
	int success = 0;
	glGetProgramiv(programID, GL_LINK_STATUS, &success);
	if (!success)
	{
		error += "== PROGRAM ERROR == \n";
		char info[1024];
		glGetProgramInfoLog(programID, 1024, nullptr, info);
		error += info;
	}
	std::cout << error << "\n";
	glUseProgram(0);
}

std::string rrts::Graphics::Shader::LoadFile(std::string path)
{
	std::string str;
#ifdef EMSCRIPTEN

	FILE *in_file  = fopen("name_of_file", "rb"); // read only

	if (in_file == NULL)
	{
		printf("Error! Could not open file\n");
		exit(-1); // must include stdlib.h
	}
#else
	{
		std::ifstream stream(path);
		for( std::string line; getline( stream, line ); )
		{
			str += line + "\n";
		}
		stream.close();
	}
#endif
	return std::move(str);
}

std::string rrts::Graphics::Shader::errorCheck(unsigned int shader, unsigned int errortype, std::string message)
{
	std::string error;
	int success = 0;
	glGetShaderiv(shader, errortype, &success);
	if (!success)
	{
		error += message + "\n";
		char info[1024];
		glGetShaderInfoLog(shader, 1024, nullptr, info);
		error += info;
	}
	return std::move(error);
}

void rrts::Graphics::Shader::compileShader(std::string source, unsigned int id, unsigned int type)
{
	const GLchar* c_src = source.c_str();
	glShaderSource(id, 1, &c_src, nullptr);
	glCompileShader(id);
	std::cout << errorCheck(id, GL_COMPILE_STATUS, "== SHADER ERROR ==");
}

void rrts::Graphics::Shader::bind()
{

}
