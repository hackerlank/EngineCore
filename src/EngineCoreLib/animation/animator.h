#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <QObject>

/*!
 * \brief The abstact Animator class controls a float value at a given address
 *
 * An animation coud be an sin-Wave or an interpolation etc..
 *
 */
class Animator : public QObject
{
    Q_OBJECT

protected:

    float * value;
    bool ownValue;

    bool isRunning;

    virtual void startAnimation(){isRunning = true;}
    virtual void stopAnimation(){isRunning = false;}
    virtual void resetAnimation(){isRunning = false;}
    virtual void updateAnimation(unsigned long time, double elapsedTime) = 0;


public:

    explicit Animator(float * controlValue = NULL) {

        isRunning = false;

        if (controlValue == NULL) {
        value = new float;
        ownValue = true;
        } else {
        value = controlValue;
        ownValue = false;
        }
    }

    ~Animator() {
        if(ownValue) {
            delete value;
            value = NULL;
        }

    }

    bool isActive(){return isRunning;}

    float getValue() const {return *value;}

public slots:


    /*!
     * \brief update updates the value at the given address according to the current system time
     * \param time application runtime
     * \param elapsedTime frametTime time since the last frame
     */
    void update(unsigned long time, double elapsedTime){

        if(isRunning)
            this->updateAnimation(time, elapsedTime);

    }

    /*!
     * \brief start starts the animation
     */
    void start() {
        startAnimation();
    }

    /*!
     * \brief stop stops the animation
     */
    void stop() {
        stopAnimation();
    }

    /*!
     * \brief reset resets the animation so that it can be started from the beginning
     */
    void reset() {
        resetAnimation();
    }
};

#endif // ANIMATOR_H
