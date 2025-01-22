//
// Created by trangnt on 17/11/2024.
//
#include "shader.h"

#include <iostream>
#include <ostream>

Shader::Shader() {}

Shader &Shader::Use() {
    glUseProgram(this->id);
    return *this;
}

void Shader::Compile(const char *vertexSource, const char *fragmentSource) {
    unsigned int sVertex, sFragment;
    // vertex Shader
    sVertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(sVertex, 1, &vertexSource, NULL);
    glCompileShader(sVertex);
    checkCompileErrors(sVertex, "VERTEX");
    // fragment Shader
    sFragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(sFragment, 1, &fragmentSource, NULL);
    glCompileShader(sFragment);
    checkCompileErrors(sFragment, "FRAGMENT");
    // shader program
    this->id = glCreateProgram();
    glAttachShader(this->id, sVertex);
    glAttachShader(this->id, sFragment);
    glLinkProgram(this->id);

    checkCompileErrors(this->id, "PROGRAM");
    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(sVertex);
    glDeleteShader(sFragment);
}

void Shader::SetFloat(const char *name, float value, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform1f(glGetUniformLocation(this->id, name), value);
}
void Shader::SetInteger(const char *name, int value, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform1i(glGetUniformLocation(this->id, name), value);
}
void Shader::SetVector2f(const char *name, float x, float y, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform2f(glGetUniformLocation(this->id, name), x, y);
}
void Shader::SetVector2f(const char *name, const glm::vec2 &value, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform2f(glGetUniformLocation(this->id, name), value.x, value.y);
}
void Shader::SetVector3f(const char *name, float x, float y, float z, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform3f(glGetUniformLocation(this->id, name), x, y, z);
}
void Shader::SetVector3f(const char *name, const glm::vec3 &value, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform3f(glGetUniformLocation(this->id, name), value.x, value.y, value.z);
}
void Shader::SetVector4f(const char *name, float x, float y, float z, float w, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform4f(glGetUniformLocation(this->id, name), x, y, z, w);
}
void Shader::SetVector4f(const char *name, const glm::vec4 &value, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform4f(glGetUniformLocation(this->id, name), value.x, value.y, value.z, value.w);
}
void Shader::SetMatrix4(const char *name, const glm::mat4 &matrix, bool useShader)
{
    if (useShader)
        this->Use();
    glUniformMatrix4fv(glGetUniformLocation(this->id, name), 1, false, glm::value_ptr(matrix));
}

void Shader::checkCompileErrors(unsigned int object, const std::string type) {
    int success;
    char info[1024];
    if (type != "PROGRAM") {
        glGetShaderiv(object, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(object, sizeof(info), nullptr, info);
            std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << " - " << info <<  std::endl;
        }
    } else {
        glGetProgramiv(object, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(object, 1024, NULL, info);
            std::cout << "| ERROR::SHADER: Link-time error: Type: " << type << " - "<< info << std::endl;
        }
    }
}