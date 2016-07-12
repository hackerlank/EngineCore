#include "normal3dmesh.h"
#include <QVector>
#include <QVector3D>
#include <QVector2D>
#include <qopengl.h>
#include <QStringList>
#include <QByteArray>
#include <QDebug>

void Normal3DMesh::init(QFile *objMeshFile)
{

    Q_CHECK_PTR(objMeshFile);



    QString name;
    QVector<GLushort> inIndeciesVert;
    QVector<GLushort> inIndeciesNorm;
    QVector<GLushort> inIndeciesUV;
    QVector<VertexNormal> inVertex;
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
            inVertex.append(VertexNormal(QVector3D(cmd.at(1).toFloat(),cmd.at(2).toFloat(),cmd.at(3).toFloat()),QVector3D()));
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

                inIndeciesVert.append(fList.at(0).toInt()-1);

                if(fList.size() > 2) { // Texture and Normal Mode

                inVertex[fList.at(0).toInt()-1].norm = inNormal.at(fList.at(2).toInt()-1);

                } else if(fList.size() > 1) {//Normal only mode

                inVertex[fList.at(0).toInt()-1].norm = inNormal.at(fList.at(1).toInt()-1);

                }
                }
            }





    }while(in.size() > 0);

    iSize = inIndeciesVert.size();
    vSize = inVertex.size();


    vTupel =3;
    vStride= sizeof(VertexNormal);
    vOffset=0;
    nTupel = 3;
    nStride = sizeof(VertexNormal);
    nOffset = sizeof(Vertex);
    iStride = 0;
    iOffset = 0;

    pVertexData = new MeshNormal::VertexNormal[vSize];
    pIndex = new GLushort[iSize];

    memcpy(pVertexData,inVertex.data(), (sizeof(VertexNormal)) * static_cast<GLuint>(vSize));
    memcpy(pIndex,inIndeciesVert.data(),(sizeof(GLushort))  * static_cast<GLuint>(iSize));
}

Normal3DMesh::Normal3DMesh(QFile *objMeshFile)
{
    if(!objMeshFile->isOpen()) {

        if(!objMeshFile->open(QFile::ReadOnly)) {
            qWarning() << objMeshFile->errorString();
        }
        else {
            init(objMeshFile);
        }
   }


}

Normal3DMesh::Normal3DMesh(QString filename)
{
    QFile file(filename);


    if(!file.open(QFile::ReadOnly)) {
        qWarning() << file.errorString();
    }
    else {
        init(&file);
    }


}

Normal3DMesh::~Normal3DMesh()
{
    delete [] pVertexData;
    delete [] pIndex;
    pVertexData = 0;
    pIndex = 0;
}
