#include "mesh.h"

void Mesh::Create(){

        int bufferSizeVertex = static_cast<int>(sizeof(QVector3D)) * vSize;
        int bufferSizeIndex  = static_cast<int>(sizeof(GLushort))  * iSize;

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
