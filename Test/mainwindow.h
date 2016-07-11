#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWindow>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QExposeEvent>
#include <QOpenGLFunctions_4_3_Core>
#include <QTimer>
#include <QElapsedTimer>
#include "../scene.h"
#include "../Animation/newtondamper.h"
class MainWindow : public QWindow, protected QOpenGLFunctions_4_3_Core
{
    Q_OBJECT

    QTimer* timer;
    QElapsedTimer *eTimer;

public:
    MainWindow();
    ~MainWindow();

    float set;
    float * ctl;
    int count;

    QOpenGLContext * context;
    NewtonDamper * damper;

    Scene * scene;

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
    void animate();

};

#endif // MAINWINDOW_H
