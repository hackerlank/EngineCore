#ifndef RENDEROFFSCREEN_H
#define RENDEROFFSCREEN_H

#include <QOffscreenSurface>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLFramebufferObject>

class RenderOffScreen : public QOffscreenSurface , public QOpenGLFunctions_3_3_Core
{
    QOpenGLFramebufferObject * frameBuffer;

public:
    RenderOffScreen();
};

#endif // RENDEROFFSCREEN_H
