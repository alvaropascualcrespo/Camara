//---------------------------------------------------------------------------

#ifndef MontanaRusaH
#define MontanaRusaH

#include "Malla.h"
#include "Coche.h"
//---------------------------------------------------------------------------
class MontanaRusa : public Malla{

        private:
                PV3D* primeraDerivada(GLfloat valor);
                PV3D* segundaDerivada(GLfloat valor);
                PV3D* funcion(GLfloat valor);
                int sucesor(int valor);
                Coche* coche;

        public:
                int NP; //numero de lados del poligono circunferencia
                int NQ; //numero de rodajas del tubo
                MontanaRusa(int np, int nq);
                PV3D** perfil;
                void creaPerfil(GLfloat r);
                void creaTuboFrenet();
                void dibujaCoche();
                void dibuja();
                void sumaCoche(){coche->suma();};
                void restaCoche(){coche->resta();};

};

#endif
