//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "GLSkel3D.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGLForm3D *GLForm3D;
//---------------------------------------------------------------------------
__fastcall TGLForm3D::TGLForm3D(TComponent* Owner): TForm(Owner) {
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TGLForm3D::FormCreate(TObject *Sender) {
  hdc=GetDC(Handle);
  SetPixelFormatDescriptor();
  hrc=wglCreateContext(hdc);
  if(hrc==NULL) ShowMessage("Error CreateContex");
  if(wglMakeCurrent(hdc, hrc)==false) ShowMessage("Error MakeCurrent");

  crearObjetosEscena();

  glClearColor(0.6,0.7,0.8,1.0);
  glEnable(GL_LIGHTING);

  glEnable(GL_COLOR_MATERIAL);
  glMaterialf(GL_FRONT, GL_SHININESS, 0.1);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  glShadeModel(GL_SMOOTH);   //Defecto

  //Cámara
  eyeX=40.0; eyeY=40.0; eyeZ=40.0;
  lookX=0.0; lookY=0.0; lookZ=0.0;
  upX=0; upY=1; upZ=0;
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

  //Volumen de vista
  N=30; F=300;
  xRight=10; xLeft=-xRight;
  yTop=10; yBot=-yTop;

  //Ratio del volumen de vista =1
  //ClientWidth=400;
  //ClientHeight=400;
  RatioViewPort=1.0;

  posX = 0;
  posY = 0;
  posZ = 0;
  traslate = 0;
  zoom = ZOOM_BASE;
  relleno = true;

  angRoll = 0;
  angYaw = 0;
  angPitch = 0;
  camara = new Camara(eyeX,eyeY,eyeZ,lookX,lookY,lookZ,upX,upY,upZ);

  //Luz0
  glEnable(GL_LIGHT0);
  GLfloat LuzDifusa[]={1.0,1.0,1.0,1.0};
  glLightfv(GL_LIGHT0, GL_DIFFUSE, LuzDifusa);
  GLfloat LuzAmbiente[]={0.3,0.3,0.3,1.0};
  glLightfv(GL_LIGHT0, GL_AMBIENT, LuzAmbiente);
  GLfloat PosicionLuz0[]={25.0, 25.0, 0.0, 1.0};
  glLightfv(GL_LIGHT0, GL_POSITION, PosicionLuz0);
}
//---------------------------------------------------------------------------
void __fastcall TGLForm3D::SetPixelFormatDescriptor() {
  PIXELFORMATDESCRIPTOR pfd = {
    	sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        24,
        0,0,0,0,0,0,
        0,0,
        0,0,0,0,0,
        32,
        0,
        0,
        PFD_MAIN_PLANE,
        0,
        0,0,0 };
  int PixelFormat=ChoosePixelFormat(hdc,&pfd);
  SetPixelFormat(hdc,PixelFormat,&pfd);
}
//---------------------------------------------------------------------------
void __fastcall TGLForm3D::FormResize(TObject *Sender) {
  //Se actualiza puerto de vista y ratio
  if ((ClientHeight<=1.0) || (ClientHeight<=1.0)) {
        ClientWidth=400;
        ClientHeight=400;
        RatioViewPort=1.0;
  }
  else RatioViewPort=(GLfloat)ClientWidth/(GLfloat)ClientHeight;

  glViewport(0,0,ClientWidth,ClientHeight);

  //Se actualiza el volumen de vista
  //para que su ratio coincida con RatioViewPort
  GLfloat RatioVolVista=xRight/yTop;

  if (RatioVolVista>=RatioViewPort) {
     //Aumentamos yTop-yBot
     yTop=xRight/RatioViewPort;
     yBot=-yTop;
     }
  else {
     //Aumentamos xRight-xLeft
     xRight=RatioViewPort*yTop;
     xLeft=-xRight;
     }

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(xLeft, xRight, yBot, yTop, N, F);

  GLScene();
}
//---------------------------------------------------------------------------
void __fastcall TGLForm3D::GLScene() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);

  glTranslatef(traslate,0,0);

  glRotatef(posX,1,0,0);
  glRotatef(posY,0,1,0);
  glRotatef(posZ,0,0,1);



  glScalef(zoom,zoom,zoom);
  escena->dibuja(relleno);


  glRotatef(-posZ,0,0,1);
  glRotatef(-posY,0,1,0);
  glRotatef(-posX,1,0,0);

  


  zoom = ZOOM_BASE;

  glScalef(1/zoom,1/zoom,1/zoom);
  glTranslatef(-traslate,0,0);
 


  //Dibujo de los ejes
  glBegin(GL_LINES);
        glColor4f(1.0, 0.0, 0.0, 1.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(10.0, 0.0, 0.0);

        glColor4f(0.0, 1.0, 0.0, 1.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 10.0, 0.0);

        glColor4f(0.0, 0.0, 1.0, 1.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 10.0);
  glEnd();


  glColor3f(1.0, 1.0, 1.0);


  glFlush();
  SwapBuffers(hdc);
}
//---------------------------------------------------------------------------
void __fastcall TGLForm3D::FormPaint(TObject *Sender) {
  GLScene();
}
//---------------------------------------------------------------------------
void __fastcall TGLForm3D::FormDestroy(TObject *Sender) {
  liberarObjetosEscena();
  ReleaseDC(Handle,hdc);
  wglMakeCurrent(NULL,NULL);
  wglDeleteContext(hrc);
}
//---------------------------------------------------------------------------
void TGLForm3D::crearObjetosEscena() {
        TAfin* t = new TAfin();
        escena = new Escena(t);
}
//---------------------------------------------------------------------------
void TGLForm3D::liberarObjetosEscena() {
  //gluDeleteQuadric(esfera);
}

