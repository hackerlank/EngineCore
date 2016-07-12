
#include <QtTest>

#include "mesh.h"
#include "meshnormal.h"
#include "mesh/normal3dmesh.h"

class MeshTest : public QObject {

     Q_OBJECT

    QString* fileNames;
    QString primaryFile;


    QFile * file;

    MeshNormal * mesh;


public:
    MeshTest() {

        fileNames = new QString[2];
        fileNames[0] = ":/box.obj";
        fileNames[1] = ":/torus.obj";


        primaryFile = fileNames[0];

        file = NULL;
        mesh = NULL;

    }


private Q_SLOTS:

    void initTestCase() {

        file = new QFile(primaryFile);


        file->open(QFile::ReadOnly);
        mesh = new Normal3DMesh(file);
        file->close();

    }

    void cleanupTestCase() {

        delete file;
        delete mesh;

        file = NULL;
        mesh = NULL;

    }

    void testFormat() {

        const int normalDimension = 3;
        const int normalOffset = static_cast<int>(sizeof(QVector3D));
        const int normalStride = static_cast<int>(sizeof(QVector3D)) * 2;

        const int vertexDimension = 3;
        const int vertexOffset = 0;
        const int vertexStride = normalStride;

        const int indexStride = 0;
        const int indexOffset = 0;

        QCOMPARE(mesh->normalTupel(),  normalDimension);
        QCOMPARE(mesh->normalOffset(), normalOffset);
        QCOMPARE(mesh->normalStride(), normalStride);

        QCOMPARE(mesh->vertexTupel(),  vertexDimension);
        QCOMPARE(mesh->vertexOffset(), vertexOffset);
        QCOMPARE(mesh->vertexStride(), vertexStride);

        QCOMPARE(mesh->indexStride(), indexStride);
        QCOMPARE(mesh->indexOffset(), indexOffset);

    }

    void testSize() {

        int countVertex = 0;
        int countNormal = 0;
        int countIndex = 0;
        int countOther = 0;

        QFile local(primaryFile);
        local.open(QFile::ReadOnly);

        QByteArray in;
        do
        {

            in = local.readLine();

            if(in.isEmpty())
                break;


            QString data =  QString::fromStdString(in.toStdString());
            data.remove("\n");
            QStringList cmd = data.split(" ",QString::SkipEmptyParts);

            if(cmd.first() == "v") {
                countVertex++;
            } else if(cmd.first() == "vn") {
                countNormal++;
            } else if(cmd.first() == "f") {
                cmd.removeFirst();
                countIndex += cmd.size();
            } else {
                countOther++;
            }

        }while(in.size() > 0);

        file->close();

        QCOMPARE(mesh->vertexSize(), countVertex);
        QCOMPARE(mesh->indexSize(), countIndex);

    }

    void testAltSize() {

        primaryFile = fileNames[1];

        delete mesh;

        this->initTestCase();

        this->testFormat();

    }

};
