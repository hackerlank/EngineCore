#include "renderframe.h"
#include <QWidget>
#include <QExposeEvent>
void RenderFrame::timerLoop()
{

}

RenderFrame::RenderFrame(QWindow *parent) : QWindow(parent)
{
    this->setWidth(800);
    this->setHeight(600);
    setSurfaceType(QWindow::OpenGLSurface);

    GLCreate();

    scene = NULL;
    exposed = false;

}

void RenderFrame::exposeEvent(QExposeEvent * e)
{
    if(!e->region().isEmpty())
        exposed = true;
    else
        exposed = false;

}

void RenderFrame::resizeEvent(QResizeEvent * e)
{
    QWindow::resizeEvent(e);
}

void RenderFrame::GLCreate()
{
    context = new QOpenGLContext(this);
    context->setFormat(this->format());
    context->setScreen(this->screen());
    context->create();
}

void RenderFrame::GLRender()
{
    if(scene != NULL)
        scene->Render();
}

void RenderFrame::update()
{

}
