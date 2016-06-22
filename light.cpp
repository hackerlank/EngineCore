#include "light.h"

Light::Light() : position(-5.0f,2.0f,0.0f), direction(1.0f,0.0f,0.0f), diffuseColor(0.9f,0.9f,0.9f),
                 ambientColor(0.1f,0.1f,0.1f), attenstion(0,0,0.04f,0)
{
    cosHalfPhi = 0.4;
    cosHalfTheta = 0.9;
}

QVector3D Light::getAmbientColor() const
{
    return ambientColor;
}

void Light::setAmbientColor(const QVector3D &value)
{
    ambientColor = value;
}

QVector3D Light::getDiffuseColor() const
{
    return diffuseColor;
}

void Light::setDiffuseColor(const QVector3D &value)
{
    diffuseColor = value;
}

QVector3D Light::getDirection() const
{
    return direction;
}

void Light::setDirection(const QVector3D &value)
{
    direction = value;
}

QVector3D Light::getPosition() const
{
    return position;
}

QVector4D Light::getAttenstion() const
{
    return attenstion;
}

void Light::setAttenstion(const QVector4D &value)
{
    attenstion = value;
}

float Light::getCosHalfPhi() const
{
    return cosHalfPhi;
}

void Light::setCosHalfPhi(float value)
{
    cosHalfPhi = value;
}

float Light::getCosHalfTheta() const
{
    return cosHalfTheta;
}

void Light::setCosHalfTheta(float value)
{
    cosHalfTheta = value;
}


