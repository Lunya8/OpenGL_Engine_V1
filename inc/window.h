#ifndef OPENGL_ENGINE_V1_WINDOW_H
#define OPENGL_ENGINE_V1_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

#include "engine.h"

typedef struct {
    GLFWwindow* glfwWindow;
    int open;
    int pause;
    int frame_cap;
    double delta_time, last_frame;
} Window;

Window createWindow(int width, int height, char* title);
void setFrameLimit(Window* window, int frame_limit);
void updateWindow(Window* window);
void destroyWindow(Window window);
void destroyWindows();

#endif //OPENGL_ENGINE_V1_WINDOW_H
