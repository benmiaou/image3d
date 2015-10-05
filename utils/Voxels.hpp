#ifndef VOXEL_HPP
#define VOXEL_HPP

#include "Pgm3DLoader.hpp"
#include <QtOpenGL>



class Voxels
{
public:
    Voxels(string fileName, bool allFaces);
    struct Quad{
        Quad(QVector3D a, QVector3D b, QVector3D c, QVector3D d) {
            points[0] = a;
            points[1] = b;
            points[2] = c;
            points[3] = d;

        }
        QVector3D points[4];
        float grey;
    };
    vector<Quad> mQuads;
    void addQuad(int otherGrey, int grey, Quad q, bool allFaces);
    QVector3D getCenter();
    void draw(float alpha);
private:


    int width,height,depth,max;
    vector<int>  loadFile(string fileName);
};

#endif // VOXEL_HPP
