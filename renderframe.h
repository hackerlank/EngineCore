#ifndef RENDERFRAME_H
#define RENDERFRAME_H

#include <QWindow>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QExposeEvent>
#include <QTimer>
#include <QElapsedTimer>
#include <QOpenGLFunctions_3_3_Core>

#include "scene.h"

/*!
 * \brief The RenderFrame a QWidget with OpenGl Renderring and a TimerLoop
 */
class RenderFrame : public QWindow , protected QOpenGLFunctions
{
    Q_OBJECT

    QOpenGLContext * context;
    Scene * scene;

    QTimer timer;
    QElapsedTimer timerDelta;
    unsigned long currentMs;

    bool exposed;

private slots:
    void timerLoop();


public:
    explicit RenderFrame(QWindow *parent = 0);

    void setScene(Scene * scene) {this->scene = scene;}
    Scene * getScene() {return scene;}



protected:
    virtual void exposeEvent(QExposeEvent *);

    virtual void resizeEvent(QResizeEvent *);

    virtual void GLCreate();




public:
    virtual void GLRender();
    void create();

public slots:
    void update();
};

#endif // RENDERFRAME_H
