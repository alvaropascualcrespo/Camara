//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TAfin.h"

//---------------------------------------------------------------------------

TAfin::TAfin(){
        m = new GLfloat[16];
        for(int i=0; i<16; i++){
                m[i] = 0;
        }
        m[0] = 1;
        m[5] = 1;
        m[10] = 1;
        m[15] = 1;  
}         

void TAfin::traslacion(GLfloat x, GLfloat y, GLfloat z){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glTranslatef(x, y, z);
		GLfloat* mm = new GLfloat[16];
		glGetFloatv(GL_MODELVIEW_MATRIX,mm);
	glPopMatrix();
	postMultiplica(mm);		
}

void TAfin::escalacion(GLfloat x, GLfloat y, GLfloat z){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glScalef(x, y, z);
		GLfloat* mm = new GLfloat[16];
		glGetFloatv(GL_MODELVIEW_MATRIX,mm);
	glPopMatrix();
	postMultiplica(mm);	
}

void TAfin::rotacion(GLfloat angle, GLfloat x, GLfloat y, GLfloat z){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glRotatef(angle, x, y, z);
		GLfloat* mm = new GLfloat[16];
		glGetFloatv(GL_MODELVIEW_MATRIX,mm);
	glPopMatrix();
	postMultiplica(mm);	
}

void TAfin::postMultiplica(GLfloat matr[16]){
	glLoadMatrixf(this->m);
	glMultMatrixf(matr);
        glGetFloatv(GL_MODELVIEW_MATRIX,this->m);
}

#pragma package(smart_init)
