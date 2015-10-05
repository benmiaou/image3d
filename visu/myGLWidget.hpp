#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <stdlib.h>
#include <vector>
#include "mySlider.hpp"
#include "../utils/Voxels.hpp"

using namespace std;

class GLWidget : public QGLWidget {

    Q_OBJECT // must include this if you use Qt signals/slots

public:
    GLWidget(string fileName, QWidget *parent = NULL);


protected:
    float trX;
    float trY;
    float trZ;
    float angleY;
    float angleX;
    float angleZ;
    float previousPointX;
    float previousPointY;
    float zoom;
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void wheelEvent(QWheelEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    MyScrollBar* scrollBar;
    Voxels *mObject;
    QVector3D center;
};


#endif // MYGLWIDGET_H
