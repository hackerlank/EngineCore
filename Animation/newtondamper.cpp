#include "newtondamper.h"
#include <qmath.h>
#include <QDebug>

const float NewtonDamper::FLOAT_MAX = std::numeric_limits<float>::max();




NewtonDamper::NewtonDamper(float * controlValue, float acceleration, float maxSpeed) : Animator(controlValue)
{
    this->lastValue = 0;
    this->lastTime = 0;

    this->acceleration = acceleration;
    this->speed = 0;

    this->maxSpeed = maxSpeed;
}

void NewtonDamper::updateAnimation(unsigned long time, double elapsedTime)
{
    float currentValue = *value; //read

    double elapsed = static_cast<double>(time - lastTime) / 1000.0;

    float nextValue;

    float dirAccl;

    if(currentValue == lastValue)
        return;



    if(currentValue >= lastValue)
        dirAccl = 1.0f;
    else
        dirAccl = -1.0f;

  //  float s = speed * elapsed + acceleration + elapsed;
   // if(lastValue/currentValue > 0.5)
   //     dirAccl = -dirAccl;

    speed += dirAccl * acceleration * elapsed;

    nextValue = lastValue + (speed * elapsed);


    if(fabs(currentValue - lastValue) < fabs(currentValue - nextValue)){
        nextValue = currentValue;
        speed = 0.0;
    }

    //return
    *value = nextValue;
    lastValue = nextValue;
}

float NewtonDamper::getSpeed() const
{
    return speed;
}

void NewtonDamper::setSpeed(float value)
{
    speed = value;
}

float NewtonDamper::getMaxSpeed() const
{
    return maxSpeed;
}

void NewtonDamper::setMaxSpeed(float value)
{
    maxSpeed = value;
}

float NewtonDamper::getAcceleration() const
{
    return acceleration;
}

void NewtonDamper::setAcceleration(float value)
{
    acceleration = value;
}
