#ifdef GL_ES
// Set default precision to medium
precision mediump int;
precision mediump float;
#endif

uniform float amplitude;
uniform float dividerValue;
uniform float frequency;
uniform float time;
uniform float red;
uniform float green;
uniform float blue;
uniform sampler2D source;
uniform lowp float age_Opacity;
varying vec2 v_texCoord;

void main()
{

    vec2 uv = v_texCoord.xy;
    vec2 tc = v_texCoord;
    if (uv.x < dividerValue) {
        vec2 p = sin(time + frequency * v_texCoord);
        tc += amplitude * vec2(p.y, -p.x);
    }
    gl_FragColor =  texture2D(source, tc) * vec4(red,green,blue,age_Opacity);
    //gl_FragColor = texture2D(source, v_texCoord);
}
/*
uniform float amplitude;
uniform float dividerValue;
uniform float frequency;
uniform float time;

uniform sampler2D source;
uniform lowp float qt_Opacity;
varying vec2 v_texCoord;

void main()
{
    vec2 uv = v_texCoord.xy;
    vec2 tc = v_texCoord;
    if (uv.x < dividerValue) {
        vec2 p = sin(time + frequency * v_texCoord);
        tc += amplitude * vec2(p.y, -p.x);
    }
    gl_FragColor = qt_Opacity * texture2D(source, tc);
}
*/



/*
#ifdef GL_ES
// Set default precision to medium
precision mediump int;
precision mediump float;
#endif

uniform sampler2D source;
uniform lowp float qt_Opacity;
varying vec2 v_texCoord;

void main()
{
    gl_FragColor = texture2D(source, v_texCoord);
}
*/
