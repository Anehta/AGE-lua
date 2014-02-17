
uniform mat4 mvp_matrix;

attribute vec4 a_position;
attribute vec2 a_texcoord;

varying vec2 qt_TexCoord0;
varying vec2 v_texCoord;

void main()
{
    gl_Position = mvp_matrix * a_position;

    qt_TexCoord0 = a_texcoord;
    v_texCoord = a_texcoord;
}
//! [0]
