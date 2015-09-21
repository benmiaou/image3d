#include <iostream>
#include <stdlib.h>
#include "utils/pgm3D.hpp"
#include "utils/voxel.hpp"
#include <QtGui/QApplication>
#include <QtOpenGL/QGLWidget>
#include "visu/myGLWidget.hpp"


using namespace std;

void usage(int argc,  char* argv[]){
    if(argc != 2){
        std::cout << argv[0] << " FileName" << std::endl;
        exit(EXIT_FAILURE);
    }

}

int main( int argc,  char* argv[] )
{

    usage(argc,argv);
    string str(argv[1]);
    pgm3D pgm(str);
    int l,c,d,max;
    pgm.getInfo(&l,&c,&d,&max);
    voxel vox(pgm);
    QApplication app(argc, argv);

      GLWidget *window = new GLWidget(vox.quads,0);
      window->resize(800,600);
      window->show();

      return app.exec();
}
