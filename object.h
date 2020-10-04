#ifndef OBJECT_H
#define OBJECT_H

#include "mesh.h"
#include "paint_gl.h"

#include <QOpenGLShaderProgram>

class Object : public PaintGL
{
public:
    Object(Mesh &m);

    ~Object();

    void initialieGL() override;

    void paintGL(float dt, const Camera &camera) override;

private:
    Mesh *mesh_;

    glm::mat4 model_;

    QOpenGLShaderProgram program_;

    GLuint vao_;
    GLuint vbo_;
    GLuint nbo_;
    GLuint ebo_;
};

#endif // OBJECT_H
