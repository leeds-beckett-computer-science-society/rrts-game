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
#ifndef RRTS_SHADER_H
#define RRTS_SHADER_H

#include <iostream>
#include <vec3.hpp>
#include <glm.hpp>

namespace rrts
{
    namespace Graphics
    {
        /**
	 * @author jack martin
	 */
        class Shader
	{
	public:
	    Shader();

	    ~Shader();

	    /**
	     * Loads the shaders from the file. the geometry shader is optional my default but the others are required
	     * @param vertex
	     * @param fragment
	     * @param geometry
	     */
	    void loadFromFile(std::string vertex, std::string fragment, std::string geometry = "");

	    void bind();

	    static void unbind();

	    /**
	     * Adds a Vec3 uniform to the shader
	     * @param vec3
	     * @param name
	     */
	    void addUniformVec3(glm::vec3 vec3, const std::string& name);

	    /**
	     * Adds a Mat4 uniform to the shader
	     * @param mat4
	     * @param name
	     */
	    void addUniformMat4(glm::mat4 mat4, const std::string& name);

	    /**
	     * Adds a Mat3 uniform to the shader
	     * @param mat3
	     * @param name
	     */
	    void addUniformMat3(glm::mat3 mat3, const std::string& name);

	    /**
	     * Adds a Mat2 uniform to the shader
	     * @param mat2
	     * @param name
	     */
	    void addUniformMat2(glm::mat2 mat2, const std::string& name);

	    unsigned int getId();
	private:
	    int getUniformLocation(const std::string& name);

	    unsigned int vertexid;
	    unsigned int fragmentid;
	    unsigned int geometryid;

	    unsigned int programID;

	    void compileShader(std::string source, unsigned int id, unsigned int type);

	    std::string LoadFile(std::string path);

	    std::string errorCheck(unsigned int shader, unsigned int errortype, std::string message);
	};
    }
}

#endif //RRTS_SHADER_H
