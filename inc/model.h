#ifndef OPENGL_ENGINE_V1_MODEL_H
#define OPENGL_ENGINE_V1_MODEL_H

#include <glad/glad.h>
#include <stdlib.h>
#include "shader.h"
#include "texture.h"

typedef struct {
    unsigned int VAO;
    int indices;
    struct {
        unsigned int VBO;
        unsigned int EBO;
    } buffers;
    Shader* shader;
    Texture* texture;
} Model;

Model loadModel(float vertices[], long vertex_count, unsigned int indices[], long index_count, Shader* shader, Texture* texture);
void renderModel(Model* model);
void deleteModel(Model model);

#endif //OPENGL_ENGINE_V1_MODEL_H
