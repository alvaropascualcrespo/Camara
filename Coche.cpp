//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Coche.h"

//---------------------------------------------------------------------------

Coche::Coche(GLfloat xa, GLfloat ya, GLfloat za){
        x = xa;
        y = ya;
        z = za;
        radioRueda = 0.1;
        movimiento = 0;

        construye();
}

void Coche::construye(){
        rueda1 = gluNewQuadric();
        rueda2 = gluNewQuadric();
        rueda3 = gluNewQuadric();
        rueda4 = gluNewQuadric();

        tapa1 = gluNewQuadric();
        tapa2 = gluNewQuadric();
        tapa3 = gluNewQuadric();
        tapa4 = gluNewQuadric();

        cubo = new Cubo(1.4*x,1*y,1.6*z);
        cubo->construye();
}

void Coche::dibuja(){
        glMatrixMode(GL_MODELVIEW);

        //Ruedas y Tapas
        glColor3f(0,0,0);

        glPushMatrix();
        glTranslated(-0.3,0.15,0);

        //Rueda1
        glPushMatrix();
                glRotated(90,0,1,0);
                glTranslated(-radioRueda,0,0.1*x);
                glRotated(movimiento,0,0,1);
                gluQuadricDrawStyle(rueda1,GLU_FILL);
                gluCylinder(rueda1,radioRueda*2,radioRueda*2,0.2,20,20);
        glPopMatrix();
        glPushMatrix();
                glRotated(90,0,1,0);
                glTranslated(-radioRueda,0,0.1*x);
                glRotated(movimiento,0,0,1);
                gluQuadricDrawStyle(tapa1,GLU_FILL);
                gluDisk(tapa1,0,radioRueda*2,20,20);
        glPopMatrix();

        //Rueda2
        glPushMatrix();
                glRotated(90,0,1,0);
                glTranslated(-radioRueda-1.2*z,0,0.1*x);
                glRotated(movimiento,0,0,1);
                gluQuadricDrawStyle(rueda1,GLU_FILL);
                gluCylinder(rueda2,radioRueda*2,radioRueda*2,0.2,20,20);
        glPopMatrix();
        glPushMatrix();
                glRotated(90,0,1,0);
                glTranslated(-radioRueda-1.2*z,0,0.1*x);
                glRotated(movimiento,0,0,1);
                gluQuadricDrawStyle(tapa1,GLU_FILL);
                gluDisk(tapa2,0,radioRueda*2,20,20);
        glPopMatrix();

        //Rueda3
        glPushMatrix();
                glRotated(90,0,1,0);
                glTranslated(-radioRueda,0,0.7*x+0.2);
                glRotated(movimiento,0,0,1);
                gluQuadricDrawStyle(rueda1,GLU_FILL);
                gluCylinder(rueda3,radioRueda*2,radioRueda*2,0.2,20,20);
        glPopMatrix();
        glPushMatrix();
                glRotated(90,0,1,0);
                glTranslated(-radioRueda,0,0.7*x+0.2);
                glRotated(movimiento,0,0,1);
                gluQuadricDrawStyle(tapa1,GLU_FILL);
                gluDisk(tapa3,0,radioRueda*2,20,20);
        glPopMatrix();

        //Rueda4
        glPushMatrix();
                glRotated(90,0,1,0);
                glTranslated(-radioRueda-1.2*z,0,0.7*x+0.2);
                glRotated(movimiento,0,0,1);
                gluQuadricDrawStyle(rueda1,GLU_FILL);
                gluCylinder(rueda4,radioRueda*2,radioRueda*2,0.2,20,20);
        glPopMatrix();
        glPushMatrix();
                glRotated(90,0,1,0);
                glTranslated(-radioRueda-1.2*z,0,0.7*x+0.2);
                glRotated(movimiento,0,0,1);
                gluQuadricDrawStyle(tapa1,GLU_FILL);
                gluDisk(tapa4,0,radioRueda*2,20,20);
        glPopMatrix();

        //Cubo
        glPushMatrix();
                glColor3f(1,0,0);
                glTranslated(0.2*x,radioRueda/2-1.4*x,radioRueda);
                cubo->dibuja(true,true);
        glPopMatrix();

        glPopMatrix();
}

#pragma package(smart_init)
