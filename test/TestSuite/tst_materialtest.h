#ifndef TST_MATERIALTEST_H
#define TST_MATERIALTEST_H

#include <QtTest>


class MaterialTest : public QObject
{
    Q_OBJECT

public:
    MaterialTest() {

    }

private Q_SLOTS:

    void initTestCase() {

    }

    void cleanupTestCase() {

    }

    void testCase1() {
         QVERIFY2(true, "Failure");
    }

};



#endif // TST_MATERIALTEST_H
