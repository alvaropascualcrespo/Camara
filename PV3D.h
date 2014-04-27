//---------------------------------------------------------------------------

#ifndef PV3DH
#define PV3DH
//---------------------------------------------------------------------------

#include <gl/GL.h>
#include <iostream>
using namespace std;

//const double PI = 3,1415926;

class PV3D{

	private:
		GLfloat x;
		GLdouble y;
		GLdouble z;
		bool point;

        public:

	        PV3D();
	        PV3D(GLdouble xn, GLdouble yn, GLdouble zn, bool pointn);
	        PV3D(const PV3D &p);
	        ~PV3D();
                bool isPoint();
                GLdouble getX(){return x;};
                GLdouble getY(){return y;};
                GLdouble getZ(){return z;};
                void fillPoint(GLdouble xn, GLdouble yn, GLdouble zn);
                void fillVector(GLdouble xn, GLdouble yn, GLdouble zn);

                void normaliza();
                GLfloat modulo();
                GLfloat productoEscalar(PV3D* v);
                PV3D* productoVectorial(PV3D* v);
                GLfloat dot(PV3D* v);
                PV3D* multiplicaMatriz(PV3D* N, PV3D* B, PV3D* T, PV3D* C);

};


#endif
 