//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ObjetoCompuesto.h"

//---------------------------------------------------------------------------
ObjetoCompuesto::ObjetoCompuesto(TAfin* t, Color* c) : Objeto3D(t,c){
        array = new Objeto3D*[100];
        numObjetos = 0;
}

void ObjetoCompuesto::anade(Objeto3D* o){
        array[numObjetos] = o;
        numObjetos++;
}

void ObjetoCompuesto::dibuja(bool relleno){
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        GLfloat* m = getTAfin()->getMatrix();
        glMultMatrixf(getTAfin()->getMatrix());
        for(int i=0; i<numObjetos; i++){
                Color* c = array[i]->getColor();
                glColor3f(c->r/255,c->g/255,c->b/255);
                array[i]->dibuja(relleno);
        }
        glPopMatrix();
}

#pragma package(smart_init)
