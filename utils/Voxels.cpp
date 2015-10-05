#include "Voxels.hpp"
#include <iostream>
#include <fstream>




/*e------h.
  |`.    | `.
  |  `a--+---d
  |   |  |   |
  f---+--g   |
   `. |   `. |
     `b------c*/
Voxels::Voxels(string fileName, bool allFaces)
{
    vector<int> values = loadFile(fileName) ;
    if(!values.empty()){
        for(int x = 0; x < width; x++)
            for(int y = 0; y<height; y++)
                for(int z =0; z<depth; z++)
                    if(values[x*depth*height+y*depth+z]!=0){
                        int grey = values[x*depth*height+y*depth+z];
                        int otherGrey;
                        QVector3D a(x-0.5,y-0.5,z-0.5);
                        QVector3D b(x-0.5,y+0.5,z-0.5);
                        QVector3D c(x+0.5,y+0.5,z-0.5);
                        QVector3D d(x+0.5,y-0.5,z-0.5);
                        QVector3D e(x-0.5,y-0.5,z+0.5);
                        QVector3D f(x-0.5,y+0.5,z+0.5);
                        QVector3D g(x+0.5,y+0.5,z+0.5);
                        QVector3D h(x+0.5,y-0.5,z+0.5);

                        Quad q(a,b,c,d);
                        otherGrey=values[x*depth*height+y*depth+z-1];
                        addQuad(otherGrey,grey,q,allFaces);

                        otherGrey=values[(x-1)*depth*height+y*depth+z];
                        q = Quad(a,e,f,b);
                        addQuad(otherGrey,grey,q,allFaces);

                        otherGrey=values[x*depth*height+y*depth+z+1];
                        q= Quad(e,h,g,f);
                        addQuad(otherGrey,grey,q,allFaces);

                        otherGrey=values[(x+1)*depth*height+y*depth+z];
                        q= Quad(c,g,h,d);
                        addQuad(otherGrey,grey,q,allFaces);

                        otherGrey=values[x*depth*height+(y-1)*depth+z];
                        q= Quad(a,d,h,e);
                        addQuad(otherGrey,grey,q,allFaces);

                        otherGrey=values[x*depth*height+(y+1)*depth+z];
                        q= Quad(b,c,g,f);
                        addQuad(otherGrey,grey,q,allFaces);

                    }
        std::cout << "Number of faces "<< mQuads.size() << std::endl;
    }
}

vector<int>  Voxels::loadFile(string fileName){
    vector<int> values;
    ifstream file;
    string line;
    file.open(fileName.c_str());
    if(!file){
        std::cout << "Can't find "<< fileName << std::endl;
        exit(EXIT_FAILURE);
    }
    getline(file, line);
    if(line == "PGM3D"){
        std::cout << "Loading PGM3D : "<< fileName << std::endl;
        Pgm3DLoader pgm3D(fileName);
        pgm3D.getInfo(&width,&height,&depth,&max);
        values = pgm3D.getValues();
    }
    else
        std::cout << "Can't load "<< fileName <<" unknow format" <<std::endl;
    return values;
}


void Voxels::addQuad(int otherGrey, int grey, Quad q, bool allFaces){
    if(allFaces){
        q.grey = grey;
        mQuads.push_back(q);
    }
    else if(otherGrey!=grey)
        //Garde la face la plus claire.
        if(otherGrey < grey){
            q.grey = grey;
            mQuads.push_back(q);
        }
}

void Voxels::draw(float alpha){
    for(int i = 0; i<mQuads.size();i++){
        float grey = mQuads[i].grey;
            grey = grey/255.0;
            /*(1-grey)/2 permet d'ajouter une valeur fixe aux interfaces plus sombre, ce qui permet une meilleur visibilité des interfaces interieur.*/
            glColor4f(grey,grey,grey,((1-grey)/2+alpha));
            glBegin(GL_QUADS);
            glVertex3f(mQuads[i].points[0].x(), mQuads[i].points[0].y(), mQuads[i].points[0].z());
            glVertex3f(mQuads[i].points[1].x(), mQuads[i].points[1].y(), mQuads[i].points[1].z());
            glVertex3f(mQuads[i].points[2].x(), mQuads[i].points[2].y(), mQuads[i].points[2].z());
            glVertex3f(mQuads[i].points[3].x(), mQuads[i].points[3].y(), mQuads[i].points[3].z());
            glEnd();
        }
}

QVector3D Voxels::getCenter(){
    return QVector3D(height/2,width/2,depth/2);
}

