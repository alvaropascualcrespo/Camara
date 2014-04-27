//---------------------------------------------------------------------------
#ifndef GLSkel3DH
#define GLSkel3DH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <gl\gl.h>
#include <gl\glu.h>

#include "Malla.h"
#include "MontanaRusa.h"
#include "Camara.h"
#include "Escena.h"

#define KEY_UP 38
#define KEY_DOWN 40
#define KEY_LEFT 37
#define KEY_RIGHT 39
#define KEY_A 65
#define KEY_Z 90
#define KEY_Q 81
#define KEY_W 87
#define KEY_G 71
#define KEY_H 72
#define KEY_I 73
#define KEY_J 74
#define KEY_K 75
#define KEY_U 85
#define KEY_N 78
#define KEY_M 77
#define KEY_P 80
#define KEY_O 79
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define KEY_E 69
#define KEY_R 82
#define KEY_D 68
#define KEY_F 70
#define KEY_C 67
#define KEY_V 86
#define KEY_X 88
#define KEY_S 83
#define KEY_B 66
#define KEY_MORE 107
#define KEY_LESS 109
#define KEY_COMA 188
#define KEY_POINT 190


//---------------------------------------------------------------------------
class TGLForm3D : public TForm
{
__published:	//IDE-managed Components
    void __fastcall FormResize(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);

private:        //User declarations
    HDC hdc;
    HGLRC hrc;
    GLfloat eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ; //Cámara
    GLdouble RatioViewPort, xLeft, xRight, yBot, yTop, N, F;  //Volumen de vista
    Malla* malla;  //Malla inicial de la escena
    GLfloat posX, posY, posZ; // variables para la posicion
    GLfloat zoom; // variable para el zoom
    GLfloat traslate;
    bool relleno, normales;
    GLfloat angRoll, angYaw, angPitch;
    Camara* camara;
    Escena* escena;

    void __fastcall SetPixelFormatDescriptor();
    void __fastcall GLScene();
    void crearObjetosEscena();
    void liberarObjetosEscena();

public:		//User declarations
    __fastcall TGLForm3D(TComponent* Owner);
};

const float ANG_GIRO = 180.0f/30.0f;
const float DELTA_ZOOM = 0.02f;
const float ZOOM_BASE = 1.0f;
const float DELTA_TRASLATE = 0.4f;
//---------------------------------------------------------------------------
extern PACKAGE TGLForm3D *GLForm3D;
//---------------------------------------------------------------------------
#endif
