
attribute vec2 a_Position;

uniform float u_Time;

uniform vec2 u_Pos;

void main()
{
    vec2 pos = a_Position + u_Pos;

    pos -= 5;
    pos /= 5;

    //pos.x += u_Time;

   gl_Position = vec4(pos, 0, 1 );
}
