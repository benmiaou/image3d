#include "voxel.hpp"
#include "point.hpp"
#include "quad.hpp"
#include "GL/gl.h"

voxel::voxel(pgm3D pgm)
{

    int l,c,d,max;
    pgm.getInfo(&l,&c,&d,&max);
    vector<int> values = pgm.getValues();
    vector<quad> quads;
    for(int x = 0; x < l; x++)
        for(int y = 0; y<c; y++)
            for(int z =0; z<d; z++)
              if(values[x*l*c+y*l+z]!=0){
                  point a(x-0.5,y-0.5,z-0.5);
                  point b(x-0.5,y+0.5,z-0.5);
                  point c(x+0.5,y+0.5,z-0.5);
                  point d(x+0.5,y-0.5,z-0.5);
                  point e(x-0.5,y-0.5,z+0.5);
                  point f(x-0.5,y+0.5,z+0.5);
                  point g(x+0.5,y+0.5,z+0.5);
                  point h(x+0.5,y-0.5,z+0.5);

                  quad q(a,b,c,d);
                  quads.push_back(q);

                  q = quad(a,b,f,e);
                  quads.push_back(q);

                  q= quad(e,f,g,h);
                  quads.push_back(q);

                  q= quad(h,g,c,d);
                  quads.push_back(q);

                  q= quad(a,d,e,h);
                  quads.push_back(q);

                  q= quad(b,c,f,g);
                  quads.push_back(q);


              }


}
