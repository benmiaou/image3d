#include <iostream>
#include <stdlib.h>

#include"utils/pgm3D.hpp"

using namespace std;

void usage(int argc, const char* argv[]){
    if(argc != 2){
        std::cout << argv[0] << " FileName" << std::endl;
        exit(EXIT_FAILURE);
    }

}

int main( int argc, const char* argv[] )
{

    usage(argc,argv);
    string str(argv[1]);
    pgm3D pgm(str);

}
