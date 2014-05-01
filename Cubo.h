//---------------------------------------------------------------------------

#ifndef CuboH
#define CuboH

#include "Malla.h"
#include "Color.h"
#include "TAfin.h"
//---------------------------------------------------------------------------
class Cubo : public Malla{

        private:
                GLfloat x;
                GLfloat y;
                GLfloat z;

        public:
                Cubo(GLfloat xa, GLfloat ya, GLfloat za, TAfin* t, Color* c);
                void construye();
};

#endif
