#ifndef MATERIAL_H
#define MATERIAL_H

#include <QObject>
#include <QOpenGLContext>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QVector4D>
#include <QOpenGLBuffer>
#include "mesh.h"
#include "light.h"

/*!
 * \brief The Material class
 *
 * This Class manages a material for a Object.
 * A Material contains vertex and fragment shader and manages the connection to them
 */
class Material : public QObject
{
private:
    Q_OBJECT
protected:

    QOpenGLContext* contextDevice;

    QString vertexShaderFileName;
    QString fragmentShaderFileName;

    QOpenGLShader* vertexShader;
    QOpenGLShader* fragmentShader;

    QOpenGLShaderProgram* programm;

    QVector4D diffuseColor;
    QVector4D ambientColor;

    int diffuseColorLocation;
    int ambientColorLocation;
    int vertexLocation;
    int worldViewProjMatrixLocation;

public:
    explicit Material(QOpenGLContext* context,
                      QString vShaderFile,
                      QString fShaderFile, QObject *parent = 0);

    virtual void Create();
    virtual void Destroy();
    virtual void CreateVertexLayout(Mesh *format);
    virtual void Setup();

    virtual void SetupPerObject(const QMatrix4x4* matWorld, const QMatrix4x4* matWorldView,
                                const QMatrix4x4* matWorldViewProjection);
    virtual void SetupPerFrame(const Light* pLight);

    inline QOpenGLShader* getVertexShader(){return vertexShader;}
    inline QOpenGLShader* getFragmentShader(){return fragmentShader;}
    inline QOpenGLShaderProgram* getShaderProgramm(){return programm;}

    //QVector4D getDiffuseColor() const;
    void setDiffuseColor(const QVector4D &value){diffuseColor = value;}

    //QVector4D getAmbientColor() const;
    void setAmbientColor(const QVector4D &value){ambientColor = value;}


signals:

public slots:
};

#endif // MATERIAL_H
