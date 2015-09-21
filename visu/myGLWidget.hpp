#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include "../utils/quad.hpp"
#include "../utils/point.hpp"
#include <stdlib.h>
#include <vector>
using namespace std;

class GLWidget : public QGLWidget {

    Q_OBJECT // must include this if you use Qt signals/slots

public:
    GLWidget( vector<quad> quads,QWidget *parent = NULL);
    vector<quad> quads;

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
};


#endif // MYGLWIDGET_H
