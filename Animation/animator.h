#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <QObject>


class Animator : public QObject
{
    Q_OBJECT

protected:

    float * value;

    bool isRunning;

    virtual void startAnimation(){isRunning = true;}
    virtual void stopAnimation(){isRunning = false;}
    virtual void resetAnimation(){isRunning = false;}
    virtual void updateAnimation(unsigned long time, double elapsedTime) = 0;

public:

    Animator(float * controlValue) {

        isRunning = false;
        value = controlValue;

    }

    bool isActive(){return isRunning;}

public slots:
    void update(unsigned long time, double elapsedTime){

        if(isRunning)
            this->updateAnimation(time, elapsedTime);

    }

    void start() {
        startAnimation();
    }

    void stop() {
        stopAnimation();
    }

    void reset() {
        resetAnimation();
    }
};

#endif // ANIMATOR_H
