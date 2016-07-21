#include "sinewave.h"


SineWave::SineWave(float *control,  float waveSpeed ,float amp) : Animator(control)
{
    this->amplitude = amp;
    this->waveSpeed = waveSpeed / 100.0;
    this->restated = true;
}


void SineWave::updateAnimation(unsigned long time, double elapsedTime)
{
    if (restated) {
        this->startTime = time;
        this->restated = false;
    }

    double timems = (time - startTime) / 1000.0;

    *value = sin( timems * speed) * amplitude;
}

void SineWave::resetAnimation()
{
    Animator::resetAnimation();
    restated = true;
}

void SineWave::startAnimation()
{
    Animator::startAnimation();
    if (!isRunning) {
        restated = true;
    }
}
