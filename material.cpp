#include "material.h"
#include <QRgb>
#include "light.h"
/*!
 * \brief Material::Material Creates a new Material
 * there are no shaders compiled or liked or bound
 *
 * \param context openGl context for the Material
 * \param vShaderFile Vertex-Shader file name and location
 * \param fShaderFile Fragment-Shader file name and location
 * \param parent
 */
Material::Material(QOpenGLContext *context, QString vShaderFile, QString fShaderFile, QObject *parent)
    : QObject(parent) ,
      diffuseColor(0.0,1.0,1.0,1.0),
      ambientColor(1.0,0.5,0.5,1.0)
{
    contextDevice = context;
    vertexShaderFileName = vShaderFile;
    fragmentShaderFileName = fShaderFile;

    diffuseColorLocation = -1;
    ambientColorLocation = -1;

    this->vertexShader = NULL;
    this->fragmentShader = NULL;
    this->programm = NULL;

    //...
}
/*!
 * \brief Material::Create reads the shader files, compiles them and adds them to a programm
 */
void Material::Create()
{
    vertexShader = new  QOpenGLShader(QOpenGLShader::Vertex,this);
    fragmentShader = new QOpenGLShader(QOpenGLShader::Fragment,this);
    programm = new QOpenGLShaderProgram(this);

    vertexShader->compileSourceFile(vertexShaderFileName);
    fragmentShader->compileSourceFile(fragmentShaderFileName);

    if(!programm->addShader(vertexShader))
        qErrnoWarning("VertexShaderError");

    if(!programm->addShader(fragmentShader))
        qErrnoWarning("FragmentShaderError");

    programm->link();
    programm->bind();


    vertexLocation = programm->attributeLocation("glVertex");
    diffuseColorLocation = programm->attributeLocation("glDiffuseColor");
    ambientColorLocation = programm->attributeLocation("glAmbientColor");
}
/*!
 * \brief Material::Destroy
 * deletes the shaders and programm
 */
void Material::Destroy()
{
    if(vertexShader)vertexShader->deleteLater();
    if(fragmentShader)fragmentShader->deleteLater();
    if(programm)programm->deleteLater();

    vertexShader=NULL;
    fragmentShader=NULL;
    programm=NULL;
}

/*!
 * \brief Material::CreateVertexLayout binds Material to a VertexBuffer and sets up the data structure
 * \param vertexBuffer QOpenGLBuffer with the VertexBuffer
 * \param format VertexFormat says what format the Buffer has with color etc
 */
void Material::CreateVertexLayout(Mesh* format)
{

    format->bind();
    programm->bind();

    programm->enableAttributeArray(vertexLocation);

    programm->setAttributeBuffer(vertexLocation,GL_FLOAT,format->vertexOffset(),format->vertexTupel(),format->vertexStride());


    programm->release();
    format->release();

}

/*!
 * \brief Material::Setup Setup shader values for the hole material livetime
 */
void Material::Setup()
{
    programm->bind();

    if(diffuseColorLocation != -1)
        programm->setAttributeValue(diffuseColorLocation,diffuseColor);
    if(ambientColorLocation != -1)
        programm->setAttributeValue(ambientColorLocation,ambientColor);

    programm->release();
}

/*!
 * \brief Material::SetupPerObject Setup values that needed to be setup for one object for one time
 * \param matWorld \link{QMatrix4x4}* The World matrix for that object
 * \param matWorldView \link{QMatrix4x4}* The WorldView matrix for that object
 * \param matWorldViewProjection \link{QMatrix4x4}* The WorldViewProjection matrix for that object
 */
void Material::SetupPerObject(const QMatrix4x4 *matWorld, const QMatrix4x4 *matWorldView, const QMatrix4x4 *matWorldViewProjection)
{
    programm->bind();

   //programm->setAttributeValue("glmWorld",matWorld->data(),4,4);
   //programm->setAttributeValue("glmWorldView",matWorldView->data(),4,4);
   programm->setAttributeValue("glmWorldViewProjection",matWorldViewProjection->data(),4,4);

   programm->release();
}
/*!
 * \brief Material::SetupPerFrame Setup Material Values (e.g. the Light source) that need to be updates only one a Frame not for every Object
 * \param pLight light values;
 */
void Material::SetupPerFrame(const Light *pLight)
{
    QVector3D lightDir = pLight->getDirection();
    QVector3D lightDiffCol = pLight->getDiffuseColor();
    QVector3D lightAmbiCol = pLight->getAmbientColor();

    programm->setAttributeValue("glLightDir",lightDir);
    programm->setAttributeValue("glLightDiffuseColor",lightDiffCol);
    programm->setAttributeValue("glLightAmbientColor",lightAmbiCol);


}



