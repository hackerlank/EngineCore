#ifndef NEWTONDAMPER_H
#define NEWTONDAMPER_H

#include "animator.h"

/*!
 * \brief The NewtonDamper class
 */
class NewtonDamper : public Animator
{


private:
    Q_OBJECT

    float lastPosition;
    unsigned long lastTime;
    float lastVelocity;

    float targetPosition;
    float targetTime;

    float midSpeed;


protected:

    virtual void updateAnimation(unsigned long time, double elapsedTime);


public:
    NewtonDamper(float * controlValue, float midSpeed = 2);

    float getSpeed() const;
    void setSpeed(float value);

protected:
   static double calcTargetTime(double startTime, double startPosition, double targetPos, double speed);
   static double funcA(double startTime, double startPosition, double startVelocity, double targetTime, double targetPos );
   static double funcB(double startTime, double startPosition, double startVelocity, double targetTime, double targetPos );
   static double funcC(double startTime, double startPosition, double startVelocity, double targetTime, double targetPos );
   static double funcD(double startTime, double startPosition, double startVelocity, double targetTime, double targetPos );



};

#endif // NEWTONDAMPER_H
