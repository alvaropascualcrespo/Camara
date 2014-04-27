//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PV3D.h"

//---------------------------------------------------------------------------

PV3D::PV3D()
{
        x = 0;
        y = 0;
        z = 0;
        point = 1;
};

PV3D::PV3D(GLdouble xn, GLdouble yn, GLdouble zn, bool pointn)
{
        x = xn;
        y = yn;
        z = zn;
        point = pointn;
};

PV3D::PV3D(const PV3D &p)
{
        x = p.x;
        y = p.y;
        z = p.z;
        point = p.point;
};

PV3D::~PV3D()
{
        x = 0;
        y = 0;
        z = 0;
};

bool PV3D::isPoint()
{
        return point;
};

void PV3D::fillPoint(GLdouble xn, GLdouble yn, GLdouble zn)
{
        x = xn;
        y = yn;
        z = zn;
        point = true;
};

void PV3D::fillVector(GLdouble xn, GLdouble yn, GLdouble zn)
{
        x = xn;
        y = yn;
        z = zn;
        point = false;
};

void PV3D::normaliza()
{
        GLfloat modulo = this->modulo();
        if(modulo !=0){
                x = x/modulo;
                y = y/modulo;
                z = z/modulo;
        }
};

GLfloat PV3D::modulo(){
        GLfloat sqrtx = x*x;
        GLfloat sqrty = y*y;
        GLfloat sqrtz = z*z;

        GLfloat suma = sqrtx+sqrty+sqrtz;

        return sqrt(suma);
}

GLfloat PV3D::productoEscalar(PV3D* v)
{
        return dot(v);
};


PV3D* PV3D::productoVectorial(PV3D* v)
{
        GLdouble xn = y * v->z - z * v->y;
        GLdouble yn = z * v->x - x * v->z;
        GLdouble zn = x * v->y - v->x * y;
        return new PV3D(xn,yn,zn,point);
};


GLfloat PV3D::dot(PV3D* v)
{
     return x*v->x + y*v->y + z*v->z;
};

PV3D* PV3D::multiplicaMatriz(PV3D* N, PV3D* B, PV3D* T, PV3D* C){
        GLfloat matriz[4][4];
        matriz[0][0] = N->getX();
        matriz[1][0] = N->getY();
        matriz[2][0] = N->getZ();
        matriz[3][0] = 0;

        matriz[0][1] = B->getX();
        matriz[1][1] = B->getY();
        matriz[2][1] = B->getZ();
        matriz[3][1] = 0;

        matriz[0][2] = T->getX();
        matriz[1][2] = T->getY();
        matriz[2][2] = T->getZ();
        matriz[3][2] = 0;

        matriz[0][3] = C->getX();
        matriz[1][3] = C->getY();
        matriz[2][3] = C->getZ();
        matriz[3][3] = 1;

        GLfloat valx = matriz[0][0]*x+matriz[0][1]*y+matriz[0][2]*z+matriz[0][3]*point;
        GLfloat valy = matriz[1][0]*x+matriz[1][1]*y+matriz[1][2]*z+matriz[1][3]*point;
        GLfloat valz = matriz[2][0]*x+matriz[2][1]*y+matriz[2][2]*z+matriz[2][3]*point;

        return new PV3D(valx,valy,valz,point);
}





#pragma package(smart_init)
