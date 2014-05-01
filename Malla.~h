//---------------------------------------------------------------------------

#ifndef MallaH
#define MallaH

#include "PV3D.h"
#include "Cara.h"
#include "Objeto3D.h"
//---------------------------------------------------------------------------
class Malla : public Objeto3D{

        protected:
                int numVertices;
                PV3D** vertices;
                int numNormales;
                PV3D** normales;
                int numCaras;
                Cara** caras;

        public:
                Malla(int nV, int nN, int nC, TAfin* t, Color* c);
                PV3D* CalculoVectorNormalPorNewell(Cara* c);
                PV3D** getVertices(){return vertices;};
                void dibuja();
                void dibujaNormales();
                PV3D* calcularCentro(Cara* c);



};

#endif
