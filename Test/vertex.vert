#version 330
in vec3 glVertex;
in vec3 glNormal;
in vec3 glDiffuesColor;
in vec3 glLightDiffuseColor;
in vec3 glLightAmbientColor;

in vec3 glLightDir;

in mat4 glmWorldViewProjection;


out vec4  fragPos;
out vec4  fragColor;



float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main(void)
{
   gl_Position =glmWorldViewProjection * vec4(glVertex,1) ;



   fragColor = vec4(1,1,1,1) * vec4(glNormal,0); //vec4(rand(vec2(glVertex.x+glVertex.y,glVertex.z)),rand(vec2(glVertex.y+glVertex.z,glVertex.x)),rand(vec2(glVertex.z+glVertex.x,glVertex.y)),1) *vec4(glLightAmbientColor,1) ;

}

