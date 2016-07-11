#ifndef NEWTONDAMPER_H
#define NEWTONDAMPER_H

#include "animator.h"
#include <limits>

class NewtonDamper : public Animator
{
   static const float FLOAT_MAX;

private:
    Q_OBJECT

    float lastValue;
    unsigned long lastTime;

    float acceleration;
    float speed;

    float maxSpeed;

protected:

    virtual void updateAnimation(unsigned long time, double elapsedTime);


public:
    NewtonDamper(float * controlValue, float acceleration = 1, float maxSpeed = FLOAT_MAX);



    float getAcceleration() const;
    void setAcceleration(float value);

    float getSpeed() const;
    void setSpeed(float value);

    float getMaxSpeed() const;
    void setMaxSpeed(float value);
};

#endif // NEWTONDAMPER_H
