//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("GLProj3D.res");
USEFORM("GLSkel3D.cpp", GLForm3D);
USEUNIT("PV3D.cpp");
USEUNIT("Cara.cpp");
USEUNIT("VerticeNormal.cpp");
USEUNIT("Malla.cpp");
USEUNIT("Objeto3D.cpp");
USEUNIT("ObjetoCuadrico.cpp");
USEUNIT("ObjetoCompuesto.cpp");
USEUNIT("Tablero.cpp");
USEUNIT("TAfin.cpp");
USEUNIT("Color.cpp");
USEUNIT("Esfera.cpp");
USEUNIT("Cilindro.cpp");
USEUNIT("Disco.cpp");
USEUNIT("DiscoParcial.cpp");
USEUNIT("Camara.cpp");
USEUNIT("Escena.cpp");
USEUNIT("Cubo.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TGLForm3D), &GLForm3D);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
