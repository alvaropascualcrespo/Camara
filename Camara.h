//---------------------------------------------------------------------------

#ifndef CamaraH
#define CamaraH

#include <gl\gl.h>
#include <gl\glu.h>
#include "PV3D.h"
//---------------------------------------------------------------------------
class Camara{
        private:
                GLfloat eyeX, eyeY, eyeZ;
                GLfloat lookX, lookY, lookZ;
                GLfloat upX, upY, upZ;
                void dameEjes(PV3D* &u, PV3D* &v, PV3D* &n);
                void hazMovimiento(PV3D* u, PV3D* v, PV3D* n, PV3D* eye);

        public:
                Camara(PV3D* eye, PV3D* look, PV3D* up);
                Camara(GLfloat eyeX, GLfloat eyeY, GLfloat eyeZ, GLfloat lookX, GLfloat lookY, GLfloat lookZ, GLfloat upX, GLfloat upY, GLfloat upZ);
                void roll(GLfloat alfa);
                void pitch(GLfloat alfa);
                void yaw(GLfloat alfa);
                void perspectiva(GLfloat xLeft, GLfloat xRight, GLfloat yTop, GLfloat yBot, GLfloat N, GLfloat F);
                void ortogonal(GLfloat xLeft, GLfloat xRight, GLfloat yTop, GLfloat yBot, GLfloat N, GLfloat F);
                void oblicua(PV3D* d, GLfloat xLeft, GLfloat xRight, GLfloat yTop, GLfloat yBot, GLfloat N, GLfloat F);
                void vistaLateral(GLfloat eyeX);
                void vistaFrontal(GLfloat eyeZ);
                void vistaCenital(GLfloat eyeY);
                void vistaEsquina(GLfloat eyeX, GLfloat eyeY, GLfloat eyeZ);
                void fijarCamara();
                void recorrido(GLfloat x, GLfloat y, GLfloat z);
                void giraX();
                void giraY();
                void giraZ();
                void desplazarY(GLfloat y);
};
#endif
