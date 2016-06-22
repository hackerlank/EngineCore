#ifndef CAMERA_H
#define CAMERA_H

#include <QVector3D>
#include <QMatrix4x4>
#include <QObject>
/*!
 * \brief The Camera class Class for a Camera in a 3D Scene
 * The Camera Calculates the World to View Matrix and the Projection Matrix
 *
 * Camera is initilzed with standard values
 *
 * TODO: Need function to change values
 */
class Camera : public QObject
{
    Q_OBJECT

    QVector3D position;
    QVector3D viewDirection;
    const QVector3D up;

    float angleFieldOfView;
    float aspectRatio;
    float nearP, farP;

public:
    /*!
     * \brief Camera Creates a new Camera with standard values
     * \param width width of the screen for the correct aspectRatio
     * \param height height of the screen for the correct aspectRatio
     */
    Camera(int width = 1 , int height = 1);

    /*!
     * \brief getWorldToViewMatrix generates the World to View Matrix for this Camera
     * \return \link{QMatrix4x4} WorldToViewMatrix
     */
    QMatrix4x4 getWorldToViewMatrix() const;

    /*!
     * \brief getViewToProjectionMatrix generates the Projection Matrix for this Camera
     * \return  \link{QMatrix4x4}
     */
    QMatrix4x4 getViewToProjectionMatrix() const;

public slots:

    /*!
     * \brief updateRatio updates the aspectRatio for the Projection of the Camera.
     * This shoud be updated when the screen size changes.
     * \param width int new width of the screen device
     * \param height int new height of the screen devce
     */
    void updateRatio(int width,int height){aspectRatio = (float)width/height;}

};

#endif // CAMERA_H
