#ifndef MESH_H
#define MESH_H

#include <QObject>
#include <QOpenGLBuffer>
#include <QVector3D>
/*!
 * \brief The {abstract} Mesh class Contains all 3D Vertex Information
 */
class Mesh : public QObject
{    

   //Need metadata for dynamic QObject cast diffrent types of meshes
   Q_OBJECT

protected:

    /*!
     * \brief The Vertex struct
     * Definds the structure Data of a Vertex used in a Mesh
     */
    struct Vertex {
        /*!
         * \brief Vertex Creates a vertex with 0 values
         */
        Vertex(){}
        /*!
         * \brief Vertex Creates a vertex with a given position
         * \param v the position of the vertex
         */
        explicit Vertex(QVector3D v) : vert(v){}
        QVector3D vert;
    };

    /*!
     * \brief Mesh <<protected>> Create a Empty Mesh
     */
    Mesh(){
        vertexBuffer = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
        indexBuffer = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
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
    virtual ~Mesh(){

        delete vertexBuffer;
        delete indexBuffer;
        vertexBuffer = NULL;
        indexBuffer =NULL;

    }

    QOpenGLBuffer* vertexBuffer;
    QOpenGLBuffer* indexBuffer;

    /*!
     * \brief vSize size off the Vertex Data.
     * the cout of Vertex in the pVertexData array
     */
    int vSize;
    /*!
     * \brief iSize size off the Index Data.
     * the cout of Indecies in the pIndex array
     */
    int iSize;


    /*!
     * \brief vTupel count of the values in a Vertex so the Dimension of the vertex eg 2, 3 or 4 ...
     */
    int vTupel;
    /*!
     * \brief vStride the distance between 2 Vertex data in the Buffer
     */
    int vStride;
    /*!
     * \brief vOffset the Position where the the data begins in the Buffer
     */
    int vOffset;


    int iStride;
    int iOffset;

    /*!
     * \brief pVertexData put your Vertex Data here to write this data to the GPU at Create()
     */
    Vertex* pVertexData;
    /*!
     * \brief pIndex put yout IndexData here to wirte this data to the GPU at Create();
     */
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
