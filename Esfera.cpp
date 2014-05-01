//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Esfera.h"

//---------------------------------------------------------------------------
Esfera::Esfera(GLdouble r, GLint p, GLint m, TAfin* t, Color* c) : ObjetoCuadrico(t,c){
        quadric = gluNewQuadric();
        radio = r;
        paralelos = p;
        meridianos = m;
}

void Esfera::dibuja(bool rellena){
        glPushMatrix();
        glMultMatrixf(getTAfin()->getMatrix());
        gluSphere(quadric,radio,paralelos,meridianos);
        glPopMatrix();
}


#pragma package(smart_init)
