#ifndef QUAD_H
#define QUAD_H
#include "point.hpp"
#include <stdlib.h>
#include <vector>
using namespace std;

class quad
{
public:
    quad(point a, point b, point c, point d);
    vector<point> points;
    float grey;
};

#endif // QUAD_H
