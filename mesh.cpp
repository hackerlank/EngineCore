#include "mesh.h"

void Mesh::Create(int bufferSizeVertex, int bufferSizeIndex) {

       Q_CHECK_PTR(pVertexData);
       Q_CHECK_PTR(pIndex);

        this->vertexBuffer->create();
        this->indexBuffer->create();

        this->vertexBuffer->bind();
        this->vertexBuffer->setUsagePattern(QOpenGLBuffer::StaticDraw);
        this->vertexBuffer->allocate(bufferSizeVertex);
        this->vertexBuffer->write(0,pVertexData,bufferSizeVertex);
        this->vertexBuffer->release();

        this->indexBuffer->bind();
        this->indexBuffer->setUsagePattern(QOpenGLBuffer::StaticDraw);
        this->indexBuffer->allocate(bufferSizeIndex);
        this->indexBuffer->write(0,pIndex,bufferSizeIndex);
        this->indexBuffer->release();

}

void Mesh::Create() {

        int bufferSizeVertex = static_cast<int>(sizeof(Vertex)) * vSize;
        int bufferSizeIndex  = static_cast<int>(sizeof(GLushort))  * iSize;

        Mesh::Create(bufferSizeVertex,bufferSizeIndex);
}
