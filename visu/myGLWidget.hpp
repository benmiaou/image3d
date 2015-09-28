#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include "../utils/quad.hpp"
#include "../utils/point.hpp"
#include <stdlib.h>
#include <vector>
#include "mySlider.hpp"
#include "../utils/pgm3D.hpp"
#include "../utils/voxel.hpp"

using namespace std;

class GLWidget : public QGLWidget {

    Q_OBJECT // must include this if you use Qt signals/slots

public:
    GLWidget(pgm3D pgm,QWidget *parent = NULL);


protected:
    float angleY;
    float angleX;
    float previousPointX;
    float previousPointY;
    float zoom;
    float rotqube;
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void wheelEvent(QWheelEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    MyScrollBar* scrollBar;
    voxel *vox;
    pgm3D *pgm;
};


#endif // MYGLWIDGET_H
