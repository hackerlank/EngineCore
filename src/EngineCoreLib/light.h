#ifndef LIGHT_H
#define LIGHT_H

#include <QVector3D>
#include <QVector4D>
#include <QColor>

/*!
 * \brief The Light class holding Values for diffrent light Types 
 * The Shader choose with type is used
 */
class Light
{
protected:
    QVector3D position;
    QVector3D direction;
    QVector3D diffuseColor;
    QVector3D ambientColor;

    //PointLight
    QVector4D attenstion;

    //Spotlight
    float cosHalfPhi;
    float cosHalfTheta;

public:
   
    QVector3D getAmbientColor() const;
    void setAmbientColor(const QVector3D &value);
    QVector3D getDiffuseColor() const;
    void setDiffuseColor(const QVector3D &value);
    QVector3D getDirection() const;
    void setDirection(const QVector3D &value);
    QVector3D getPosition() const;
    QVector4D getAttenstion() const;
    void setAttenstion(const QVector4D &value);
    float getCosHalfPhi() const;
    void setCosHalfPhi(float value);
    float getCosHalfTheta() const;
    void setCosHalfTheta(float value);

    /*!
     * \brief Light Creates a new Light with normal values
     */
    Light();
};

#endif // LIGHT_H
