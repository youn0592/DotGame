
attribute vec2 a_Position;

uniform float u_Time;

void main()
{
    vec2 pos = a_Position;

    pos.x += u_Time;

gl_Position = vec4( sin(u_Time * pos), 0, 1 );
}
