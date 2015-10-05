#include "myGLWidget.hpp"
#include "GL/glu.h"
#include <qtimer.h>
#include <QSlider>
#include <QLayout>



#include <iostream>
#include <stdlib.h>

#include <QtGui/QMouseEvent>

using namespace std;
GLWidget::GLWidget(string fileName, QWidget *parent) : QGLWidget(parent) {
    mObject = new Voxels(fileName,false);
    center = mObject->getCenter();
    setMouseTracking(true);
    zoom = 50;
    previousPointX = 0;
    previousPointY = 0;
    angleY = -89;//Bon angle de vu
    angleZ = trZ = trY= trX = angleX = 0;
    scrollBar = new MyScrollBar(Qt::Horizontal,this);
    scrollBar->setMinimum(-100);
    scrollBar->setMaximum(100);
    scrollBar->setPageStep(1);
    scrollBar->resize(this->width(),25);
    scrollBar->setValue(2);

}

void GLWidget::initializeGL() {
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(16);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLoadIdentity();
}

void GLWidget::resizeGL(int w, int h) {
    GLfloat aspect = (GLfloat)w / (GLfloat)h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    scrollBar->resize(this->width(),25);
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(1,1,32+zoom,0,0,0,0,1,0);
    glTranslatef(trX,trY,trZ);
    glRotatef(angleZ, 0.0, 0.0, 1.0);
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);

    //Permet de centrer l'objet, facilitant les autres transformations
    glTranslatef(-center.x(),-center.y(),-center.z());
    mObject->draw(scrollBar->value()/100.0);
}

void GLWidget::wheelEvent(QWheelEvent* event){
    bool forward = event->delta() > 0;
    if(forward)
        zoom += 1;
    else
        zoom -=1;
}

void GLWidget::mousePressEvent(QMouseEvent *event) {

}

void GLWidget::mouseMoveEvent(QMouseEvent *event) {
    if(event->buttons() == Qt::LeftButton){
        if(abs(event->x()-previousPointX) > 100 || abs(event->y()-previousPointY) > 100)
        {
            previousPointX = event->x();
            previousPointY = event->y();

        }
        else{
            angleY += (event->x()-previousPointX) * 0.1;
            angleX += (event->y()-previousPointY) * 0.1;
            previousPointX = event->x();
            previousPointY = event->y();
        }
    }
}

void GLWidget::keyPressEvent(QKeyEvent* event) {
    switch(event->key()) {
    case Qt::Key_Escape:
        close();
        break;
    case Qt::Key_PageUp:
       // mVoxels = new voxel(*pgm,true);
        break;
    case Qt::Key_PageDown:
       // mVoxels = new voxel(*pgm,false);
        break;
    case Qt::Key_Z:
        trZ += 0.5;
        break;
    case Qt::Key_S:
        trZ -= 0.5;
        break;
    case Qt::Key_Q:
        trX -= 0.5;
        break;
    case Qt::Key_D:
        trX += 0.5;
        break;
    case Qt::Key_R:
        trY += 0.5;
        break;
    case Qt::Key_F:
        trY -= 0.5;
        break;
    case Qt::Key_A:
        angleZ += 0.5;
        break;
    case Qt::Key_E:
        angleZ -= 0.5;
        break;
    default:
        event->ignore();
        break;
    }
}
