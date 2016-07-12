#include <QCoreApplication>

#include <QtTest>
#include <QVector>

#include "tst_materialtest.h"
#include "tst_meshtest.h"

#define TEST_ADD(TestClass) (tests.append(new TestClass))

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<QObject *> tests;


    TEST_ADD(MaterialTest);
    TEST_ADD(MeshTest);


    int ret = 0;
    foreach (QObject* test, tests) {
        ret = ret | QTest::qExec(test);
    }

    return ret;


}
