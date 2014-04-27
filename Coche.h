//---------------------------------------------------------------------------

#ifndef CocheH
#define CocheH

#include <gl\glu.h>
#include "Cubo.h"
//---------------------------------------------------------------------------
class Coche{

        private:
                GLfloat x;
                GLfloat y;
                GLfloat z;
                GLfloat radioRueda;

                GLUquadric* rueda1;
                GLUquadric* rueda2;
                GLUquadric* rueda3;
                GLUquadric* rueda4;

                GLUquadric* tapa1;
                GLUquadric* tapa2;
                GLUquadric* tapa3;
                GLUquadric* tapa4;

                Cubo* cubo;
                GLfloat movimiento;

        public:
                Coche(GLfloat xa, GLfloat ya, GLfloat za);
                void construye();
                void dibuja();
                void suma(){movimiento = movimiento+0.1;};
                void resta(){movimiento = movimiento-0.1;};
                GLfloat getMovimiento(){return movimiento;};

};

#endif
