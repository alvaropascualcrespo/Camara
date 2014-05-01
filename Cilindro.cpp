//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Cilindro.h"

//---------------------------------------------------------------------------
Cilindro::Cilindro(GLdouble b, GLdouble a, GLdouble h, GLint p, GLint l, TAfin* t, Color* c) : ObjetoCuadrico(t,c){
        quadric = gluNewQuadric();
        base = b;
        arriba = a;
        altura = h;
        porciones = p;
        lados = l;
}

void Cilindro::dibuja(bool rellena){
        glPushMatrix();
        glMultMatrixf(getTAfin()->getMatrix());
        gluCylinder(quadric,base,arriba,altura,porciones,lados);
        glPopMatrix();
}

#pragma package(smart_init)
