#include "entity.h"

Entity makeEntity(Model* model, vec3 position, vec3 scale, vec3 rotation) {
    Entity e;
    e.model = model;
    memcpy(e.position, position, sizeof(vec3));
    memcpy(e.scale, scale, sizeof(vec3));
    memcpy(e.rotation, rotation, sizeof(vec3));

    return e;
}

void entityMoveTo(Entity* e, vec3 newPos) {
    memcpy(e->position, newPos, sizeof(vec3));
}

void entityMoveToF(Entity* e, float newX, float newY, float newZ) {
    e->position[0] = newX;
    e->position[1] = newY;
    e->position[2] = newZ;
}

Entity makeDefaultEntity(Model* model) {
    Entity e;
    e.model = model;

    memcpy(e.position, GLM_VEC3_ZERO, sizeof(vec3));
    memcpy(e.scale, GLM_VEC3_ONE, sizeof(vec3));
    memcpy(e.rotation, GLM_VEC3_ZERO, sizeof(vec3));

    return e;
}

void translateEntity(Entity* e, vec3 translation) {
    glm_vec3_add(e->position, translation, e->position);
}

void translateEntityF(Entity* e, float x, float y, float z) {
    vec3 a = {x, y, z};
    glm_vec3_add(e->position, a, e->position);
}

void renderEntity(Entity* e) {
    mat4 trans_mat;
    glm_mat4_identity(trans_mat);
    glm_translate(trans_mat, e->position);
    for (int i = 0; i < 3; i++) {
        vec3 axis = {0, 0, 0};
        axis[i] = 1;
        glm_rotate(trans_mat, e->rotation[i], axis);
    }
    glm_scale(trans_mat, e->scale);

    shaderSetUniformMat4(e->model->shader, "transform", trans_mat);

    renderModel(e->model);
}

void printEntityInfo(Entity* e) {
    printf("Entity Info: \n"
           "Position: %f, %f, %f\n"
           "Rotation: %f, %f, %f\n"
           "Scale: %f, %f, %f\n\n", e->position[0], e->position[1], e->position[2], e->rotation[0], e->rotation[1], e->rotation[2],
           e->scale[0], e->scale[1], e->scale[2]);
}