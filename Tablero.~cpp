//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Tablero.h"

//---------------------------------------------------------------------------

Tablero::Tablero(GLfloat l, GLfloat a, GLfloat an, TAfin* t, Color* c) : Malla(8,6,6,t,c){
        largo = l;
        alto = a;
        ancho = an;
}

void Tablero::construye(){
        vertices[0] = new PV3D(0,alto,0,1);
        vertices[4] = new PV3D(0,alto,ancho,1);

        vertices[1] = new PV3D(0,0,0,1);
        vertices[5] = new PV3D(0,0,ancho,1);

        vertices[2] = new PV3D(largo,0,0,1);
        vertices[6] = new PV3D(largo,0,ancho,1);

        vertices[3] = new PV3D(largo,alto,0,1);
        vertices[7] = new PV3D(largo,alto,ancho,1);

        int nVerticesCara = 4;
        for(int i=0; i<nVerticesCara; i++){
                int numCara = i;
                caras[numCara] = new Cara(nVerticesCara);
                VerticeNormal** normalesCara = new VerticeNormal*[nVerticesCara];

                int base = i;
                int suc = (i+1) % nVerticesCara;

                int v0 = base;
                int v1 = suc;
                int v2 = suc + nVerticesCara;
                int v3 = base + nVerticesCara;

                normalesCara[0] = new VerticeNormal(v0,numCara);
                normalesCara[1] = new VerticeNormal(v1,numCara);
                normalesCara[2] = new VerticeNormal(v2,numCara);
                normalesCara[3] = new VerticeNormal(v3,numCara);

                caras[numCara]->addVerticeNormal(normalesCara);
        }

        //Cara4
        caras[4] = new Cara(nVerticesCara);
        VerticeNormal** normales4 = new VerticeNormal*[nVerticesCara];
        normales4[0] = new VerticeNormal(0,4);
        normales4[1] = new VerticeNormal(3,4);
        normales4[2] = new VerticeNormal(2,4);
        normales4[3] = new VerticeNormal(1,4);
        caras[4]->addVerticeNormal(normales4);

        //Cara5
        caras[5] = new Cara(nVerticesCara);
        VerticeNormal** normales5 = new VerticeNormal*[nVerticesCara];
        normales5[0] = new VerticeNormal(4,5);
        normales5[1] = new VerticeNormal(5,5);
        normales5[2] = new VerticeNormal(6,5);
        normales5[3] = new VerticeNormal(7,5);
        caras[5]->addVerticeNormal(normales5);

        for(int i=0; i<numCaras; i++){
                PV3D* normal = CalculoVectorNormalPorNewell(caras[i]);
                normales[i] = normal;
        }
}

#pragma package(smart_init)
