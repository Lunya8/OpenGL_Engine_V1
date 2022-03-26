#define STB_IMAGE_STATIC

#include "window.h"
#include "shader.h"
#include "model.h"
#include "entity.h"

int main() {
    Window window = createWindow(800, 600, "Test Window");
    setFrameLimit(&window, 60);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    float vertices[] = {
            0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
            -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
    };
    unsigned int indices[] = {
            0, 1, 3,
            1, 2, 3
    };

    Shader shader = createShader("res/shaders/vertex.glsl", "res/shaders/fragment.glsl");
    Texture texture = loadTexture("res/textures/qr.png");
    Model model = loadModel(vertices, 4, indices, 6, &shader, &texture);
    Entity entity = makeDefaultEntity(&model);

    while (window.open) {
        do {
            updateWindow(&window);
        } while (window.pause);

        double time = glfwGetTime();
        entityMoveToF(&entity, 4*(time - floor(time)) - 2, sin(time)/2, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        renderEntity(&entity);
    }

    deleteModel(model);
    deleteShader(shader);
    destroyWindows();
    return 0;
}
