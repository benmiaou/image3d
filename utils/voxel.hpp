#ifndef VOXEL_HPP
#define VOXEL_HPP

#include "pgm3D.hpp"

#include "point.hpp"
#include "quad.hpp"

class voxel
{
public:
    voxel(pgm3D pgm, bool allFaces);
    vector<quad> quads;
    void addQuad(int otherGrey, int grey, quad q, bool allFaces);
    int width,height,depth,max;
};

#endif // VOXEL_HPP
