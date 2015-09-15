#ifndef PGM3D_HPP
#define PGM3D_HPP

#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;

class pgm3D
{
   public:
      pgm3D(string fileName);
      void getInfo(int *l, int *c, int *d, int *max);
      vector<int> getValues();
   private:
      vector<int> values;
      int l,c,d,max,value;
};

#endif // PGM3D_HPP
