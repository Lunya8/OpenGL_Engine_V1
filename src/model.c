#include "model.h"

Model loadModel(float vertices[], long vertex_count, unsigned int indices[], long index_count, Shader* shader, Texture* texture) {
    if (!global_state.initialized.glad) {
        fprintf(stderr, "GLAD not initialized in loadModel!");
        exit(-1);
    }

    Model model;
    model.shader = shader;
    model.texture = texture;
    model.indices = (int)index_count;
    glGenVertexArrays(1, &model.VAO);
    glBindVertexArray(model.VAO);

    glGenBuffers(1, &model.buffers.VBO);
    glBindBuffer(GL_ARRAY_BUFFER, model.buffers.VBO);
    glBufferData(GL_ARRAY_BUFFER, vertex_count*5*(long)sizeof(float), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &model.buffers.EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model.buffers.EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_count*(long)sizeof(int), indices, GL_STATIC_DRAW);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    return model;
}

void renderModel(Model* model) {
    useShader(model->shader);
    useTexture(model->texture);
    glBindVertexArray(model->VAO);
    glDrawElements(GL_TRIANGLES, model->indices, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void deleteModel(Model model) {
    glDeleteBuffers(1, &model.buffers.VBO);
    glDeleteBuffers(1, &model.buffers.EBO);
    glDeleteBuffers(1, &model.VAO);
}