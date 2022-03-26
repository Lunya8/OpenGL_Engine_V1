cmake_minimum_required(VERSION 3.21)
project(OpenGL_Engine_V1 C)

set(CMAKE_C_STANDARD 99)

add_executable(${PROJECT_NAME} src/main.c ext/src/glad.c src/window.c src/model.c src/shader.c src/memory.c src/texture.c src/entity.c)
target_include_directories(${PROJECT_NAME} PUBLIC ext/inc inc)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/ext/lib/libglfw3.a ${PROJECT_SOURCE_DIR}/ext/lib/libcglm.a -lX11 -lpthread -lXrandr -lXi -ldl -lGL -lm)
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)