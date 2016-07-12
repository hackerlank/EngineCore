#include "camera.h"

Camera::Camera(int width, int height) :
                   position(0.0f,0.0f,0.0f),
                   viewDirection(0.0f,0.0f,-1.0f),
                   up(0.0f,1.0f,0.0f)
{
    angleFieldOfView = 60.0f;
    aspectRatio = (float)width/height;
    nearP = 0.1f;
    farP = 10.0f;
}

QMatrix4x4 Camera::getWorldToViewMatrix() const
{
    QMatrix4x4 ret;
    ret.lookAt(position,position+viewDirection,up);
    return ret;
}

QMatrix4x4 Camera::getViewToProjectionMatrix() const
{
    QMatrix4x4 ret;
    ret.perspective(angleFieldOfView,aspectRatio,nearP,farP);
    return ret;
}
