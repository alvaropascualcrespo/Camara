//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MontanaRusa.h"

//---------------------------------------------------------------------------
MontanaRusa::MontanaRusa(int np, int nq) : Malla(np*nq,np*nq,np*nq){
        NP = np;
        NQ = nq;
        perfil = new PV3D*[NP];
        coche = new Coche(0.4,0.4,0.4);
}

void MontanaRusa::creaPerfil(GLfloat r){
        GLfloat inc = 2*M_PI/NP;
        for(int i=0; i<NP; i++){
                perfil[i] = new PV3D(r*cos(i*inc),r*sin(i*inc),0,1);
        }
}

void MontanaRusa::creaTuboFrenet(){
        //Lo multiplicamos por el numero de vueltas
        GLfloat intervalo = 2*M_PI*2/NQ;
        PV3D** vertices = getVertices();

        //Construimos los vertices de cada cara del tubo
        for(int i=0; i<NQ; i++){
                GLfloat valor = i*intervalo;
                PV3D* T = primeraDerivada(valor);
                T->normaliza();
                PV3D* B = primeraDerivada(valor)->productoVectorial(segundaDerivada(valor));
                B->normaliza();
                PV3D* N = B->productoVectorial(T);
                PV3D* C = funcion(valor);
                for(int j=0; j<NP; j++){
                        int indiceVertice = NP*i+j;
                        PV3D* vertice = perfil[j]->multiplicaMatriz(N,B,T,C);
                        vertices[indiceVertice] = vertice;
                }
        }

        //Construimos las caras
        for(int i=0; i<NQ; i++){
                for (int j=0; j<NP; j++){
                        int indiceCara = NP*i+j;
                        caras[indiceCara] = new Cara(4);
                        VerticeNormal** normalesCara = new VerticeNormal*[4];

                        int verticeBase = indiceCara;
                        int v0 = verticeBase % (NP*NQ);
                        int v1 = sucesor(verticeBase % (NP*NQ));
                        int v2 = (sucesor(verticeBase)+NP) % (NP*NQ);
                        int v3 = (verticeBase + NP) % (NP*NQ);

                        normalesCara[0] = new VerticeNormal(v0,indiceCara);
                        normalesCara[1] = new VerticeNormal(v1,indiceCara);
                        normalesCara[2] = new VerticeNormal(v2,indiceCara);
                        normalesCara[3] = new VerticeNormal(v3,indiceCara);

                        caras[indiceCara]->addVerticeNormal(normalesCara);
                }

        }

        //Calculamos las normales de cada cara
        for(int i=0; i<numCaras; i++){
                normales[i] = CalculoVectorNormalPorNewell(caras[i]);
        }
}

PV3D* MontanaRusa::primeraDerivada(GLfloat valor){
        GLfloat d1x = -sin(valor);
        GLfloat d1y = 1.5*(-sin(1.5*valor));
        GLfloat d1z = cos(valor);
        return new PV3D(d1x,d1y,d1z,0);
}

PV3D* MontanaRusa::segundaDerivada(GLfloat valor){
       GLfloat d2x = -cos(valor);
       GLfloat d2y = 1.5*(-cos(1.5*valor));
       GLfloat d2z = -sin(valor);
       return new PV3D(d2x,d2y,d2z,0);
}

PV3D* MontanaRusa::funcion(GLfloat valor){
        GLfloat x = 3*cos(valor);
        GLfloat y = 2*cos(1.5*valor);
        GLfloat z = 3*sin(valor);
        return new PV3D(x,y,z,1);
}

int MontanaRusa::sucesor(int valor){
        int vAux = valor+1;
        if((vAux % NP) == 0){
                return vAux - NP;
        }
        return vAux;
}

void MontanaRusa::dibujaCoche(){
        GLfloat movimiento = coche->getMovimiento();
        PV3D* T = primeraDerivada(movimiento);
        T->normaliza();
        PV3D* B = primeraDerivada(movimiento)->productoVectorial(segundaDerivada(movimiento));
        B->normaliza();
        PV3D* N = B->productoVectorial(T);
        PV3D* C = funcion(movimiento);

        GLfloat m[] = { N->getX(), N->getY(), N->getZ(), N->isPoint(),
                        B->getX(), B->getY(), B->getZ(), B->isPoint(),
                        T->getX(), T->getY(), T->getZ(), T->isPoint(),
                        C->getX(), C->getY(), C->getZ(), C->isPoint()};

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
                glMultMatrixf(m);
                coche->dibuja();
        glPopMatrix();
}




#pragma package(smart_init)
