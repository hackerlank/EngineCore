#ifndef MESH_H
#define MESH_H

#include <QObject>
#include <QOpenGLBuffer>
#include <QVector3D>
/*!
 * \brief The Mesh class Contains all vertex Information
 * abstract Interface
 */
class Mesh
{    
protected:

    Mesh(){
        vertexBuffer = NULL;
        indexBuffer = NULL;

                vSize = 0;
                iSize = 0;

                vTupel = 0;
                vStride = 0;
                vOffset = 0;

                iStride = 0;
                iOffset = 0;

                pVertex = 0;
                pIndex = 0;
          }

    QOpenGLBuffer* vertexBuffer;
    QOpenGLBuffer* indexBuffer;

    int vSize;
    int iSize;

    int vTupel;
    int vStride;
    int vOffset;

    int iStride;
    int iOffset;

    QVector3D* pVertex;
    GLushort * pIndex;

public:

    virtual int vertexSize(){return vSize;}
    virtual int  indexSize(){return iSize;}

    virtual float* vertex(){return (float*) pVertex;}
    virtual int vertexTupel(){return vTupel;}
    virtual int vertexStride(){return vStride;}
    virtual int vertexOffset(){return vOffset;}

    virtual GLushort* indecies(){return pIndex;}
    virtual int  indexStride(){return iStride;}
    virtual int  indexOffset(){return iOffset;}

    virtual void bind()    {vertexBuffer->bind(); indexBuffer->bind();}
    virtual void release() {vertexBuffer->release(); indexBuffer->bind();}

    /*!
     * \brief Create the OpenGL buffer objects for This Mesh from the mesh data and sends this data to the GPU
     */
    virtual void Create()
    {
        int bufferSizeVertex = sizeof(QVector3D) * vSize;
        int bufferSizeIndex = sizeof(GLushort) * iSize;

        this->vertexBuffer->create();
        this->indexBuffer->create();

        this->vertexBuffer->bind();
        this->vertexBuffer->setUsagePattern(QOpenGLBuffer::StaticDraw);
        this->vertexBuffer->allocate(bufferSizeVertex);
        this->vertexBuffer->write(0,pVertex,bufferSizeVertex);
        this->vertexBuffer->release();

        this->indexBuffer->bind();
        this->indexBuffer->setUsagePattern(QOpenGLBuffer::StaticDraw);
        this->indexBuffer->allocate(bufferSizeIndex);
        this->indexBuffer->write(0,pIndex,bufferSizeIndex);
        this->indexBuffer->release();
    }

    /*!
     * \brief Destroy Removes the OpenGL buffers for this Mesh from the GPU
     */
    virtual void Destroy()
    {
        this->vertexBuffer->destroy();
        this->indexBuffer->destroy();
    }

};

#endif // MESH_H
