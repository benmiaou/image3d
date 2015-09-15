#include <iostream>
#include <fstream>

#include <sstream>
#include "pgm3D.hpp"
using namespace std;




pgm3D::pgm3D(string fileName){
    ifstream file;
    istringstream iss;
    file.open(fileName.c_str());
    string line;
    getline(file, line);
    if(line != "PGM3D")
       cout << "Wrong format" << endl;
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


