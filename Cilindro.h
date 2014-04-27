//---------------------------------------------------------------------------

#ifndef CilindroH
#define CilindroH

#include "ObjetoCuadrico.h"
#include <gl\gl.h>
#include <gl\glu.h>
#include "Color.h"
//---------------------------------------------------------------------------
class Cilindro : public ObjetoCuadrico{
        private:
                GLUquadric* quadric;
                GLdouble base;
                GLdouble arriba;
                GLdouble altura;
                GLint porciones;
                GLint lados;
        public:
                Cilindro(GLdouble b, GLdouble a, GLdouble h, GLint p, GLint l, TAfin* t, Color* c);
                void dibuja();

};

#endif
 