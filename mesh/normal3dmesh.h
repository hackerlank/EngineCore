#ifndef NORMAL3DMESH_H
#define NORMAL3DMESH_H

#include "../mesh.h"
#include <QFile>

class Normal3DMesh : public Mesh
{
    void init(QFile* objMeshFile);
public:
    Normal3DMesh(QFile* objMeshFile);
    Normal3DMesh(QString file);
    ~Normal3DMesh();
};

#endif // NORMAL3DMESH_H
