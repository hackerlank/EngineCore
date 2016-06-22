#include "primitivemesh.h"

PrimitiveMesh::PrimitiveMesh(ShapeData* shape)
{
    vSize = shape->numVertices;
    iSize = shape->numIndices;

    vTupel =3;
    vStride=0;
    vOffset=0;
    iStride = 0;
    iOffset = sizeof(QVector3D)*vSize;

    vertexBuffer = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    indexBuffer = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);

    pVertex = new QVector3D[vSize];
    pIndex = new GLushort[iSize];

    for (int i = 0; i<vSize; i++){
        pVertex[i]=  shape->vertices[i].position();
    }

    memcpy(pIndex, shape->indices, sizeof(GLushort)* iSize);
}




PrimitiveMesh::~PrimitiveMesh()
{
    delete [] pVertex;
    delete [] pIndex;
    pVertex = 0;
    pIndex = 0;
    vertexBuffer = 0;
    indexBuffer =0;
}
