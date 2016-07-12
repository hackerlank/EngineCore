#ifndef NORMAL3DMESH_H
#define NORMAL3DMESH_H

#include "../meshnormal.h"
#include <QFile>
/*!
 * \brief The Normal3DMesh class Creates A 3D Mesh with position data and Vertex Data from a .obj file (e.g From Blender)
 * that only contains one Object
 */
class Normal3DMesh : public MeshNormal
{
private:

    void init(QFile* objMeshFile);

public:
    /*!
     * \brief Normal3DMesh
     * \param objMeshFile QFile of the Mesh need to be opend to read
     */
    explicit Normal3DMesh(QFile* objMeshFile);

    /*!
     * \brief Normal3DMesh
     * \param file QString of tht position of the Mesh .obj file
     */
    explicit Normal3DMesh(QString file);

    virtual ~Normal3DMesh() Q_DECL_OVERRIDE;
};

#endif // NORMAL3DMESH_H
