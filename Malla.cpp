//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Malla.h"
#include "Color.h"
//---------------------------------------------------------------------------

Malla::Malla(int nV, int nN, int nC, TAfin* t, Color* c) : Objeto3D(t,c){
        vertices = new PV3D*[nV];
        normales = new PV3D*[nN];
        caras = new Cara*[nC];
        numVertices = nV;
        numNormales = nN;
        numCaras = nC;
}

PV3D* Malla::CalculoVectorNormalPorNewell(Cara* c){
        GLfloat x = 0;
        GLfloat y = 0;
        GLfloat z = 0;
        for(int i=0; i<c->getNumeroVertices(); i++){
                PV3D* verticeActual = vertices[c->getIndiceVerticeK(i)];
                PV3D* verticeSiguiente = vertices[c->getIndiceVerticeK((i+1) % c->getNumeroVertices())];
                x += (verticeActual->getY() - verticeSiguiente->getY()) * (verticeActual->getZ() + verticeSiguiente->getZ());
                y += (verticeActual->getZ() - verticeSiguiente->getZ()) * (verticeActual->getX() + verticeSiguiente->getX());
                x += (verticeActual->getX() - verticeSiguiente->getX()) * (verticeActual->getY() + verticeSiguiente->getY());
        }
        PV3D* normal = new PV3D(x,y,z,0);
        normal->normaliza();
        return normal;
}

void Malla::dibuja(bool rellena){
        glPushMatrix();
        glMultMatrixf(getTAfin()->getMatrix());
        for(int i=0; i<numCaras; i++){
                glLineWidth(1.0);
                if(rellena){
                        glBegin(GL_POLYGON);
                }
                else{
                        glBegin(GL_LINE_LOOP);
                }
                for(int j=0; j<caras[i]->getNumeroVertices(); j++){
                        int iN = caras[i]->getIndiceNormalK(j);
                        int iV = caras[i]->getIndiceVerticeK(j);
                        glNormal3f(normales[iN]->getX(),normales[iN]->getY(),normales[iN]->getZ());
                        //Si hubiera coordenadas de textura, aqui se suministrarian
                        //las coordenadas de textura del vertice j con glTexCoor2f(...);
                        glVertex3f(vertices[iV]->getX(),vertices[iV]->getY(),vertices[iV]->getZ());
                }
                glEnd();
        }
        glPopMatrix();
}

void Malla::dibujaNormales(){
    glColor4f(0.7f,0.7f,0.7f,1.0);
    for (int i = 0; i < numCaras; i++){
        PV3D* centro = calcularCentro(caras[i]);
        PV3D* normal = normales[i];
        glBegin(GL_LINES);
                glVertex3f(centro->getX(),centro->getY(),centro->getZ());
                glVertex3f(centro->getX()+normal->getX()/2,centro->getY()+normal->getY()/2,
                        centro->getZ()+normal->getZ()/2);
        glEnd();
    }

}


PV3D* Malla::calcularCentro(Cara* c){

        int numV=c->getNumeroVertices();
        GLfloat x=0;
        GLfloat y=0;
        GLfloat z=0;
        for(int i=0;i<numV;i++){
        PV3D *v= vertices[c->getIndiceVerticeK(i)];
                x+=v->getX();
                y+= v->getY();
                z+= v->getZ();
        }
        x=x/numV ;
        y=y/numV ;
        z=z/numV ;

        return new PV3D(x,y,z,1);  
}

#pragma package(smart_init)
