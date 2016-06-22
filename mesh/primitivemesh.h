#ifndef PRIMITIVEMESH_H
#define PRIMITIVEMESH_H

//#include <QOpenGLBuffer>
#include "../mesh.h"
#include "../Primitives/shapedata.h"

class PrimitiveMesh : public Mesh
{

public:
    explicit PrimitiveMesh(ShapeData *shape);
    ~PrimitiveMesh();

};

#endif // PRIMITIVEMESH_H
