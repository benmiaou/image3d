#include "voxel.hpp"
#include "GL/gl.h"

voxel::voxel(pgm3D pgm)
{

    int width,height,depth,max;
    pgm.getInfo(&width,&height,&depth,&max);
    vector<int> values = pgm.getValues();

    for(int x = 0; x < width; x++)
        for(int y = 0; y<height; y++)
            for(int z =0; z<depth; z++)
              if(values[x*depth*height+y*depth+z]!=0){
                  int grey = values[x*depth*height+y*depth+z];
                  point a(x-0.5,y-0.5,z-0.5);
                  point b(x-0.5,y+0.5,z-0.5);
                  point c(x+0.5,y+0.5,z-0.5);
                  point d(x+0.5,y-0.5,z-0.5);
                  point e(x-0.5,y-0.5,z+0.5);
                  point f(x-0.5,y+0.5,z+0.5);
                  point g(x+0.5,y+0.5,z+0.5);
                  point h(x+0.5,y-0.5,z+0.5);

                  quad q(a,b,c,d);
                  q.grey = grey;
                  quads.push_back(q);

                  q = quad(a,b,f,e);
                  q.grey = grey;
                  quads.push_back(q);

                  q= quad(e,f,g,h);
                  q.grey = grey;
                  quads.push_back(q);

                  q= quad(h,g,c,d);
                  q.grey = grey;
                  quads.push_back(q);

                  q= quad(a,d,h,e);
                  q.grey = grey;
                  quads.push_back(q);

                  q= quad(b,c,g,f);
                  q.grey = grey;
                  quads.push_back(q);

              }


}
