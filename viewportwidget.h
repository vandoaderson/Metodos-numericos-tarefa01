#ifndef VIEWPORTWIDGET_H
#define VIEWPORTWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTimer>

class ViewportWidget : public QOpenGLWidget, protected QOpenGLFunctions {

    Q_OBJECT

public:

    explicit ViewportWidget(QWidget *parent = 0);
    ~ViewportWidget();

    int radius;
    bool wireframe;

protected:

    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;

private:
    QTimer timer;
    float ang;    
};

#endif // VIEWPORTWIDGET_H
