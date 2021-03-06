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
    double lastTime;
    float lastVelocity;

    float targetPosition;
    float targetTime;
    bool needTargetUpdate;

    float midSpeed;

    double a ,b ,c ,d;


protected:


    virtual void updateAnimation(unsigned long time, double elapsedTime);


public:
    NewtonDamper(float * controlValue, float midSpeed = 2);

    /*!
     * \brief setTarget sets a new Animation target position
     * \param newValue
     */
    virtual void setTarget(float newValue);
    float getSpeed() const;

    float getCurrentSpeed() const{ return lastVelocity;}


    void setSpeed(float value);

protected:
   static double calcTargetTime(double startTime, double startPosition, double targetPos, double speed);
   static double funcA(double startTime, double startPosition, double startVelocity, double targetTime, double targetPos );
   static double funcB(double startTime, double startPosition, double startVelocity, double targetTime, double targetPos );
   static double funcC(double startTime, double startPosition, double startVelocity, double targetTime, double targetPos );
   static double funcD(double startTime, double startPosition, double startVelocity, double targetTime, double targetPos );



};

#endif // NEWTONDAMPER_H
