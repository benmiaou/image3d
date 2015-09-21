#include <iostream>
#include <stdlib.h>
#include <QApplication>
#include <QtOpenGL>
#include"utils/pgm3D.hpp"
#include "visu/myWindow.hpp"


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
    //std::cout << "l = " << l << "c = " << c << "d = " << d << "max = " << max << std::endl;

    QApplication app(argc,argv);
    myWindow myWin;
         myWin.show();
        return app.exec();
}
