#ifndef MESHNORMAL_H
#define MESHNORMAL_H
#include "mesh.h"

/*!
 * \brief The {abstract} MeshNormal class that extends Mesh so that Meshes can now have Vertex information and Normal information in the Buffer
 */
class MeshNormal : public Mesh
{
    //Need metadata for dynamic QObject cast diffrent types of meshes
    Q_OBJECT
public:

    /*!
     * \brief The VertexNormal struct
     * New structure for the vertex data buffer
     * added normal values after each Vertex postion
     */
    struct VertexNormal : public Mesh::Vertex{
        VertexNormal(){}
        explicit VertexNormal(QVector3D v,QVector3D n) : Vertex(v), norm(n){}

        QVector3D norm;
    };

protected:
    /*!
     * \brief MeshNormal Creates a Empty Mesh
     * Subklasses implements the Mesh data input
     */
    MeshNormal() :Mesh(){
        nTupel  = 0;
        nStride = 0;
        nOffset = 0;
    }
    virtual ~MeshNormal(){}

    /*!
     * \brief nTupel Dimension of the Normal Data
     */
    int nTupel;
    /*!
     * \brief nStride distance in the buffer between Normal data
     */
    int nStride;
    /*!
     * \brief nOffset start position of the Normal data
     */
    int nOffset;


public:

    virtual inline VertexNormal* normal(){return reinterpret_cast<VertexNormal*>(pVertexData);}
    virtual inline int normalTupel(){return nTupel;}
    virtual inline int normalStride(){return nStride;}
    virtual inline int normalOffset(){return nOffset;}


    /*!
     * \brief Create the OpenGL buffer objects for This Mesh from the mesh data and sends this data to the GPU
     */
    virtual void Create() Q_DECL_OVERRIDE;

};

#endif // MESHNORMAL_H
