#include "primitivemesh.h"

PrimitiveMesh::PrimitiveMesh(ShapeData* shape)
{
    Q_CHECK_PTR(shape);

    //read shape size
    vSize = shape->numVertices;
    iSize = shape->numIndices;

    //Dens packed 3D Data
    vTupel = 3;
    vStride= 0;
    vOffset= 0;
    iStride = 0;
    iOffset = 0;

    pVertexData = new Mesh::Vertex[vSize];
    pIndex = new GLushort[iSize];

    //Copy data from shape
    for (int i = 0; i<vSize; i++){
        pVertexData[i].vert =  shape->vertices[i].position();
    }

    memcpy(pIndex, shape->indices, sizeof(GLushort)* iSize);
}




PrimitiveMesh::~PrimitiveMesh()
{
    Q_CHECK_PTR(pVertexData);
    Q_CHECK_PTR(pIndex);

    delete [] pVertexData;
    delete [] pIndex;
    pVertexData = 0;
    pIndex = 0;
}
