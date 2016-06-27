#include "renderframe.h"

RenderFrame::RenderFrame(QWidget *parent) : QWidget(parent)
{
    this->setWidth(800);
    this->setHeight(600);
    setSurfaceType(QWindow::OpenGLSurface);

    context = new QOpenGLContext(this);
    context->setFormat(this->format());
    context->setScreen(this->screen());
    context->create();

    scene = NULL;

}
