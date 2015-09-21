#ifndef VOXEL_HPP
#define VOXEL_HPP

#include "pgm3D.hpp"

#include "point.hpp"
#include "quad.hpp"

class voxel
{
public:
    voxel(pgm3D pgm);
    vector<quad> quads;
};

#endif // VOXEL_HPP
