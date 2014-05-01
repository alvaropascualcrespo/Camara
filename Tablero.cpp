//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Tablero.h"

//---------------------------------------------------------------------------

Tablero::Tablero(GLfloat l, GLfloat a, GLfloat an, int partL, int partAN, int partAL, TAfin* t, Color* c) : ObjetoCompuesto(t,c){
        largo = l;
        alto = a;
        ancho = an;
        partesL = partL;
        partesAN = partAN;
        partesAL = partAL;
}

void Tablero::construye(){
        GLfloat largoCara = largo/partesL;
        GLfloat anchoCara = ancho/partesAN;
        GLfloat altoCara = alto/partesAL;
       /* int nVert = 0;

        for (int i=0; i<=partesL; i++){
                for(int j=0; j<=partesAL; j++){
                        for(int k=0; k<=partesAN; k++){
                                vertices[nVert] = new PV3D(i*largoCara,j*anchoCara,k*altoCara,1);
                                nVert++;
                        }
                }
        }

        int v;
        int numCara = 0;
        VerticeNormal** normalesCara;
        for (int i=0; i<=partesL; i++){
                for(int j=0; j<=partesAL; j++){
                        for(int k=0; k<=partesAN; k++){
                                v = i * ((partesAL + 1) * (partesAN + 1)) + (j * (partesAN + 1)) + k;
                                 if ((i != partesL) && (j != partesAL)){
                                        caras[numCara] = new Cara(4);
                                        normalesCara = new VerticeNormal*[4];
                                        normalesCara[0] = new VerticeNormal(v,numCara);
                                        normalesCara[1] = new VerticeNormal(v + ((partesAN + 1) * (partesAL + 1)),numCara);
                                        normalesCara[2] = new VerticeNormal(v + ((partesAN + 1) * (partesAL + 1)) + (partesAN + 1),numCara);
                                        normalesCara[3] = new VerticeNormal(v + (partesAN + 1),numCara);
                                        caras[numCara]->addVerticeNormal(normalesCara);
                                        numCara++;
                                }
                                if ((i != partesL) && (k != partesAN)){
                                        caras[numCara] = new Cara(4);
                                        normalesCara = new VerticeNormal*[4];
                                        normalesCara[0] = new VerticeNormal(v,numCara);
                                        normalesCara[1] = new VerticeNormal(v+1,numCara);
                                        normalesCara[2] = new VerticeNormal(v + ((partesAN + 1) * (partesAL + 1)) + 1,numCara);
                                        normalesCara[3] = new VerticeNormal(v + ((partesAN + 1) * (partesAL + 1)),numCara);
                                        caras[numCara]->addVerticeNormal(normalesCara);
                                        numCara++;
                                }
                                if ((k != partesAN) && (j != partesAL)){
                                       caras[numCara] = new Cara(4);
                                       normalesCara = new VerticeNormal*[4];
                                        normalesCara[0] = new VerticeNormal(v,numCara);
                                        normalesCara[1] = new VerticeNormal(v+1,numCara);
                                        normalesCara[2] = new VerticeNormal(v + (partesAN + 1) + 1,numCara);
                                        normalesCara[3] = new VerticeNormal(v + (partesAN + 1),numCara);
                                        caras[numCara]->addVerticeNormal(normalesCara);
                                        numCara++;
                                }


                        }
                }
        }


        for(int i=0; i<numCaras; i++){
                PV3D* normal = CalculoVectorNormalPorNewell(caras[i]);
                normales[i] = normal;
        }       */
        for (int i=0; i<partesL; i++){
                for(int j=0; j<partesAL; j++){
                        for(int k=0; k<partesAN; k++){
                                TAfin* t = new TAfin();
                                t->traslacion(i*largoCara,j*altoCara,k*anchoCara);
                                Cubo* c = new Cubo(largoCara,altoCara,anchoCara,t,color);
                                c->construye();
                                anade(c);
                        }
                }
        }
}

#pragma package(smart_init)
