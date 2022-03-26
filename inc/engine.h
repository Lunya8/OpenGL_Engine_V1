#ifndef OPENGL_ENGINE_V1_ENGINE_H
#define OPENGL_ENGINE_V1_ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct engine_state {
    struct {
        int glfw;
        int glad;
        int textures;
    } initialized;
};

struct engine_state global_state;

#endif //OPENGL_ENGINE_V1_ENGINE_H
