#ifndef OPENGL_ENGINE_V1_TEXTURE_H
#define OPENGL_ENGINE_V1_TEXTURE_H

#define STB_IMAGE_IMPLEMENTATION
#include "engine.h"

#include <glad/glad.h>

typedef struct {
    unsigned int id;
} Texture;

Texture loadTexture(char* path);
void useTexture(Texture* t);

#endif //OPENGL_ENGINE_V1_TEXTURE_H