void __fastcall TGLForm3D::FormKeyPress(TObject *Sender, char &Key)
{
        ShowMessage(Key);

}
//---------------------------------------------------------------------------

void __fastcall TGLForm3D::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
      // ShowMessage(Key);
        switch(Key){
                case KEY_UP: posX -= ANG_GIRO; break;
                case KEY_DOWN: posX += ANG_GIRO; break;
                case KEY_LEFT: posY -= ANG_GIRO; break;
                case KEY_RIGHT: posY += ANG_GIRO; break;
                case KEY_A: posZ += ANG_GIRO; break;
                case KEY_Z: posZ -= ANG_GIRO; break;
                case KEY_G: relleno = false; break;
                case KEY_H: relleno = true; break;

                case KEY_COMA:  traslate += DELTA_TRASLATE; break;
                case KEY_POINT: traslate -= DELTA_TRASLATE; break;

                case KEY_MORE:  zoom = ZOOM_BASE + DELTA_ZOOM;
                                break;
                                
                case KEY_LESS:  zoom = ZOOM_BASE - DELTA_ZOOM;
                                break;

                case KEY_J:     angYaw += M_PI/256;
                                camara->yaw(angYaw);
                                break;

                case KEY_K:     angYaw -= M_PI/256;
                                camara->yaw(angYaw);
                                break;

                case KEY_U:     angRoll += M_PI/256;
                                camara->roll(angRoll);
                                break;

                case KEY_I:     angRoll -= M_PI/256;
                                camara->roll(angRoll);
                                break;

                case KEY_N:     angPitch += M_PI/256;
                                camara->pitch(angPitch);
                                break;

                case KEY_M:     angPitch -= M_PI/256;
                                camara->pitch(angPitch);
                                break;

                case KEY_P:     camara->perspectiva(xLeft,xRight,yTop,yBot,N,F);
                                break;

                case KEY_O:     camara->ortogonal(xLeft,xRight,yTop,yBot,N,F);
                                break;

                case KEY_4:     camara->vistaLateral(40);
                                break;

                case KEY_5:     camara->vistaFrontal(40);
                                break;

                case KEY_6:     camara->vistaCenital(40);
                                break;

                case KEY_7:     camara->vistaEsquina(40,40,40);
                                break;

                case KEY_E:     camara->recorrido(0.5,0,0);
                                break;

                case KEY_R:     camara->recorrido(-0.5,0,0);
                                break;

                case KEY_D:     camara->recorrido(0,0.5,0);
                                break;

                case KEY_F:     camara->recorrido(0,-0.5,0);
                                break;

                case KEY_C:     camara->recorrido(0,0,0.5);
                                break;

                case KEY_V:     camara->recorrido(0,0,-0.5);
                                break;

                case KEY_1:     camara->giraX();
                                break;

                case KEY_2:     camara->giraY();
                                break;

                case KEY_3:     camara->giraZ();
                                break;

                case KEY_X:     camara->desplazarY(0.2);
                                break;

                case KEY_S:     camara->desplazarY(-0.2);
                                break;

                case KEY_B:     PV3D* d = new PV3D(0.09,0.09,1,false);
                                camara->oblicua(d,xLeft,xRight,yTop,yBot,N,F);
                                break;


        }
        GLScene();
}
//---------------------------------------------------------------------------

