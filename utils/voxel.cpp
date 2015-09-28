#include "voxel.hpp"
#include "GL/gl.h"

void voxel::addQuad(int otherGrey,int grey,quad q,bool allFaces){
    if(allFaces){
        q.grey = grey;
        quads.push_back(q);
    }
    else if(otherGrey!=grey)
        if(otherGrey < grey){
            q.grey = grey;
            quads.push_back(q);
        }
}


voxel::voxel(pgm3D pgm, bool allFaces)
{

   // int width,height,depth,max;
    pgm.getInfo(&width,&height,&depth,&max);
    vector<int> values = pgm.getValues();

    for(int x = 0; x < width; x++)
        for(int y = 0; y<height; y++)
            for(int z =0; z<depth; z++)
                if(values[x*depth*height+y*depth+z]!=0){
                    int grey = values[x*depth*height+y*depth+z];
                    int otherGrey;
                    point a(x-0.5,y-0.5,z-0.5);
                    point b(x-0.5,y+0.5,z-0.5);
                    point c(x+0.5,y+0.5,z-0.5);
                    point d(x+0.5,y-0.5,z-0.5);
                    point e(x-0.5,y-0.5,z+0.5);
                    point f(x-0.5,y+0.5,z+0.5);
                    point g(x+0.5,y+0.5,z+0.5);
                    point h(x+0.5,y-0.5,z+0.5);
                    quad q(a,b,c,d);

                    otherGrey=values[x*depth*height+y*depth+z-1];
                    q = quad(a,b,c,d);
                    addQuad(otherGrey,grey,q,allFaces);


                    otherGrey=values[(x-1)*depth*height+y*depth+z];
                    q = quad(a,b,f,e);
                    addQuad(otherGrey,grey,q,allFaces);

                    otherGrey=values[x*depth*height+y*depth+z+1];
                    q= quad(e,f,g,h);
                    addQuad(otherGrey,grey,q,allFaces);


                    otherGrey=values[(x+1)*depth*height+y*depth+z];
                    q= quad(h,g,c,d);
                    addQuad(otherGrey,grey,q,allFaces);

                    otherGrey=values[x*depth*height+(y-1)*depth+z];
                    q= quad(a,d,h,e);
                    addQuad(otherGrey,grey,q,allFaces);

                    otherGrey=values[x*depth*height+(y+1)*depth+z];
                    q= quad(b,c,g,f);
                    addQuad(otherGrey,grey,q,allFaces);

                }
    std::cout << "Number oh faces "<< quads.size() << std::endl;



}
