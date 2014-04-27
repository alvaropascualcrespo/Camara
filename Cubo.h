//---------------------------------------------------------------------------

#ifndef CuboH
#define CuboH

#include "Malla.h"
//---------------------------------------------------------------------------
class Cubo : public Malla{

        private:
                GLfloat x;
                GLfloat y;
                GLfloat z;

        public:
                Cubo(GLfloat xa, GLfloat ya, GLfloat za);
                void construye();
};

#endif
