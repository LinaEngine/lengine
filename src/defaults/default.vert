#version 450

layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec3 inColour;

layout(location = 0) out vec3 frag_col;

/*
layout(push_constant) uniform pushConstant
{
    mat4 transMat;
} ps;
*/

void main() {
   // gl_Position = ps.transMat * inPosition;
    gl_Position = inPosition;
    frag_col = inColour;
}

