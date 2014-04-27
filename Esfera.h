//---------------------------------------------------------------------------

#ifndef EsferaH
#define EsferaH

#include "ObjetoCuadrico.h"
#include <gl\gl.h>
#include <gl\glu.h>
#include "Color.h"
//---------------------------------------------------------------------------
class Esfera : public ObjetoCuadrico{
        private:
                GLUquadric* quadric;
                GLdouble radio;
                GLint paralelos;
                GLint meridianos;

        public:
                Esfera(GLdouble r, GLint p, GLint m, TAfin* t, Color* c);
                void dibuja();
};

#endif
 