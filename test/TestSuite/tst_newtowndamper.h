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


public:
    NewtonDamperTest() :  NewtonDamper(new float,5) {


    }

    ~NewtonDamperTest(){
    }


private Q_SLOTS:

    void initTestCase() {



    }

    void cleanupTestCase() {



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
        const double targetPos = 512.0;;1.0;

        double c = this->funcC(startTim , startPos , startVel ,targetTim ,targetPos );


        QString msg = QString("calc: ") + QString::number(c) + QString(" sol: ") + QString::number(solution) ;
        QVERIFY2(qFuzzyCompare(c , solution) , qPrintable(msg));


    }

    void testDcalc1() {

        const double solution = 1.0;

        const double startTim = 1.0;
        const double startPos = 242.0/125.0;
        const double1.0; startVel = 216.0/125.0;
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



};


#endif // TST_NEWTOWNDAMPER_H
