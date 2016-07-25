#ifndef TST_NEWTOWNDAMPER_H
#define TST_NEWTOWNDAMPER_H

#include <QtTest>
#include <QDebug>
#include <qmath.h>
#include <limits.h>
#include <string>
#include "animation/newtondamper.h"

#define DELTA 0.00001

class NewtonDamperTest :  public NewtonDamper{

     Q_OBJECT


    float * testValue;
    NewtonDamper * testNewtonDamper;

public:
    NewtonDamperTest() :  NewtonDamper(new float,5) {


    }

    ~NewtonDamperTest(){
    }


private Q_SLOTS:

    void init() {

    testValue = new float;
    testNewtonDamper = new NewtonDamper(testValue);

    }

    void cleanup() {

        delete testNewtonDamper;
        testNewtonDamper = NULL;
        delete testValue;
        testValue = NULL;

    }

    void testUpdateNoTarget() {
        testNewtonDamper->start();

        testNewtonDamper->update(10,0.10);

        QVERIFY2(qFuzzyCompare(*testValue,0.0f), "Zero error");

        testNewtonDamper->update(12,2.0);

        QVERIFY2(qFuzzyCompare(*testValue,0.0f), "Zero error");

    }

    void testUpdateSimple() {
        const float target = 2.0f;
        const float speed  = 2.0f;

        testNewtonDamper->start();
        testNewtonDamper->setTarget(target);
        testNewtonDamper->setSpeed(speed);

        testNewtonDamper->update(0,0);

        testNewtonDamper->update(1000,2.0);

        //qInfo() << "Value: " << *testValue << " Speed: " << testNewtonDamper->getSpeed();

        QVERIFY2(qFuzzyCompare(*testValue,2.0f), "Zero error");

    }

    void testUpdateMidChange() {
        const float target = 4.0f;
        const float speed  = 2.0f;

        testNewtonDamper->start();
        testNewtonDamper->setTarget(target);
        testNewtonDamper->setSpeed(speed);


        //qInfo() << "Value: " << *testValue << " Speed: " << testNewtonDamper->getCurrentSpeed();

        for(int i = 0; i<= 1000; i+=10) {
            testNewtonDamper->update(i,0);
          //  qInfo() << "Value: " << *testValue << " Speed: " << testNewtonDamper->getCurrentSpeed();

        }

        QVERIFY2(qFuzzyCompare(*testValue,2.0f), "Value error");


        testNewtonDamper->setTarget(1.5f);


        //qInfo() << "Value: " << *testValue << " Speed: " << testNewtonDamper->getCurrentSpeed();

        for(int i = 1000; i<= 1250; i+=10) {
            testNewtonDamper->update(i,0);
          //  qInfo() << "Value: " << *testValue << " Speed: " << testNewtonDamper->getCurrentSpeed();

        }


        QVERIFY2(qFuzzyCompare(*testValue,1.5f), "Value error");

    }

    void testUpdateOverTime() {
        const float target = 4.0f;
        const float speed  = 2.0f;

        testNewtonDamper->start();
        testNewtonDamper->setTarget(target);
        testNewtonDamper->setSpeed(speed);


        //qInfo() << "Value: " << *testValue << " Speed: " << testNewtonDamper->getCurrentSpeed();

        for(int i = 0; i<= 1000; i+=10) {
            testNewtonDamper->update(i,0);
          //  qInfo() << "Value: " << *testValue << " Speed: " << testNewtonDamper->getCurrentSpeed();

        }

        QVERIFY2(qFuzzyCompare(*testValue,2.0f), "Value error");


        for(int i = 1000; i<= 3000; i+=10) {
            testNewtonDamper->update(i,0);
          //  qInfo() << "Value: " << *testValue << " Speed: " << testNewtonDamper->getCurrentSpeed();

        }


        QVERIFY2(qFuzzyCompare(*testValue,4.0f), "Value error");

    }



    /*!
     * Test static func for the calculation of a
     *
     * Values are pre Calculated
     *
     * \brief testAcalc1
     */
    void testAcalc1() {

        const float solution = -(18.0/125.0);

        const float startTim = 1.0;
        const float startPos = 242.0/125.0;
        const float startVel = 216.0/125.0;
        const float targetTim = 5.0;
        const float targetPos = 10.0;

        float a = this->funcA(startTim , startPos , startVel ,targetTim ,targetPos );

        QString msg = QString("calc: ") + QString::number(a) + QString(" sol: ") + QString::number(solution) ;
        QVERIFY2(qFuzzyCompare(a , solution), qPrintable(msg));

    }

    /*!
     * Test static func for the calculation of a
     *
     * Values are pre Calculated
     *
     * \brief testAcalc2
     */
    void testAcalc2() {

        const double solution = -125882.0/4492125.0;

        const double startTim = 3;
        const double startPos = 3.0/125.0;
        const double startVel = 64.0/125.0;
        const double targetTim =36.0;
        const double targetPos = 512.0;

        double a = this->funcA(startTim , startPos , startVel ,targetTim ,targetPos );

        QString msg = QString("calc: ") + QString::number(a) + QString(" sol: ") + QString::number(solution) ;
        QVERIFY2(qFuzzyCompare(a , solution) , qPrintable(msg));

    }

