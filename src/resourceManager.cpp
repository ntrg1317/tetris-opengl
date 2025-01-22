//
// Created by trangnt on 17/11/2024.
//

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "glad/glad.h"

#include "resourceManager.h"

#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>

std::map<std::string, Texture>    ResourceManager::Textures;
std::map<std::string, Shader>     ResourceManager::Shaders;

Shader ResourceManager::LoadShader(const char *vShaderFile, const char *fShaderFile, const std::string shaderName) {
    Shaders[shaderName] = loadShaderFromFile(vShaderFile, fShaderFile);
    return Shaders[shaderName];
}

Shader ResourceManager::GetShader(std::string shaderName) {
    return Shaders[shaderName];
}

Texture ResourceManager::LoadTexture(const char *file, bool alpha, std::string name){
    Textures[name] = loadTextureFromFile(file, alpha);
    return Textures[name];
}

Texture &ResourceManager::GetTexture(std::string textureName) {
    return Textures[textureName];
}

void ResourceManager::Clear()
{
    // (properly) delete all shaders
    for (auto iter : Shaders)
        glDeleteProgram(iter.second.id);
    // (properly) delete all textures
    for (auto iter : Textures)
        glDeleteTextures(1, &iter.second.id);
}

Shader ResourceManager::loadShaderFromFile(const char *vShaderFile, const char *fShaderFile) {
    std::string vertexCode;
    std::string fragmentCode;

    std::ifstream vertexShaderFile(vShaderFile);
    std::ifstream fragmentShaderFile(fShaderFile);
    if (vertexShaderFile)
    {
        while (vertexShaderFile)
        {
            std::string vbuffer;
            getline(vertexShaderFile, vbuffer);
            vertexCode += vbuffer + "\n";
        }
    }

    if (fragmentShaderFile)
    {
        while (fragmentShaderFile)
        {
            std::string buffer;
            getline(fragmentShaderFile, buffer);
            fragmentCode += buffer + "\n";
        }
    }

    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();

    Shader shader;
    shader.Compile(vShaderCode, fShaderCode);
    return shader;
}

Texture ResourceManager::loadTextureFromFile(const char *file, bool alpha) {
    Texture texture;
    if (alpha) {
        texture.Internal_Format = GL_RGBA;
        texture.Image_Format = GL_RGBA;
    }

    int width, height, nrChannels;
    unsigned char *data = stbi_load(file, &width, &height, &nrChannels, 0);
    texture.Generate(width, height, data);
    stbi_image_free(data);

    return texture;
}