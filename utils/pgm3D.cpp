#include <iostream>
#include <fstream>

#include <sstream>
#include "pgm3D.hpp"
using namespace std;




pgm3D::pgm3D(string fileName){

    ifstream file;
    istringstream iss;
    string line;
    file.open(fileName.c_str());
    if(!file){
        std::cout << "Wrong File" << std::endl;
        exit(EXIT_FAILURE);       
    }
    getline(file, line);
    if(line != "PGM3D"){
        std::cout << "Bad Format" << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
    getline(file, line);
    iss.str(line);
    iss >> l >> c >> d;
    getline(file, line);
    iss.clear();
    iss.str(line);
    iss >> max;
    while(getline(file, line)){
        iss.clear();
        iss.str(line);
        iss >> value;
        values.push_back(value);
    }
    }

}
void pgm3D::getInfo(int *l, int *c, int *d, int *max){
    *l = this->l;
    *c = this->c;
    *d = this->d;
    *max = this->max;

}

vector<int> pgm3D::getValues(){
    return values;
}

