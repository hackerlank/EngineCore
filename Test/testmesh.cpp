#include <QtTest>
#include <QCoreApplication>
#include <meshnormal.h>
#include <mesh/normal3dmesh.h>

class TestMesh : public QObject
{
    Q_OBJECT

public:
    TestMesh();
    ~TestMesh();

private:
    MeshNormal * mesh;
    QString fileName;

    QFile * file;

private slots:
    void initTestCase();

    void test_case1();

    void cleanupTestCase();

};

TestMesh::TestMesh()
{
    fileName = ":/untitled.obj";
}

TestMesh::~TestMesh()
{

}

void TestMesh::initTestCase()
{
    file = new QFile(fileName);
}

void TestMesh::test_case1()
{
    mesh = new Normal3DMesh(file);
}

void TestMesh::cleanupTestCase()
{
    delete file;
    file = NULL;
}

QTEST_MAIN(TestMesh)

#include "testmesh.moc"
