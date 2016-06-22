#ifndef MESH_H
#define MESH_H

#include <QObject>
#include <QOpenGLBuffer>
#include <QVector3D>
/*!
 * \brief The Mesh class Contains all vertex Information
 * abstract Interface
 */
class Mesh : public QObject
{    

    Q_OBJECT
protected:

    struct Vertex {
        Vertex(){}
        explicit Vertex(QVector3D v) : vert(v){}

        QVector3D vert;
    };

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
        pVertexData = NULL;
        pIndex = NULL;
    }
    virtual ~Mesh(){}

    QOpenGLBuffer* vertexBuffer;
    QOpenGLBuffer* indexBuffer;

    int vSize;
    int iSize;

    int vTupel;
    int vStride;
    int vOffset;

    int iStride;
    int iOffset;

    Vertex* pVertexData;
    GLushort * pIndex;

public:

    virtual inline int vertexSize(){return vSize;}
    virtual inline int  indexSize(){return iSize;}

    virtual inline Vertex* vertex(){return (pVertexData);}
    virtual inline int vertexTupel(){return vTupel;}
    virtual inline int vertexStride(){return vStride;}
    virtual inline int vertexOffset(){return vOffset;}

    virtual inline GLushort* indecies(){return pIndex;}
    virtual inline int  indexStride(){return iStride;}
    virtual inline int  indexOffset(){return iOffset;}

    virtual inline void bind()    {vertexBuffer->bind(); indexBuffer->bind();}
    virtual inline void release() {vertexBuffer->release(); indexBuffer->bind();}

    /*!
     * \brief Create the OpenGL buffer objects for This Mesh from the mesh data and sends this data to the GPU
     */
    virtual void Create();


    /*!
     * \brief Destroy Removes the OpenGL buffers for this Mesh from the GPU
     */
    virtual inline void Destroy()
    {
        this->vertexBuffer->destroy();
        this->indexBuffer->destroy();
    }

};

#endif // MESH_H
