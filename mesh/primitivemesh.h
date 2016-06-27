#ifndef PRIMITIVEMESH_H
#define PRIMITIVEMESH_H

//#include <QOpenGLBuffer>
#include "../mesh.h"
#include "../Primitives/shapedata.h"

/*!
 * \brief The PrimitiveMesh class Generates a Basic Mesh of position data from the Primitive Generated ShapeData
 * \see ShapeData
 * \see ShapeGenerator
 */
class PrimitiveMesh : public Mesh
{

public:
    /*!
     * \brief PrimitiveMesh generate the Mesh from ShapeData
     * \param shape ShapeData
     */
    explicit PrimitiveMesh(ShapeData *shape);
    ~PrimitiveMesh();

};

#endif // PRIMITIVEMESH_H
