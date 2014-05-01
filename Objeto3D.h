//---------------------------------------------------------------------------

#ifndef Objeto3DH
#define Objeto3DH

#include "TAfin.h"
#include "Color.h"
//---------------------------------------------------------------------------
class Objeto3D{
        public:
                Objeto3D(TAfin* t, Color* c){tm = t; color = c;};
                TAfin* getTAfin(){return tm;};
                Color* getColor(){return color;};
                Color* color;
                virtual void dibuja(bool relleno)=0;

        private:
                TAfin* tm;
};
#endif
