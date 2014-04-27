//---------------------------------------------------------------------------

#ifndef TableroH
#define TableroH

#include "Malla.h"
#include "Color.h"
//---------------------------------------------------------------------------
class Tablero : public Malla{
        private:
                GLfloat largo;
                GLfloat alto;
                GLfloat ancho;

        public:
                Tablero(GLfloat l, GLfloat a, GLfloat an, TAfin* t, Color* c);
                void construye();
};
#endif
