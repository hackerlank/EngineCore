#ifndef ENTITY_H
#define ENTITY_H

#include "renderable.h"
#include "material.h"
#include "mesh.h"
#include "light.h"
#include <QOpenGLVertexArrayObject>

/*!
 * \brief The Entity class
 *
 * Implements a Renderable Object
 * a Renderable Mesh with one Material
 *
 * \see Mesh
 * \see Material
 */
class Entity : public Renderable
{

protected:
    Material * material;
    Mesh * mesh;
    QOpenGLVertexArrayObject * glVAO;


    QMatrix4x4 worldToView; //ViewMatrix
    QMatrix4x4 viewToProjecton;
    QMatrix4x4 animate;

public:
    /*!
     * \brief Entity creates a new Entity need a Mesh, Material, Context and a Position in the World
     * \param pMesh the Mesh of the Entity
     * \param pMaterial the Material for the Mesh
     * \param context the context witch shoud be drawed to
     * \param pWorld the modelToWorld Matrix gives the position of the Entiry in the World
     * \param strName OPT. gives the Entity a name
     * \param parent OPT QObject Parent
     */
    Entity(Mesh* pMesh, Material* pMaterial, QOpenGLContext *context, const QMatrix4x4* pWorld, const QString strName = "Entity", QObject *parent=0);
    ~Entity();

    /*!
     * \brief Create and initilize OpenGL Values
     * Creates Mesh and Material and initilize them
     */
    virtual void Create();

    /*!
     * \brief Destroy Clear the GPU Memory and Delets the OpenGL Values
     */
    virtual void Destroy();

    /*!
     * \brief Render Renders the Entity to the given openGL context
     * \param drawOrder order
     * \param pView WorldToView Matrix for the Entity
     * \param pProj Projection for the Entity
     * \param light A light for rendering
     */
    virtual void Render(GLuint drawOrder, const QMatrix4x4 *pView, const QMatrix4x4 *pProj, const Light* light);

    void setAnimationSpeed(float speed);
    void setAnimationMatrix(QMatrix4x4 animate){this->animate = animate;}
    virtual void update(double fTime, double fElapsedTime) {

        animate = QMatrix4x4();
        animate.translate(0,0,-1-fTime);
        *matWorld = animate;
    }

public slots:

};

#endif // ENTITY_H
