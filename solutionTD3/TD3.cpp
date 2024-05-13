#include <cstdlib>
#include <iostream>
#include <list>
#include <cmath>
#include "XWindow.h"
#include "Vector4D.h"
#include "Matrix4x4.h"
#include "Particule.h"
#include <ctime>

using namespace std;

static const int X_SIZE  = 600;
static const int Y_SIZE  = 600;
static const int X_SIZEH = X_SIZE/2;
static const int Y_SIZEH = Y_SIZE/2;
static const int N_PART  = 20000;

void drawGrid3DCPP(XWindow &win, const Matrix4x4 &projection) {
  Vector4D vectA(-10,  0, 10, 1);
  Vector4D vectB( 10,  0, 10, 1);
  Vector4D vectC( 10,  0,-10, 1);
  Vector4D vectD(-10,  0,-10, 1);

  Vector4D Ar = projection * vectA;
  Vector4D Br = projection * vectB;
  Vector4D Cr = projection * vectC;
  Vector4D Dr = projection * vectD;

  Ar *= 1./Ar[3];
  Br *= 1./Br[3];
  Cr *= 1./Cr[3];
  Dr *= 1./Dr[3];

  Vector4D dx1=Br-Ar;
  Vector4D dx2=Cr-Dr;
  for (int i=0;i<=20;++i) {
    double x1 =Ar[0]+dx1[0] * i/20.0;
    double y1 =Ar[1]+dx1[1] * i/20.0;
    double x2 =Dr[0]+dx2[0] * i/20.0;
    double y2 =Dr[1]+dx2[1] * i/20.0;
    win.drawLine(int(x1+X_SIZEH),int(y1+Y_SIZEH),int(x2+X_SIZEH),int(y2+Y_SIZEH));
  }
  dx1 = Dr-Ar;
  dx2 = Cr-Br;
  for (int i=0;i<=20;++i) {
    double x1 = Ar[0]+dx1[0]*i/20.0;
    double y1 = Ar[1]+dx1[1]*i/20.0;
    double x2 = Br[0]+dx2[0]*i/20.0;
    double y2 = Br[1]+dx2[1]*i/20.0;
    win.drawLine(int(x1+X_SIZEH), int(y1+Y_SIZEH), int(x2+X_SIZEH), int(y2+Y_SIZEH));
  }
}

int main() {
  XWindow win(X_SIZE,Y_SIZE);
  win.setBackground(win.black());
  win.setForeground(win.white());
  double rx = -M_PI / 6.0;
  double rz = M_PI;
  double ry = 3.14;

  Particule *lPart[N_PART];

   for (int i=0;i<N_PART;++i) {
     double alpha = 2.*M_PI*(double(rand())/double(RAND_MAX));
     lPart[i] = new AccelerateParticule(Vector4D(0, 0, 0, 1),
					Vector4D ( 0.01 * cos(alpha), 0.1 ,
						   0.01 * sin(alpha), 0.));
   }

   unsigned int count = 0;
   clock_t tmp_clock = clock();

  for (;!win.isButtonRelease();) {
    win.clear();
    Matrix4x4 modelView,tmpMat;
    modelView.rotY(ry); //rotation on z axis
    tmpMat.rotZ(rz); //rotation on x axis
    modelView *= tmpMat;
    tmpMat.rotX(rx); //rotation on y axis
    modelView *= tmpMat;
    Matrix4x4 projection;
    projection.projection(800,20); //projection on screen
    projection *= modelView;

    win.setForeground(0xFF0000);
    drawGrid3DCPP(win, projection);
    Vector4D tmpVect;
    list<Particule *>::iterator it;
    for (int i=0; i<N_PART; ++i) {
      tmpVect  = projection * (lPart[i])->getPosition();
      win.setForeground(0x9999FF);
      //win.drawPoint((int)(tmpVect[0]/tmpVect[3] + X_SIZEH),
      //	    (int)(tmpVect[1]/tmpVect[3] + Y_SIZEH));
      win.drawCircle((int)(tmpVect[0]/tmpVect[3] + X_SIZEH),
		     (int)(tmpVect[1]/tmpVect[3] + Y_SIZEH), 1);
      (lPart[i])->move();
    }
    win.refresh();
    //    rx += 0.01;
    ry += 0.01;
    ++count ;
    if (count == 200) {
      clock_t delta = clock() - tmp_clock;
      double fps = 200.0 / (double(delta) / double(CLOCKS_PER_SEC));
      cout << " Frame per second : " << fps << endl;
      tmp_clock = clock();
      count = 0;
    }

  }
  return EXIT_SUCCESS;
}
