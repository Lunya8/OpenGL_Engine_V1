#ifndef OPENGL_ENGINE_V1_ENTITY_H
#define OPENGL_ENGINE_V1_ENTITY_H

#include "model.h"
#include "string.h"
#include <cglm/cglm.h>

typedef struct {
    Model* model;
    vec3 position, scale, rotation; // rotation in radians
} Entity;

Entity makeEntity(Model* model, vec3 position, vec3 scale, vec3 rotation);
Entity makeDefaultEntity(Model* model);
void entityMoveTo(Entity* e, vec3 newPos); // These two funcs directly move entity to coords specified
void entityMoveToF(Entity* e, float newX, float newY, float newZ);
void translateEntity(Entity* e, vec3 translation); // These two move entity by the values, i.e. entity at (1, 0, 1)
void translateEntityF(Entity* e, float x, float y, float z); // would be moved to (2, -1, 0) by (1, -1, -1)
void renderEntity(Entity* e);
void printEntityInfo(Entity* e);

#endif //OPENGL_ENGINE_V1_ENTITY_H
