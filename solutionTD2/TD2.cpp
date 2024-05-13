

#include <cstdlib>
#include <iostream>
#include "XWindow.h"
#include "Vector4D.h"
#include "Matrix4x4.h"

static const int X_SIZE = 800;
static const int Y_SIZE = 600;
static const int X_SIZEH = X_SIZE/2;
static const int Y_SIZEH = Y_SIZE/2;

using namespace std;

void drawGrid3DCPP(XWindow &win, const Matrix4x4 &projection) {
  Vector4D vectA(-10,  0, 10, 1);
  Vector4D vectB( 10,  0, 10, 1);
  Vector4D vectC( 10,  0,-10, 1);
  Vector4D vectD(-10,  0,-10, 1);

  Vector4D Ar = vectA * projection;
  Vector4D Br = vectB * projection;
  Vector4D Cr = vectC * projection;
  Vector4D Dr = vectD * projection;

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
  double rx=0;
  double rz=0;
  for (;!win.isButtonRelease();) {
    win.clear();

    Matrix4x4 modelView,tmpMat;
    modelView.rotZ(rz);
    tmpMat.rotX(rx);
    modelView *= tmpMat;

    Matrix4x4 projection;
    projection.projection(800,40);
    projection = modelView * projection;
    drawGrid3DCPP(win, projection);
    rx+=0.0001;
    win.refresh();
  }
  return EXIT_SUCCESS;
}
