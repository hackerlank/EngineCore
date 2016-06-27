#include "mainwindow.h"
#include <QDebug>
#include "../material.h"
#include "../entity.h"
#include "../mesh/normal3dmesh.h"

MainWindow::MainWindow()
    : QWindow()
{
    this->setWidth(800);
    this->setHeight(600);
    setSurfaceType(QWindow::OpenGLSurface);

    context = new QOpenGLContext(this);
    context->setFormat(this->format());
    context->setScreen(this->screen());
    context->create();

    scene = new Scene(context,this);

    Material * generalMat = new Material(context,":/vertex.vert",":/fragment.frag",scene);
    scene->addMaterial(generalMat);

    QMatrix4x4 w;
    w.translate(-0.7,0,-2);
    w.rotate(60.0f,0,1);
    Entity * ent = new Entity(new Normal3DMesh(":/untitled.obj"),generalMat,context,&w,"Torus",scene);
    w = QMatrix4x4();
    w.rotate(1,.8,0.1,0);
    ent->setAnimationMatrix(w);
    scene->addRenderable(ent);

    w = QMatrix4x4();
    w.scale(0.7);
    w.translate(0.5,-0.3,-3);
    w.rotate(-60.0f,0,1);
    ent = new Entity(new Normal3DMesh(":/untitled2.obj"),generalMat,context,&w,"Mesh",scene);
    w = QMatrix4x4();
    w.rotate(1,.1,.9,0);
    ent->setAnimationMatrix(w);
    scene->addRenderable(ent);

    w = QMatrix4x4();
    w.scale(1);
    w.translate(0.0,-0.5,-3);
    ent = new Entity(new Normal3DMesh(":/untitled3.obj"),generalMat,context,&w,"Plane",scene);
    scene->addRenderable(ent);


    timer = new QTimer();
    eTimer = new QElapsedTimer();

    timer->singleShot(20,this,SLOT(update()));
    eTimer->start();

}

MainWindow::~MainWindow()
{
    scene->Destroy();
    context->deleteLater();
    delete scene;
}

void MainWindow::exposeEvent(QExposeEvent *)
{
    if(this->isExposed())
        this->update();
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    scene->camera()->updateRatio(width(),height());
}

void MainWindow::create()
{
    QWindow::create();

    context->makeCurrent(this);

    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    scene->Create();

    scene->light()->setAmbientColor(QVector3D(1.0f,0.8f,0.9f));
    scene->light()->setDiffuseColor(QVector3D(1.0f,0.8f,0.9f));
   QVector3D dir = QVector3D(0,+3,0);
   dir.normalize();
    scene->light()->setDirection(dir);
}

void MainWindow::update()
{
    scene->update(0.0,eTimer->elapsed()/1000.0);
    eTimer->restart();

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)  ;
    glViewport(0,0,this->width(),this->height());

    scene->Render();

    context->swapBuffers(this);

    timer->singleShot(20,this,SLOT(update()));
}
