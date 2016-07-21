#ifndef SINEWAVE_H
#define SINEWAVE_H

#include "animator.h"


class SineWave : public Animator
{
    Q_OBJECT

    float amplitude;
    float waveSpeed;
    unsigned long startTime;

    bool restated;
protected:


    virtual void updateAnimation(unsigned long time, double elapsedTime);
    virtual void resetAnimation();
    virtual void startAnimation();


public:
    explicit SineWave(float *  control, float waveSpeed = 100.0 , float amplitud = 1.0);
};

#endif // SINEWAVE_H
