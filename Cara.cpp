//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Cara.h"

//---------------------------------------------------------------------------

Cara::Cara(int nV){
        numVertices = nV;
        arrayVN = new VerticeNormal*[nV];
}
#pragma package(smart_init)
