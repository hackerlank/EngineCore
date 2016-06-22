#ifndef MESHNORMAL_H
#define MESHNORMAL_H
#include "mesh.h"


class MeshNormal : public Mesh
{
    Q_OBJECT
public:

    struct VertexNormal : public Mesh::Vertex{
        VertexNormal(){};
        explicit VertexNormal(QVector3D v,QVector3D n) : Vertex(v), norm(n){};

        QVector3D norm;
    };

protected:
    MeshNormal(){
        nTupel  = 0;
        nStride = 0;
        nOffset = 0;
    }
    virtual ~MeshNormal(){}
    int nTupel;
    int nStride;
    int nOffset;


public:

    virtual inline VertexNormal* normal(){return reinterpret_cast<VertexNormal*>(pVertexData);}
    virtual inline int normalTupel(){return nTupel;}
    virtual inline int normalStride(){return nStride;}
    virtual inline int normalOffset(){return nOffset;}


    /*!
     * \brief Create the OpenGL buffer objects for This Mesh from the mesh data and sends this data to the GPU
     */
    virtual void Create();

};

#endif // MESHNORMAL_H
