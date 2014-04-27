//---------------------------------------------------------------------------

#ifndef ColorH
#define ColorH

#include <gl\gl.h>
//---------------------------------------------------------------------------
class Color{
        private:

        public:
                GLfloat r;
                GLfloat g;
                GLfloat b;
                Color(GLfloat red, GLfloat green, GLfloat blue){r = red; g = green; b = blue;};
};

#endif
 