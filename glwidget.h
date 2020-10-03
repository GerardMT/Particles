
#ifndef GLWIDGET_H_
#define GLWIDGET_H_

#include <GL/glew.h>
#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
  explicit GLWidget(QWidget *parent = nullptr);

protected:
    void initializeGL() override;

    void resizeGL(int w, int h) override;

    void paintGL() override;

private:

};

#endif  //  GLWIDGET_H_
