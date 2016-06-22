#include "primitivemesh.h"

PrimitiveMesh::PrimitiveMesh(ShapeData* shape)
{
    vSize = shape->numVertices;
    iSize = shape->numIndices;

    vTupel = 3;
    vStride= 0;
    vOffset= 0;
    iStride = 0;
    iOffset = 0;

    vertexBuffer = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    indexBuffer = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);

    pVertexData = new Mesh::Vertex[vSize];
    pIndex = new GLushort[iSize];

    for (int i = 0; i<vSize; i++){
        pVertexData[i].vert =  shape->vertices[i].position();
    }

    memcpy(pIndex, shape->indices, sizeof(GLushort)* iSize);
}




PrimitiveMesh::~PrimitiveMesh()
{
    delete [] pVertexData;
    delete [] pIndex;
    pVertexData = 0;
    pIndex = 0;
    vertexBuffer = 0;
    indexBuffer =0;
}