    void testBcalc1() {

        const double solution = (27.0/25.0);

        const double startTim = 1.0;
        const double startPos = 242.0/125.0;
        const double startVel = 216.0/125.0;
        const double targetTim = 5.0;
        const double targetPos = 10.0;

        double b = this->funcB(startTim , startPos , startVel ,targetTim ,targetPos );


        QString msg = QString("calc: ") + QString::number(b) + QString(" sol: ") + QString::number(solution) ;
        QVERIFY2(qFuzzyCompare(b , solution), qPrintable(msg));

    }

    void testBcalc2() {

        const double solution = 814361.0/499125.0;

        const double startTim = 3;
        const double startPos = 3.0/125.0;
        const double startVel = 64.0/125.0;
        const double targetTim =36.0;
        const double targetPos = 512.0;

        double b = this->funcB(startTim , startPos , startVel ,targetTim ,targetPos );


        QString msg = QString("calc: ") + QString::number(b) + QString(" sol: ") + QString::number(solution) ;
        QVERIFY2(qFuzzyCompare(b , solution), qPrintable(msg));


    }

    void testCcalc1() {

        const double solution = 0.0;

        const double startTim = 1.0;
        const double startPos = 242.0/125.0;
        const double startVel = 216.0/125.0;
        const double targetTim = 5.0;
        const double targetPos = 10.0;

        double c = this->funcC(startTim , startPos , startVel ,targetTim ,targetPos );


        QString msg = QString("calc: ") + QString::number(c) + QString(" sol: ") + QString::number(solution) ;
        QVERIFY2(qFuzzyCompare(c , solution) , qPrintable(msg));


    }

    void testCcalc2() {

        const double solution = -1417656.0/166375.0;

        const double startTim = 3;
        const double startPos = 3.0/125.0;
        const double startVel = 64.0/125.0;
        const double targetTim =36.0;
        const double targetPos = 512.0;

        double c = this->funcC(startTim , startPos , startVel ,targetTim ,targetPos );


        QString msg = QString("calc: ") + QString::number(c) + QString(" sol: ") + QString::number(solution) ;
        QVERIFY2(qFuzzyCompare(c , solution) , qPrintable(msg));


    }

    void testDcalc1() {

        const double solution = 1.0;

        const double startTim = 1.0;
        const double startPos = 242.0/125.0;
        const double startVel = 216.0/125.0;
        const double targetTim = 5.0;
        const double targetPos = 10.0;

        double d = this->funcD(startTim , startPos , startVel ,targetTim ,targetPos );

        QString msg = QString("calc: ") + QString::number(d) + QString(" sol: ") + QString::number(solution) ;
        QVERIFY2(qFuzzyCompare(d , solution) , qPrintable(msg));


    }

    void testDcalc2() {

        const double solution = 387952.0/33275.0;

        const double startTim = 3;
        const double startPos = 3.0/125.0;
        const double startVel = 64.0/125.0;
        const double targetTim =36.0;
        const double targetPos = 512.0;

        double d = this->funcD(startTim , startPos , startVel ,targetTim ,targetPos );

        QString msg = QString("calc: ") + QString::number(d) + QString(" sol: ") + QString::number(solution) ;
        QVERIFY2(qFuzzyCompare(d , solution) , qPrintable(msg));

    }
    void testTargetCalc1() {

        const double solution = 1.0;

        const double startTim = 0.0;
        const double startPos = 3.0;
        const double targetPos = 4.0;
        const double speed = 1.0;

        double targetTimeErg = this->calcTargetTime(startTim,startPos,targetPos,speed);

        QString msg = QString("clac: ") + QString::number(targetTimeErg) + QString(" sol: ") + QString::number(solution);

        QVERIFY2(qFuzzyCompare(targetTimeErg, solution), qPrintable(msg));


    }

    void testTargetCalc2() {

        const double solution = 5.0;

        const double startTim = 4.0;
        const double startPos = 3.0;
        const double targetPos = 6.0;
        const double speed = 3.0;

        double targetTimeErg = this->calcTargetTime(startTim,startPos,targetPos,speed);

        QString msg = QString("clac: ") + QString::number(targetTimeErg) + QString(" sol: ") + QString::number(solution);

        QVERIFY2(qFuzzyCompare(targetTimeErg, solution), qPrintable(msg));


    }

    void testTargetCalc3() {

        const double solution = 6.0;

        const double startTim = 3.0;
        const double startPos = 1.5;
        const double targetPos = 0.0;
        const double speed = 0.5;

        double targetTimeErg = this->calcTargetTime(startTim,startPos,targetPos,speed);

        QString msg = QString("clac: ") + QString::number(targetTimeErg) + QString(" sol: ") + QString::number(solution);

        QVERIFY2(qFuzzyCompare(targetTimeErg, solution), qPrintable(msg));


    }


};


#endif // TST_NEWTOWNDAMPER_H
