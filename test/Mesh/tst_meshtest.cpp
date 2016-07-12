#include <QtTest>

#include "mesh.h"
#include "meshnormal.h"
#include "mesh/normal3dmesh.h"

class MeshTest : public QObject
{
    Q_OBJECT

public:
    MeshTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

MeshTest::MeshTest()
{
}

void MeshTest::initTestCase()
{
}

void MeshTest::cleanupTestCase()
{
}

void MeshTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(MeshTest)

#include "tst_meshtest.moc"
