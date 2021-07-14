#version 450

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;

//push constant
layout(push_constant) uniform Push {
  mat4 transform;
  vec3 color;
} push;

layout(location = 0) out vec3 fragColor;

//once for each vertex so the position variable is equal to the position of the current vertex
void main() {
  //center of the screen is (0,0), upper left corner is (-1,-1)
  //we need to define THIS variable : gl_Position
  //gl_Position = vec4(position, 0.0, 1.0);
  gl_Position = push.transform * vec4(position, 1.0);
  //fourth value divide the rest to normalise

  fragColor = color;
}