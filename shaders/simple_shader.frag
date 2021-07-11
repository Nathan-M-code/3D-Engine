#version 450

layout (location = 0) in vec3 fragColor;

//declare the output variable
layout(location = 0) out vec4 outColor;

//for each pixel in the fragment (here in the triangle)
void main() {
    // r g b a
    outColor = vec4(fragColor, 1.0);
}