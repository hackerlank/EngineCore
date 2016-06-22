#include "normal3dmesh.h"
#include <QVector>
#include <QVector3D>
#include <QVector2D>
#include <qopengl.h>
#include <QStringList>


void Normal3DMesh::init(QFile *objMeshFile)
{

    vertexBuffer = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    indexBuffer = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);

    QString name;
    QVector<GLushort> inIndeciesVert;
    QVector<GLushort> inIndeciesNorm;
    QVector<GLushort> inIndeciesUV;
    QVector<QVector3D> inVertex;
    QVector<QVector3D> inNormal;
    QVector<QVector2D> inUV;

    QByteArray in;
    QString data;
    QStringList cmd;

    do
    {

        in = objMeshFile->readLine();

        if(in.isEmpty())
            break;
        if(in.at(0) == '#')
            continue;


        data =  QString::fromStdString(in.toStdString());
        data.remove("\n");
        cmd = data.split(" ",QString::SkipEmptyParts);



        if (cmd.first() == "o") {
            //add object name
            if(name.isEmpty()){
                name = cmd.last();
            }
            else break;
            //read only one object exit at the second object

        } else if (cmd.first() == "v") {
            //add vertex
            inVertex.append(QVector3D(cmd.at(1).toFloat(),cmd.at(2).toFloat(),cmd.at(3).toFloat()));
        } else if (cmd.first() == "vn") {
            //add vertex normal
            inNormal.append(QVector3D(cmd.at(1).toFloat(),cmd.at(2).toFloat(),cmd.at(3).toFloat()));
        } else if (cmd.first() == "vt") {
            inUV.append(QVector2D(cmd.at(1).toFloat(),cmd.at(2).toFloat()));
        } else if (cmd.first() == "f") {
            cmd.removeFirst();

            QStringList fList;
            foreach (QString face, cmd) {
                fList = face.split("/",QString::SkipEmptyParts);
                inIndeciesVert.append(fList.at(0).toInt());
                if(fList.size() > 1) {
                    inIndeciesNorm.append(fList.at(1).toInt());
                    if(fList.size() > 2) {
                        inIndeciesUV.append(fList.at(2).toInt());
                    }
                }
            }

        }



    }while(in.size() > 0);

    iSize = inIndeciesVert.size();
    vSize = inVertex.size();


    vTupel =3;
    vStride=0;
    vOffset=0;
    iStride = 0;
    iOffset = sizeof(QVector3D)*vSize;

    pVertex = new QVector3D[vSize];
    pIndex = new GLushort[iSize];

    memcpy(pVertex,inVertex.data(),sizeof(QVector3D) * vSize);
    memcpy(pIndex,inIndeciesVert.data() , sizeof(GLushort)* iSize);
}

Normal3DMesh::Normal3DMesh(QFile *objMeshFile)
{
    init(objMeshFile);
}

Normal3DMesh::Normal3DMesh(QString filename)
{
    QFile file(filename);

    file.open(QFile::ReadOnly);
    init(&file);
}

Normal3DMesh::~Normal3DMesh()
{
    delete [] pVertex;
    delete [] pIndex;
    delete vertexBuffer;
    delete indexBuffer;
    pVertex = 0;
    pIndex = 0;
    vertexBuffer = 0;
    indexBuffer =0;
}
