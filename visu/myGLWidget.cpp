#include "myGLWidget.hpp"
#include "GL/glu.h"
#include <qtimer.h>

#include <iostream>
#include <stdlib.h>

#include <QtGui/QMouseEvent>

using namespace std;
GLWidget::GLWidget(vector<quad> quads, QWidget *parent) : QGLWidget(parent) {
    setMouseTracking(true);
    this->quads = quads;
    zoom = 1;
    previousPointX = 0;
    previousPointY = 0;
}

void GLWidget::initializeGL() {

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(60);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
    //  gluPerspective (45.0, 600/800, 0.1, 3000);
    glLoadIdentity();
}

void GLWidget::resizeGL(int w, int h) {

    GLfloat aspect = (GLfloat)w / (GLfloat)h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(1,1,32+zoom,0,0,0,0,1,0);
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
    glTranslatef(-32,-32,-32);
    for(int i = 0; i<quads.size();i++){
        glBegin(GL_QUADS);

        glColor3f(quads[i].grey/255.0,quads[i].grey/255.0,quads[i].grey/255.0);

        glVertex3f(quads[i].points[0].x, quads[i].points[0].y, quads[i].points[0].z);
        glVertex3f(quads[i].points[1].x, quads[i].points[1].y, quads[i].points[1].z);
        glVertex3f(quads[i].points[2].x, quads[i].points[2].y, quads[i].points[2].z);
        glVertex3f(quads[i].points[3].x, quads[i].points[3].y, quads[i].points[3].z);
        glEnd();
    }
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


    default:
        event->ignore();
        break;
    }
}
