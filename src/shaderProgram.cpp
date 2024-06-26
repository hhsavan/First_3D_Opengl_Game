#include "../include/shaderProgram.hpp"
#include <glad/glad.h>
#include <fstream>
#include <iostream>
#include <sstream>

ShaderProgram::ShaderProgram()
{
    m_ProgramId = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(m_ProgramId);
}

void ShaderProgram::link()
{
    glLinkProgram(m_ProgramId);
    int isLinked;
    char log[512];
    glGetProgramiv(m_ProgramId, GL_LINK_STATUS, &isLinked);

    if (!isLinked)
    {
        glGetProgramInfoLog(m_ProgramId, 512, 0, log);
        std::cout << "Program Linking Error:" << std::endl << log << std::endl;
    }
}

void ShaderProgram::use()
{
    glUseProgram(m_ProgramId);
}

void ShaderProgram::addUniform(const std::string& varName)
{
    m_UniformVars[varName] = glGetUniformLocation(m_ProgramId, varName.c_str());
}

void ShaderProgram::setFloat(const std::string& varName, float value)
{
    glUniform1f(m_UniformVars[varName], value);
}

void ShaderProgram::setVec3(const std::string& varName, const glm::vec3& value)
{
    glUniform3f(m_UniformVars[varName], value.x, value.y, value.z);
}

void ShaderProgram::setMat3(const std::string& varName, const glm::mat3* ptrValue)
{
    glUniformMatrix3fv(m_UniformVars[varName], 1, GL_FALSE, (GLfloat*)ptrValue);
}

void ShaderProgram::setVec4(const std::string& varName, const glm::vec4& value)
{
    glUniform4f(m_UniformVars[varName], value.r, value.g, value.b, value.a);
}

void ShaderProgram::setMat4(const std::string& varName, const glm::mat4* mtx)
{
    glUniformMatrix4fv(m_UniformVars[varName], 1, GL_FALSE, (GLfloat*)mtx);
}

void ShaderProgram::attachShader(const char* fileName, unsigned int shaderType)
{
    unsigned int shaderId = glCreateShader(shaderType);

    std::string sourceCode = getShaderFromFile(fileName);
    const char* chSourceCode = sourceCode.c_str();

    glShaderSource(shaderId, 1, &chSourceCode, nullptr);
    glCompileShader(shaderId);

    int isCompiled;
    char log[512];
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isCompiled);

    if (!isCompiled)
    {
        glGetShaderInfoLog(shaderId, 512, 0, log);
        std::string strType;
        switch (shaderType)
        {
        case GL_VERTEX_SHADER:
            strType = "Vertex Shader";
            break;
        case GL_FRAGMENT_SHADER:
            strType = "Fragment Shader";
            break;
        }
        std::cout << "Shader Type: " << strType << std::endl << log << std::endl;
    }

    glAttachShader(m_ProgramId, shaderId);
    glDeleteShader(shaderId);
}

std::string ShaderProgram::getShaderFromFile(const char* fileName)
{
    std::ifstream file(fileName);
    std::stringstream buffer;

    if (file.is_open())
    {
        buffer << file.rdbuf();
        file.close();
    }

    return buffer.str();
}

int ShaderProgram::getUniform(const std::string& varName) const
{
    auto it = m_UniformVars.find(varName);
    if (it != m_UniformVars.end())
    {
        return it->second;
    }
    return -1; // Return -1 if the uniform is not found
}
