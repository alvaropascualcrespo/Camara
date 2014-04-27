//---------------------------------------------------------------------------
#include <windows.h>

#include <vcl.h>
#pragma hdrstop

#include "Escena.h"
#include "Tablero.h"
#include "Malla.h"
#include "Cilindro.h"
#include "Esfera.h"
#include <gl/GL.h>
#include <gl/Glu.h>
#include <gl/glut.h>

//---------------------------------------------------------------------------
Escena::Escena(TAfin* t){
        billar = new ObjetoCompuesto(t,new Color(0,0,0));

        //Creo los objetos

        //Tablero
        TAfin* ttablero = new TAfin();
        ttablero->setPosicion(13,1);
        Tablero* tab = new Tablero(4,0.1,2,ttablero,new Color(0,97,28));
        tab->construye();
        billar->anade(tab);

        //Marco
        TAfin* tmarco = new TAfin();
        tmarco->setPosicion(13,0.8);
        ObjetoCompuesto* marco = new ObjetoCompuesto(tmarco,new Color(94,38,5));

        TAfin* tarriba = new TAfin();
        tarriba->setPosicion(14,-0.5);
        Tablero* arriba = new Tablero(4,0.5,0.5,tarriba,new Color(94,38,5));
        arriba->construye();
        marco->anade(arriba);

        TAfin* tabajo = new TAfin();
        tabajo->setPosicion(14,2);
        Tablero* abajo = new Tablero(4,0.5,0.5,tabajo,new Color(94,38,5));
        abajo->construye();
        marco->anade(abajo);

        TAfin* tderecha = new TAfin();
        tderecha->setPosicion(12,-0.5);
        tderecha->setPosicion(14,-0.5);
        Tablero* derecha = new Tablero(0.5,0.5,3,tderecha,new Color(94,38,5));
        derecha->construye();
        marco->anade(derecha);

        TAfin* tizquierda = new TAfin();
        tizquierda->setPosicion(12,4);
        tizquierda->setPosicion(14,-0.5);
        Tablero* izquierda = new Tablero(0.5,0.5,3,tizquierda,new Color(94,38,5));
        izquierda->construye();
        marco->anade(izquierda);

        billar->anade(marco);

        //Patas
        TAfin* tpata1 = new TAfin();
        tpata1->setPosicion(5,cos(M_PI/2));
        tpata1->setPosicion(6,sin(M_PI/2));
        tpata1->setPosicion(9,-sin(M_PI/2));
        tpata1->setPosicion(10,cos(M_PI/2));
        tpata1->setPosicion(13,0.8);
        tpata1->setPosicion(12,-0.25);
        tpata1->setPosicion(14,-0.25);
        Cilindro* pata1 = new Cilindro(0.2,0.2,1,4,4,tpata1,new Color(94,38,5));
        billar->anade(pata1);

        TAfin* tpata2 = new TAfin();
        tpata2->setPosicion(5,cos(M_PI/2));
        tpata2->setPosicion(6,sin(M_PI/2));
        tpata2->setPosicion(9,-sin(M_PI/2));
        tpata2->setPosicion(10,cos(M_PI/2));
        tpata2->setPosicion(13,0.8);
        tpata2->setPosicion(14,-0.25);
        tpata2->setPosicion(12,4.25);
        Cilindro* pata2 = new Cilindro(0.2,0.2,1,4,4,tpata2,new Color(94,38,5));
        billar->anade(pata2);

        TAfin* tpata3 = new TAfin();
        tpata3->setPosicion(5,cos(M_PI/2));
        tpata3->setPosicion(6,sin(M_PI/2));
        tpata3->setPosicion(9,-sin(M_PI/2));
        tpata3->setPosicion(10,cos(M_PI/2));
        tpata3->setPosicion(13,0.8);
        tpata3->setPosicion(12,-0.25);
        tpata3->setPosicion(14,-0.25);
        tpata3->setPosicion(14,2.25);
        Cilindro* pata3 = new Cilindro(0.2,0.2,1,4,4,tpata3,new Color(94,38,5));
        billar->anade(pata3);

        TAfin* tpata4 = new TAfin();
        tpata4->setPosicion(5,cos(M_PI/2));
        tpata4->setPosicion(6,sin(M_PI/2));
        tpata4->setPosicion(9,-sin(M_PI/2));
        tpata4->setPosicion(10,cos(M_PI/2));
        tpata4->setPosicion(13,0.8);
        tpata4->setPosicion(14,-0.25);
        tpata4->setPosicion(12,4.25);
        tpata4->setPosicion(14,2.25);
        Cilindro* pata4 = new Cilindro(0.2,0.2,1,4,4,tpata4,new Color(94,38,5));
        billar->anade(pata4);

        //Bolas
        for(int i=0; i<16; i++){
                Color* cbola = new Color(255,0,0);
                GLfloat extraX = 0;
                GLfloat extraZ = 0;
                if(i>=0 && i<5) extraZ = i*0.15;
                if(i>=5 && i<9){
                        extraZ = 0.075 + (i-5)*0.15;
                        extraX = 0.15;
                }
                if(i>=9 && i<12){
                        extraZ = 0.15 + (i-9)*0.15;
                        extraX = 0.30;
                }
                if(i>=12 && i<14){
                        extraZ = 0.225 + (i-12)*0.15;
                        extraX = 0.45;
                }
                if(i==14){
                        extraZ = 0.3;
                        extraX = 0.6;
                }
                TAfin* tbola = new TAfin();
                if(i!=15){
                        tbola->setPosicion(13,1.2);
                        tbola->setPosicion(12,0.75+extraX);
                        tbola->setPosicion(14,0.7+extraZ);
                }
                else{
                        tbola->setPosicion(13,1.2);
                        tbola->setPosicion(12,3);
                        tbola->setPosicion(14,1);
                        cbola = new Color(255,255,255);
                }
                if(i==10) cbola = new Color(0,0,0);
                Esfera* bola = new Esfera(0.075,20,20,tbola,cbola);
                billar->anade(bola);
        }

        //Tiza
        TAfin* ttiza = new TAfin();
        ttiza->setPosicion(13,1.3);
        ttiza->setPosicion(12,-0.25);
        ttiza->setPosicion(14,-0.25);
        ObjetoCompuesto* tiza = new ObjetoCompuesto(ttiza,new Color(255,255,255));
        TAfin* tblaco = new TAfin();
        Tablero* blanco = new Tablero(0.05,0.04,0.05,tblaco,new Color(255,255,255));
        blanco->construye();
        tiza->anade(blanco);
        TAfin* tazul = new TAfin();
        tazul->setPosicion(13,0.04);
        Tablero* azul = new Tablero(0.05,0.01,0.05,tazul,new Color(0,127,255));
        azul->construye();
        tiza->anade(azul);
        billar->anade(tiza);

        //Taco
        TAfin* ttaco = new TAfin();
        ttaco->setPosicion(13,1.3);
        ttaco->setPosicion(12,4.5);
        ttaco->setPosicion(14,1);
        ttaco->setPosicion(0,cos(-5*M_PI/8));
        ttaco->setPosicion(2,-sin(-5*M_PI/8));
        ttaco->setPosicion(10,cos(-5*M_PI/8));
        ttaco->setPosicion(8,sin(-5*M_PI/8));
        ObjetoCompuesto* taco = new ObjetoCompuesto(ttaco,new Color(255,255,255));
        TAfin* tbase = new TAfin();

        Cilindro* base = new Cilindro(0.07,0.05,1,20,20,tbase,new Color(92,64,51));
        taco->anade(base);
        TAfin* tarribataco = new TAfin();
        tarribataco->setPosicion(14,1);
        Cilindro* arribaTaco = new Cilindro(0.05,0.03,2,20,20,tarribataco,new Color(178,134,71));
        taco->anade(arribaTaco);
        TAfin* tpunta = new TAfin();
        tpunta->setPosicion(14,3);
        Cilindro* punta = new Cilindro(0.03,0.03,0.1,20,20,tpunta,new Color(255,255,255));
        taco->anade(punta);
        billar->anade(taco);

}

void Escena::dibuja(){
        billar->dibuja();
}

#pragma package(smart_init)
