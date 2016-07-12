#include "renderable.h"
#include <QMatrix4x4>
Renderable::Renderable(QOpenGLContext *context, const QMatrix4x4* pWorld, const QString strName, QObject *parent)
    : QObject(parent) , name(strName)
{
   contextDevice = context;

   if(pWorld) matWorld =new QMatrix4x4(*pWorld);
   else matWorld = new QMatrix4x4();
}

QMatrix4x4 *Renderable::getWorldMatrix()
{
    return matWorld;
}

void Renderable::setWorldMatrix(const QMatrix4x4& nWorld)
{
    *matWorld = nWorld;
}
