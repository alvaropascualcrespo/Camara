//---------------------------------------------------------------------------

#ifndef CaraH
#define CaraH

#include "VerticeNormal.h"
//---------------------------------------------------------------------------
class Cara{

        private:
                int numVertices;
                VerticeNormal** arrayVN;

        public:
                Cara(int nV);
                int getNumeroVertices(){return numVertices;};
                int getIndiceNormalK(int i){return arrayVN[i]->getIndiceNormal();};
                int getIndiceVerticeK(int i){return arrayVN[i]->getIndiceVertice();};
                void addVerticeNormal(VerticeNormal** a){arrayVN = a;};

};

#endif
