//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Camara.h"

//---------------------------------------------------------------------------
Camara::Camara(PV3D* eye, PV3D* look, PV3D* up){
        eyeX = eye->getX();
        eyeY = eye->getY();
        eyeZ = eye->getZ();

        lookX = look->getX();
        lookY = look->getY();
        lookZ = look->getZ();

        upX = up->getX();
        upY = up->getY();
        upZ = up->getZ();
}

Camara::Camara(GLfloat eyeX, GLfloat eyeY, GLfloat eyeZ, GLfloat lookX, GLfloat lookY, GLfloat lookZ, GLfloat upX, GLfloat upY, GLfloat upZ){
        this->eyeX = eyeX;
        this->eyeY = eyeY;
        this->eyeZ = eyeZ;

        this->lookX = lookX;
        this->lookY = lookY;
        this->lookZ = lookZ;

        this->upX = upX;
        this->upY = upY;
        this->upZ = upZ;
}

void Camara::roll(GLfloat alfa){
        PV3D* u = new PV3D();
        PV3D* v = new PV3D();
        PV3D* n = new PV3D();
        dameEjes(u,v,n);

        PV3D* t = new PV3D(*u);
        GLfloat uX = cos(alfa)*u->getX() + sin(alfa)*v->getX();
        GLfloat uY = cos(alfa)*u->getY() + sin(alfa)*v->getY();
        GLfloat uZ = cos(alfa)*u->getZ() + sin(alfa)*v->getZ();
        u->fillVector(uX,uY,uZ);

        GLfloat vX = -t->getX()*sin(alfa) + v->getX()*cos(alfa);
        GLfloat vY = -t->getY()*sin(alfa) + v->getY()*cos(alfa);
        GLfloat vZ = -t->getZ()*sin(alfa) + v->getZ()*cos(alfa);
        v->fillVector(vX,vY,vZ);

        PV3D* eye = new PV3D(eyeX,eyeY,eyeZ,false);

        hazMovimiento(u,v,n,eye);
}

void Camara::pitch(GLfloat alfa){
        PV3D* u = new PV3D();
        PV3D* v = new PV3D();
        PV3D* n = new PV3D();
        dameEjes(u,v,n);

        PV3D* t = new PV3D(*v);
        GLfloat vX = cos(alfa)*v->getX() + sin(alfa)*n->getX();
        GLfloat vY = cos(alfa)*v->getY() + sin(alfa)*n->getY();
        GLfloat vZ = cos(alfa)*v->getZ() + sin(alfa)*n->getZ();
        v->fillVector(vX,vY,vZ);

        GLfloat nX = -t->getX()*sin(alfa) + n->getX()*cos(alfa);
        GLfloat nY = -t->getY()*sin(alfa) + n->getY()*cos(alfa);
        GLfloat nZ = -t->getZ()*sin(alfa) + n->getZ()*cos(alfa);
        n->fillVector(nX,nY,nZ);

        PV3D* eye = new PV3D(eyeX,eyeY,eyeZ,false);

        hazMovimiento(u,v,n,eye);
}

void Camara::yaw(GLfloat alfa){
        PV3D* u = new PV3D();
        PV3D* v = new PV3D();
        PV3D* n = new PV3D();
        dameEjes(u,v,n);

        PV3D* t = new PV3D(*n);
        GLfloat nX = cos(alfa)*n->getX() + sin(alfa)*u->getX();
        GLfloat nY = cos(alfa)*n->getY() + sin(alfa)*u->getY();
        GLfloat nZ = cos(alfa)*n->getZ() + sin(alfa)*u->getZ();
        n->fillVector(nX,nY,nZ);

        GLfloat uX = -t->getX()*sin(alfa) + u->getX()*cos(alfa);
        GLfloat uY = -t->getY()*sin(alfa) + u->getY()*cos(alfa);
        GLfloat uZ = -t->getZ()*sin(alfa) + u->getZ()*cos(alfa);
        u->fillVector(uX,uY,uZ);

        PV3D* eye = new PV3D(eyeX,eyeY,eyeZ,false);

        hazMovimiento(u,v,n,eye);
}

void Camara::dameEjes(PV3D* &u, PV3D* &v, PV3D* &n){
        n->fillVector(eyeX-lookX,eyeY-lookY,eyeZ-lookZ);
        n->normaliza();
        PV3D* up = new PV3D(upX,upY,upZ,false);
        u = up->productoVectorial(n);
        u->normaliza();
        v = n->productoVectorial(u);
}

