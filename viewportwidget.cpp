#include "viewportwidget.h"

#include <GL/glut.h>


ViewportWidget::ViewportWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
    this->ang = 0.5;
    this->wireframe = true;
    this->radius = 1;

    connect( &timer, SIGNAL(timeout()), this, SLOT(update()) );
    timer.start(16);
}

ViewportWidget::~ViewportWidget()
{

}

void ViewportWidget::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(0,0,0,1);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    static GLfloat lightPosition[4] = { 0, 10, 0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void ViewportWidget::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt( 0,0,5,  0,0,0,  0,1,0 );

    glColor3f(1.0, 0.0, 0.0);

    ang += 0.5;

    glRotatef(ang, 1,1,1);

    if(wireframe)
        glutWireSphere(radius,20,20);
    else
        glutSolidSphere(radius,20,20);

}

void ViewportWidget::resizeGL(int w, int h)
{
    glViewport(0,0, w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 45.0, (float)w/h, 0.01, 100.0 );
    //updateGL();
    update();
}
