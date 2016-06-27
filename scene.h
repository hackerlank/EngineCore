#ifndef SCENE_H
#define SCENE_H

#include <QObject>

#include <QLinkedList>
#include "light.h"
#include "camera.h"
#include "material.h"
#include "renderable.h"

/*!
 * \brief The Scene class
 *
 * Describes a Scene of renderable Objects could also contain a other scene
 * and holds dem in a Layer togehtner
 *
 */
class Scene : public Renderable
{
    Q_OBJECT

    QLinkedList<Material*> materialList;
    QLinkedList<Renderable*> renderList;
    Light * sceneLight;
    Camera * cam;
public:
    explicit Scene(QOpenGLContext * context,QObject *parent = 0);
    ~Scene();


    void addMaterial(Material* material);
    void removeMaterial(Material *material);
    void removeMaterial(int at);

    void addRenderable(Renderable* object);
    void removeRenderable(int at);
    void removeRenderable(Renderable* object);

    Camera * camera(){return cam;}
    Light * light(){return sceneLight;}

    virtual void Create();
    virtual void Destroy();
    virtual void Render(GLuint drawOrder,
                        const QMatrix4x4* pView,
                        const QMatrix4x4* pProj , const Light* pLight);
    virtual void update(double fTime, double fElapsedTime);


    void Render();

signals:

public slots:
};

#endif // SCENE_H
