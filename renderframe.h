#ifndef RENDERFRAME_H
#define RENDERFRAME_H

#include <QWidget>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QExposeEvent>
#include <QTimer>
#include <QElapsedTimer>
#include <QOpenGLFunctions_3_3_Core>

#include "scene.h"

class RenderFrame : public QWidget , protected QOpenGLFunctions
{
    Q_OBJECT

    QOpenGLContext * context;
    Scene * scene;

    QTimer timer;
    QElapsedTimer timerDelta;
    unsigned long currentMs;

private slots:
    void timerLoop();


public:
    explicit RenderFrame(QWidget *parent = 0);




protected:
    virtual void exposeEvent(QExposeEvent *);
    virtual void resizeEvent(QResizeEvent *);


 //   virtual void mousePressEvent(QMouseEvent * e);
 //   virtual void mouseMoveEvent(QMouseEvent * e);
 //   virtual void mouseReleaseEvent(QMouseEvent *e);

public:
    void create();

public slots:
    void update();
};

#endif // RENDERFRAME_H
