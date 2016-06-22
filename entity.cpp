#include "entity.h"
#include "mesh/primitivemesh.h"
#include "mesh/normal3dmesh.h"
#include "Primitives/shapegenerator.h"
#include <QOpenGLFunctions>
#include <QFile>

Entity::Entity(Mesh* pMesh, Material* pMaterial, QOpenGLContext *context, const QMatrix4x4 *pWorld, const QString strName, QObject *parent)
    : Renderable(context, pWorld, strName, parent)
{

    this->mesh = pMesh;
    this->glVAO = new QOpenGLVertexArrayObject(this);
    this->material = pMaterial;

}



void Entity::Create()
{

    glVAO->create();
    glVAO->bind();

    this->material->Create();
    this->mesh->Create();

    this->material->CreateVertexLayout(mesh);

    this->material->Setup();

    glVAO->release();
}

void Entity::Render(GLuint drawOrder, const QMatrix4x4 *pView, const QMatrix4x4 *pProj, const Light * light)
{

    this->viewToProjecton = *pProj;
    this->worldToView = *pView;


    this->glVAO->bind();


    mesh->bind();
    QMatrix4x4 MW =  worldToView * (*matWorld);
    QMatrix4x4 MWP = viewToProjecton * worldToView * (*matWorld);

    this->material->SetupPerFrame(light);
    this->material->SetupPerObject(matWorld, &MW, &MWP);

    this->material->getShaderProgramm()->bind();

    this->contextDevice->functions()->glDrawElements(GL_TRIANGLES,mesh->indexSize(),GL_UNSIGNED_SHORT,0);

    this->material->getShaderProgramm()->release();

    mesh->release();
    this->glVAO->release();

}

void Entity::Destroy()
{
    this->mesh->Destroy();
    this->glVAO->destroy();
}

Entity::~Entity()
{

}
