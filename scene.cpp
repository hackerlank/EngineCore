#include "scene.h"

Scene::Scene(QOpenGLContext * context, QObject *parent) : Renderable(context,0,"Scene",parent)
{
    sceneLight = new Light();
    cam = new Camera();
}

Scene::~Scene()
{
    delete cam;
    delete sceneLight;
}

void Scene::addMaterial(Material* material)
{
    materialList.append(material);
}

void Scene::addRenderable(Renderable* object)
{
    renderList.append(object);
}

void Scene::Render(GLuint drawOrder, const QMatrix4x4 *pView, const QMatrix4x4 *pProj, const Light *pLight)
{
    foreach (Material* mat, materialList) {
        mat->SetupPerFrame(pLight);
    }

    foreach (Renderable* obj, renderList) {

        obj->Render(1,pView,pProj,pLight);
    }
}



void Scene::Create()
{
    foreach (Renderable* obj, renderList) {
        obj->Create();
    }
}

void Scene::Destroy()
{
    foreach (Renderable* obj, renderList) {
        obj->Destroy();
        delete obj;
    }

    foreach (Material* mat, materialList) {
        mat->Destroy();
        delete mat;
    }

    materialList.clear();
    renderList.clear();
}


void Scene::Render()
{
    foreach (Material* mat, materialList) {
        mat->SetupPerFrame(sceneLight);
    }

    foreach (Renderable* obj, renderList) {
        QMatrix4x4 mView = cam->getWorldToViewMatrix();
        QMatrix4x4 mProj = cam->getViewToProjectionMatrix();

        obj->Render(1,&mView,&mProj,sceneLight);
    }
}
