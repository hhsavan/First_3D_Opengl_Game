#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include<string>
#include<map>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

class ShaderProgram
{
public:
    ShaderProgram();
    ~ShaderProgram();
   
    void attachShader(const char* fileName,unsigned int shaderType);

    void link();

    void use();
    
    void addUniform(const std::string& varName);
    void setFloat(const std::string& varName, const float value);
    void setVec3(const std::string& varName, const glm::vec3& vec);
    void setVec4(const std::string& varName, const glm::vec4& vec);
private:
    std::string getShaderFromFile(const char* fileName);
    
    std::map<std::string,unsigned int> m_UniformMap;
    
    
    unsigned int m_ProgramId;
  
};


#endif