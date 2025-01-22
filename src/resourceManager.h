//
// Created by trangnt on 17/11/2024.
//

#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H
#include <string>
#include <map>
#include "shader.h"
#include "texture.h"

class ResourceManager {
public:
    static std::map<std::string, Shader> Shaders;
    static std::map<std::string, Texture> Textures;
    static Shader       LoadShader(const char *vShaderFile, const char *fShaderFile, std::string name);
    static Shader       GetShader(std::string name);
    static Texture      LoadTexture(const char *file, bool alpha, std::string name);
    static Texture      &GetTexture(std::string name);
    static void Clear();
private:
    ResourceManager() { }
    static Shader   loadShaderFromFile(const char *vShaderFile, const char *fShaderFile);
    static Texture  loadTextureFromFile(const char *file, bool alpha);
};

#endif //RESOURCE_MANAGER_H
