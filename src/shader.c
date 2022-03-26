#include "shader.h"

unsigned int makeSpecificShader(char* path, GLenum type) {
    unsigned int shader = glCreateShader(type);

    // READING FROM FILE
    FILE* file = fopen(path, "r");
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    rewind(file);

    char* source = gmalloc(length);
    fread(source, 1, length, file);
    source[length] = 0;

    // SHADER OBJECT
    glShaderSource(shader, 1, (const char**)&source, NULL);
    glCompileShader(shader);

    // DEBUGGING
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        fprintf(stderr, "Shader Source: \n%s\n", source);
        fprintf(stderr, "Failed to compile shader of type %s! Error:\n%s\n", (type == GL_VERTEX_SHADER ? "vertex" : "fragment"), infoLog);
    }

    // CLEANUP
    fclose(file);
    gfree(source);

    return shader;
}

Shader createShader(char* vertexPath, char* fragmentPath) {
    if (!global_state.initialized.glad) {
        fprintf(stderr, "Glad not initialized yet in makeShader(%s, %s)!", vertexPath, fragmentPath);
        exit(-1);
    }
    Shader shader;

    // SHADERS AND LINKING
    unsigned int vertexShader = makeSpecificShader(vertexPath, GL_VERTEX_SHADER);
    unsigned int fragmentShader = makeSpecificShader(fragmentPath, GL_FRAGMENT_SHADER);
    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    // DEBUG
    int success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        fprintf(stderr, "Failed to link shader! Error: \n%s\n", infoLog);
        exit(-1);
    }

    // CLEANUP
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    shader.programID = program;
    return shader;
}

void useShader(Shader* shader) {
    glUseProgram(shader->programID);
}

void deleteShader(Shader shader) {
    glDeleteProgram(shader.programID);
}

void shaderSetUniformFloat(Shader* shader, char* name, float value) {
    glUniform1f(glGetUniformLocation(shader->programID, name), value);
}

void shaderSetUniformInt(Shader* shader, char* name, int value) {
    glUniform1i(glGetUniformLocation(shader->programID, name), value);
}

void shaderSetUniformMat4(Shader* shader, char* name, mat4 matrix) {
    glUniformMatrix4fv(glGetUniformLocation(shader->programID, name), 1, GL_FALSE, (float*)matrix);
}