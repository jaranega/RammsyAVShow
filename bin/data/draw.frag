#version 120
#extension GL_ARB_texture_rectangle : enable

void main()
{
  	float windowWidth = 1024.0;
    float windowHeight = 768.0;
    
    float r = gl_FragCoord.x / windowWidth;
    float g = gl_FragCoord.y / windowHeight;
    float b = 1.0;
    float a = 0.5;

    gl_FragColor = vec4(r, g, b, a);
}
