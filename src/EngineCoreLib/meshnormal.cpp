#include "meshnormal.h"

void MeshNormal::Create()
{

    //Use VertexNormal not Vertex
        int bufferSizeVertex = static_cast<int>(sizeof(VertexNormal)) * vSize;
        int bufferSizeIndex  = static_cast<int>(sizeof(GLushort))  * iSize;

        Mesh::Create(bufferSizeVertex,bufferSizeIndex);

}