void Camara::hazMovimiento(PV3D* u, PV3D* v, PV3D* n, PV3D* eye){
        GLfloat* m = new GLfloat[16];
        m[0] = u->getX();
        m[1] = v->getX();
        m[2] = n->getX();
        m[3] = 0;
        m[4] = u->getY();
        m[5] = v->getY();
        m[6] = n->getY();
        m[7] = 0;
        m[8] = u->getZ();
        m[9] = v->getZ();
        m[10] = n->getZ();
        m[11] = 0;
        m[12] = -eye->productoEscalar(u);
        m[13] = -eye->productoEscalar(v);
        m[14] = -eye->productoEscalar(n);
        m[15] = 1;

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glLoadMatrixf(m);
}

void Camara::perspectiva(GLfloat xLeft, GLfloat xRight, GLfloat yTop, GLfloat yBot, GLfloat N, GLfloat F){
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum(xLeft,xRight,yBot,yTop,N,F);
}

void Camara::ortogonal(GLfloat xLeft, GLfloat xRight, GLfloat yTop, GLfloat yBot, GLfloat N, GLfloat F){
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(xLeft,xRight,yBot,yTop,N,F);
}

void Camara::oblicua(PV3D* d, GLfloat xLeft, GLfloat xRight, GLfloat yTop, GLfloat yBot, GLfloat N, GLfloat F){
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(xLeft,xRight,yBot,yTop,N,F);

        if((d->getZ() != 0) && ((d->getX() != 0) || (d->getY() != 0) || (d->getZ() != 1))){
                GLfloat* m = new GLfloat[16];
                m[0] = 1;
                m[1] = 0;
                m[2] = 0;
                m[3] = 0;
                m[4] = 0;
                m[5] = 1;
                m[6] = 0;
                m[7] = 0;
                m[8] = -d->getX()/d->getZ();
                m[9] = -d->getY()/d->getZ();
                m[10] = 1;
                m[11] = 0;
                m[12] = -N*(d->getX()/d->getZ());
                m[13] = -N*(d->getY()/d->getZ());
                m[14] = 0;
                m[15] = 1;

                glMultMatrixf(m);
        }
}

void Camara::vistaLateral(GLfloat eyeX){
        this->eyeX = eyeX;
        eyeY = 0;
        eyeZ = 0;
        upX = 0;
        upY = 1;
        upZ = 0;
        fijarCamara();
}

void Camara::vistaFrontal(GLfloat eyeZ){
        eyeX = 0;
        eyeY = 0;
        this->eyeZ = eyeZ;
        upX = 0;
        upY = 1;
        upZ = 0;
        fijarCamara();
}

void Camara::vistaCenital(GLfloat eyeY){
        eyeX = 0;
        this->eyeY = eyeY;
        eyeZ = 0;
        upX = 1;
        upY = 0;
        upZ = 0;
        fijarCamara();
}

void Camara::vistaEsquina(GLfloat eyeX, GLfloat eyeY, GLfloat eyeZ){
        this->eyeX = eyeX;
        this->eyeY = eyeY;
        this->eyeZ = eyeZ;
        upX = 0;
        upY = 1;
        upZ = 0;
        fijarCamara();
}

void Camara::fijarCamara(){
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(eyeX,eyeY,eyeZ,lookX,lookY,lookZ,upX,upY,upZ);
}

void Camara::recorrido(GLfloat x, GLfloat y, GLfloat z){
        eyeX += x;
        eyeY += y;
        eyeZ += z;
        fijarCamara();
}

void Camara::giraX(){
        GLfloat auxeyeY = cos(M_PI/64)*eyeY - sin(M_PI/64)*eyeZ;
        GLfloat auxeyeZ = cos(M_PI/64)*eyeZ + sin(M_PI/64)*eyeY;
        eyeY = auxeyeY;
        eyeZ = auxeyeZ;
        fijarCamara();
}

void Camara::giraY(){
        GLfloat auxeyeX = cos(M_PI/64)*eyeX + sin(M_PI/64)*eyeZ;
        GLfloat auxeyeZ = cos(M_PI/64)*eyeZ - sin(M_PI/64)*eyeX;
        eyeX = auxeyeX;
        eyeZ = auxeyeZ;
        fijarCamara();
}

void Camara::giraZ(){
        GLfloat auxeyeY = cos(M_PI/64)*eyeY + sin(M_PI/64)*eyeX;
        GLfloat auxeyeX = cos(M_PI/64)*eyeX - sin(M_PI/64)*eyeY;
        eyeY = auxeyeY;
        eyeX = auxeyeX;
        fijarCamara();
}

void Camara::desplazarY(GLfloat y){
        eyeY += y;
        lookY += y;
        fijarCamara();
}

#pragma package(smart_init)
