#ifndef OPENGL_ENGINE_V1_SHADER_H
#define OPENGL_ENGINE_V1_SHADER_H

#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include <cglm/cglm.h>

#include "engine.h"
#include "memory.h"

typedef struct {
    unsigned int programID;
} Shader;

Shader createShader(char* vertexPath, char* fragmentPath);
void useShader(Shader* shader);
void deleteShader(Shader shader);

void shaderSetUniformFloat(Shader* shader, char* name, float value);
void shaderSetUniformInt(Shader* shader, char* name, int value);
void shaderSetUniformMat4(Shader* shader, char* name, mat4 matrix);

#endif //OPENGL_ENGINE_V1_SHADER_H
