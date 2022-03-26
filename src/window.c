#include "window.h"

void glfw_error_func(int code, const char* str) {
    fprintf(stderr, "GLFW Error: %s\nCode: %d\n", str, code);
}

Window createWindow(int width, int height, char* title) {
    if (!global_state.initialized.glfw) {
        if (!glfwInit()) {
            fprintf(stderr, "Failed to initialize GLFW!\n");
            exit(-1);
        }
        glfwSetErrorCallback(glfw_error_func);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        global_state.initialized.glfw = 1;
    }

    Window window;
    window.glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);
    window.open = 1;
    window.pause = 0;
    window.frame_cap = -1;
    window.last_frame = 0;
    window.delta_time = glfwGetTime();

    if (!window.glfwWindow) {
        fprintf(stderr, "Failed to create glfw window!\n");
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window.glfwWindow);

    if (!global_state.initialized.glad) {
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            fprintf(stderr, "Failed to initialize GLAD!\n");
            exit(-1);
        }
        global_state.initialized.glad = 1;
    }

    glViewport(0, 0, width, height);

    return window;
}

void setFrameLimit(Window* window, int frame_limit) {
    window->frame_cap = frame_limit;
}

void updateWindow(Window* window) {
    window->delta_time = glfwGetTime() - window->last_frame;
    if (window->delta_time < 1.f/(double)window->frame_cap) {
        window->pause = 1;
        return;
    }
    window->last_frame = glfwGetTime();
    window->pause = 0;
    glfwPollEvents();
    glfwSwapBuffers(window->glfwWindow);
    window->open = !glfwWindowShouldClose(window->glfwWindow);
}

void destroyWindow(Window window) {
    glfwDestroyWindow(window.glfwWindow);
}

void destroyWindows() {
    glfwTerminate();
    global_state.initialized.glfw = 0;
}