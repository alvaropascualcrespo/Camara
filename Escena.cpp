//---------------------------------------------------------------------------
#include <windows.h>

#include <vcl.h>
#pragma hdrstop

#include "Escena.h"
#include "Tablero.h"
#include "Malla.h"
#include "Cilindro.h"
#include "Esfera.h"
#include "Cubo.h"
#include <gl/GL.h>
#include <gl/Glu.h>

//---------------------------------------------------------------------------
Escena::Escena(TAfin* t){
        billar = new ObjetoCompuesto(t,new Color(0,0,0));

        //Creo los objetos

        //Tablero
        TAfin* ttablero = new TAfin();
        ttablero->traslacion(0,1,0);
        Tablero* tab = new Tablero(4,0.1,2,4,4,4,ttablero,new Color(0,97,28));
        tab->construye();
        billar->anade(tab);

        //Marco
        TAfin* tmarco = new TAfin();
        tmarco->traslacion(0,0.8,0);
        ObjetoCompuesto* marco = new ObjetoCompuesto(tmarco,new Color(94,38,5));

        TAfin* tarriba = new TAfin();
        tarriba->traslacion(0,0,-0.5);
        Tablero* arriba = new Tablero(4,0.5,0.5,4,4,4,tarriba,new Color(94,38,5));
        arriba->construye();
        marco->anade(arriba);

        TAfin* tabajo = new TAfin();
        tabajo->traslacion(0,0,2);;
        Tablero* abajo = new Tablero(4,0.5,0.5,4,4,4,tabajo,new Color(94,38,5));
        abajo->construye();
        marco->anade(abajo);

        TAfin* tderecha = new TAfin();
        tderecha->traslacion(-0.5,0,0);
        tderecha->traslacion(0,0,-0.5);
        Tablero* derecha = new Tablero(0.5,0.5,3,4,4,4,tderecha,new Color(94,38,5));
        derecha->construye();
        marco->anade(derecha);

        TAfin* tizquierda = new TAfin();
        tizquierda->traslacion(4,0,0);
        tizquierda->traslacion(0,0,-0.5);
        Tablero* izquierda = new Tablero(0.5,0.5,3,4,4,4,tizquierda,new Color(94,38,5));
        izquierda->construye();
        marco->anade(izquierda);

        billar->anade(marco);

        //Patas
        TAfin* tpatas = new TAfin();
        ObjetoCompuesto* grupoPatas = new ObjetoCompuesto(tpatas,new Color(0,0,0));

        TAfin* tpata1 = new TAfin();
        tpata1->traslacion(-0.25,0.8,-0.25);
        tpata1->rotacion(90,1,0,0);  
        Cilindro* pata1 = new Cilindro(0.2,0.2,1,4,4,tpata1,new Color(94,38,5));
        grupoPatas->anade(pata1);

        TAfin* tpata2 = new TAfin();
        tpata2->traslacion(4.25,0.8,-0.25);
        tpata2->rotacion(90,1,0,0);
        Cilindro* pata2 = new Cilindro(0.2,0.2,1,4,4,tpata2,new Color(94,38,5));
        grupoPatas->anade(pata2);

        TAfin* tpata3 = new TAfin();
        tpata3->traslacion(-0.25,0.8,2.25);
        tpata3->rotacion(90,1,0,0);
        Cilindro* pata3 = new Cilindro(0.2,0.2,1,4,4,tpata3,new Color(94,38,5));
        grupoPatas->anade(pata3);

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
        grupoPatas->anade(pata4);
        billar->anade(grupoPatas);

        //Bolas
        TAfin* tbolas = new TAfin();
        ObjetoCompuesto* grupoBolas = new ObjetoCompuesto(tbolas,new Color(0,0,0));
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
                        tbola->traslacion(0.75+extraX,1.2,0.7+extraZ);
                }
                else{
                        tbola->traslacion(3,1.2,1);
                        cbola = new Color(255,255,255);
                }
                if(i==10) cbola = new Color(0,0,0);
                Esfera* bola = new Esfera(0.075,20,20,tbola,cbola);
                grupoBolas->anade(bola);
        }
        billar->anade(grupoBolas);

        //Tiza
        TAfin* ttiza = new TAfin();
        ttiza->traslacion(-0.25,1.3,-0.25);

        ObjetoCompuesto* tiza = new ObjetoCompuesto(ttiza,new Color(255,255,255));
        TAfin* tblanco = new TAfin();
        Tablero* blanco = new Tablero(0.05,0.04,0.05,4,4,4,tblanco,new Color(255,255,255));
        blanco->construye();
        tiza->anade(blanco);
        TAfin* tazul = new TAfin();
        tazul->traslacion(0,0.04,0);
        Tablero* azul = new Tablero(0.05,0.01,0.05,4,4,4,tazul,new Color(0,127,255));
        azul->construye();
        tiza->anade(azul);
        billar->anade(tiza);

        //Taco
        TAfin* ttaco = new TAfin();
        ttaco->traslacion(4.3,1.4,1);
        ttaco->rotacion(-115,0,1,0);
        ObjetoCompuesto* taco = new ObjetoCompuesto(ttaco,new Color(255,255,255));
        TAfin* tbase = new TAfin();

        Cilindro* base = new Cilindro(0.07,0.05,1,20,20,tbase,new Color(92,64,51));
        taco->anade(base);
        TAfin* tarribataco = new TAfin();
        tarribataco->traslacion(0,0,1);
        Cilindro* arribaTaco = new Cilindro(0.05,0.03,2,20,20,tarribataco,new Color(178,134,71));
        taco->anade(arribaTaco);
        TAfin* tpunta = new TAfin();
        tpunta->traslacion(0,0,3);
        Cilindro* punta = new Cilindro(0.03,0.03,0.1,20,20,tpunta,new Color(255,255,255));
        taco->anade(punta);
        billar->anade(taco);

}

void Escena::dibuja(bool relleno){
        billar->dibuja(relleno);
}

#pragma package(smart_init)
