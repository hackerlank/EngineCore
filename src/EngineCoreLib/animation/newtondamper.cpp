#include "newtondamper.h"
#include <qmath.h>
#include <QDebug>





NewtonDamper::NewtonDamper(float * controlValue, float midSpeed) : Animator(controlValue)
{
    this->lastPosition = 0;
    this->lastTime = 0;
    this->needTargetUpdate = true;
    this->midSpeed = midSpeed;
}

void NewtonDamper::setTarget(float newValue)
{
    needTargetUpdate = true;
    targetPosition = newValue;
}


//sieht schon gut aus
// geht auch eine interpolation bei der die Geschwindichkeit erhalten bleibt beim setzen einens neuen ziels !
void NewtonDamper::updateAnimation(unsigned long time, double elapsedTime)
{
    float currentPosition = *value; //read

    double timems = static_cast<double>(time) / 1000.0;
    double elapsed = static_cast<double>(time - lastTime) / 1000.0; //elapsed in millisec

    if (needTargetUpdate) {
        targetTime = calcTargetTime(timems,currentPosition,targetPosition,midSpeed);
    }

    double a = funcA(lastTime,lastPosition,lastVelocity,targetTime,targetPosition);

    double b = funcB(lastTime,lastPosition,lastVelocity,targetTime,targetPosition);

    double c = funcC(lastTime,lastPosition,lastVelocity,targetTime,targetPosition);

    double d = funcD(lastTime,lastPosition,lastVelocity,targetTime,targetPosition);

    double nextPositon = a*(timems*timems*timems) + b*(timems*timems) + c*(timems) + d;
    double nextVelocity = (1.0/3.0) * a *(timems*timems) + 0.5*b*(timems) + c;


    this->lastPosition = nextPositon;
    this->lastVelocity = nextVelocity;
    this->lastTime = timems;
}

float NewtonDamper::getSpeed() const
{
    return midSpeed;
}

void NewtonDamper::setSpeed(float value)
{
    midSpeed = value;
}



// -- Static Calculation functions
// -- speed up when non static ??

double NewtonDamper::calcTargetTime(double startTime, double startPosition, double targetPos, double speed)
{
    if (targetPos < startPosition ) {
        speed = -speed;
    }

    double st = startTime;
    double sp = startPosition;
    double tp = targetPos;

    double a = speed;
    double b = -a *st + sp;

    double calTime = (tp-b)/a;

    return calTime;
}

double NewtonDamper::funcA(double startTime, double startPosition, double startVelocity, double targetTime, double targetPos)
{
    double a = -(-startTime*startVelocity+startVelocity*targetTime+2*startPosition-2*targetPos)/
            ((startTime*startTime*startTime)-3*(startTime*startTime)*targetTime+3*startTime*(targetTime*targetTime)-targetTime*targetTime*targetTime);

    return a;

}

double NewtonDamper::funcB(double startTime, double startPosition, double startVelocity, double targetTime, double targetPos)
{

    double part =  ((startTime-targetTime)*((startTime*startTime)-2*startTime*targetTime+(targetTime*targetTime)));

    double b = (-(startTime*startTime)*startVelocity-startTime*startVelocity*targetTime+2*startVelocity*(targetTime*targetTime)+3*startPosition*startTime+3*startPosition*targetTime-3*startTime*targetPos-3*targetPos*targetTime)
            /part;



    return b;
}

double NewtonDamper::funcC(double startTime, double startPosition, double startVelocity, double targetTime, double targetPos)
{
    double part =  ((startTime-targetTime)*((startTime*startTime)-2*startTime*targetTime+(targetTime*targetTime)));


    double c = -(-2*(startTime*startTime)*startVelocity+startTime*startVelocity*targetTime+startVelocity*(targetTime*targetTime)+6*startPosition*startTime-6*startTime*targetPos)*targetTime
            /part;

    return c;
}

double NewtonDamper::funcD(double startTime, double startPosition, double startVelocity, double targetTime, double targetPos)
{
    double part =  ((startTime-targetTime)*((startTime*startTime)-2*startTime*targetTime+(targetTime*targetTime)));


    double d = (-(startTime*startTime)*startVelocity*(targetTime*targetTime)+startTime*startVelocity*(targetTime*targetTime*targetTime)+3*startPosition*startTime*(targetTime*targetTime)-startPosition*(targetTime*targetTime*targetTime)+(startTime*startTime*startTime)*targetPos-3*(startTime*startTime)*targetPos*targetTime)
            /part;

    return d;
}
