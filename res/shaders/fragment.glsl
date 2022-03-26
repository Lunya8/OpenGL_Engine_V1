#version 330 core
in vec2 passTexCoords;

out vec4 FragColor;

uniform float greenVal;
uniform sampler2D ourTexture;

void main() {
    FragColor = texture(ourTexture, passTexCoords);
}