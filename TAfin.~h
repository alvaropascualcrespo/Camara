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
				
                void traslacion(GLfloat x, GLfloat y, GLfloat z);
                void escalacion(GLfloat x, GLfloat y, GLfloat z);
                void rotacion(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
                void postMultiplica(GLfloat matr[16]);
				
                void setPosicion(int posicion, GLfloat numero){m[posicion] = numero;};
};
#endif
 