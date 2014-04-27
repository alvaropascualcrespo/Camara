//---------------------------------------------------------------------------

#ifndef TAfinH
#define TAfinH

#include <gl\gl.h>
//---------------------------------------------------------------------------
class TAfin{
        private:
                GLfloat* m;

        public:
                TAfin();
                GLfloat* getMatrix(){return m;};
                void setPosicion(int posicion, GLfloat numero){m[posicion] = numero;};
};
#endif
 