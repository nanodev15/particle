#include <cstdlib>
#include <iostream>
#include <cmath>
#include "XWindow.h"

static const int X_SIZE=800;
static const int Y_SIZE=600;
using namespace std;

void affiche(const double mat[4][4]) {
  for (int i=0;i<4;++i) {
    cout << "|" ;
    for (int j=0;j<4;++j)
      cout << mat[i][j] << "\t";
    cout << "|" << endl;
  }
}

void affiche(const double vect[4]) {
  cout << "[" ;
  for (int i=0;i<4;++i)
      cout << vect[i] << "\t";
  cout << "]";
}

void ident(double mat[4][4]) {
  for (int i=0;i<4;++i)
    for (int j=0;j<4;++j)
      if (i!=j)
	mat[i][j]=0;
      else
	mat[i][j]=1;
}

/*
f 0 0 0  x * f
0 f 0 0  y * f
0 0 1 0  z
0 0 1 D  z  + D
*/

//============================================================
void getRotateXMatrix(const double alpha,double matrix[4][4]){
  ident(matrix);
  double cosAlpha = cos(alpha);
  double sinAlpha = sin(alpha);
  matrix[1][1] = cosAlpha;
  matrix[2][2] = cosAlpha;
  matrix[1][2] = sinAlpha;
  matrix[2][1] = -sinAlpha;
}
//============================================================
void getProjectionMatrix(const double f, const double d, double matrix[4][4]) {
  ident(matrix);
  matrix[0][0] = f;
  matrix[1][1] = f;
  matrix[2][3] = 1;
  matrix[3][3] = d;
}
//============================================================
void getRotateZMatrix(const double alpha, double matrix[4][4]) {
  ident(matrix);
  double cosAlpha=cos(alpha);
  double sinAlpha=sin(alpha);
  matrix[0][0]=cosAlpha;
  matrix[1][1]=cosAlpha;
  matrix[0][1]=sinAlpha;
  matrix[1][0]=-sinAlpha;
}
//============================================================
void mulVector(double vect[4], const double matrix[4][4]) {
  double vectTmp[4];
  for (int j=0;j<4;++j)
    vectTmp[j] =
      vect[0] * matrix[0][j] +
      vect[1] * matrix[1][j] +
      vect[2] * matrix[2][j] +
      vect[3] * matrix[3][j];
  for (int j=0;j<4;++j)
    vect[j] = vectTmp[j];
}
//============================================================
/*
void perspective(const double f ,const double d ,double vect[4]) {
  double tmp = f/(d+vect[2]);
  vect[0] *= tmp;
  vect[1] *= tmp;
}
*/
//============================================================
void drawGrid3DC(XWindow &win,const double rx,const double rz) {

  double vectA[4] = {-10,10,0, 1};
  double vectB[4] = {10,10,0, 1};
  double vectC[4] = {10,-10,0, 1};
  double vectD[4] = {-10,-10,0, 1};


  double modelview[4][4];

  getRotateZMatrix(rz, modelview);
  affiche(modelview);
  mulVector(vectA, modelview);
  mulVector(vectB, modelview);
  mulVector(vectC, modelview);
  mulVector(vectD, modelview);


  getRotateXMatrix(rx, modelview);
  mulVector(vectA, modelview);
  mulVector(vectB, modelview);
  mulVector(vectC, modelview);
  mulVector(vectD, modelview);

  double projection[4][4];
  getProjectionMatrix(800, 40, projection);
  affiche(projection);
  mulVector(vectA, projection);
  mulVector(vectB, projection);
  mulVector(vectC, projection);
  mulVector(vectD, projection);

  vectA[0] /= vectA[3];
  vectB[0] /= vectB[3];
  vectC[0] /= vectC[3];
  vectD[0] /= vectD[3];
  vectA[1] /= vectA[3];
  vectB[1] /= vectB[3];
  vectC[1] /= vectC[3];
  vectD[1] /= vectD[3];

  double dx1 = vectB[0] - vectA[0];
  double dy1 = vectB[1] - vectA[1];
  double dx2 = vectC[0] - vectD[0];
  double dy2 = vectC[1] - vectD[1];
  for (int i=0;i<=20;++i) {
    double x1=vectA[0]+dx1*i/20.0;
    double y1=vectA[1]+dy1*i/20.0;
    double x2=vectD[0]+dx2*i/20.0;
    double y2=vectD[1]+dy2*i/20.0;
    win.drawLine(int(x1+X_SIZE/2),int(y1+Y_SIZE/2),int(x2+X_SIZE/2),int(y2+Y_SIZE/2));
  }
  dx1=vectD[0]-vectA[0];
  dy1=vectD[1]-vectA[1];
  dx2=vectC[0]-vectB[0];
  dy2=vectC[1]-vectB[1];
  for (int i=0;i<=20;++i) {
    double x1=vectA[0]+dx1*i/20.0;
    double y1=vectA[1]+dy1*i/20.0;
    double x2=vectB[0]+dx2*i/20.0;
    double y2=vectB[1]+dy2*i/20.0;
    win.drawLine(int(x1+X_SIZE/2),int(y1+Y_SIZE/2),int(x2+X_SIZE/2),int(y2+Y_SIZE/2));
  }
}
//============================================================
int main() {
  XWindow win(X_SIZE,Y_SIZE);
  win.setBackground(win.black());
  win.setForeground(win.white());
  double rx=0;
  double rz=0;
  win.setForeground(255<<11);
  for (;!win.isButtonRelease();) {
    for (int i=0;i<100;i++) {
      win.clear();
      drawGrid3DC(win,rx,rz);
      rx+=0.05;
      win.refresh();
    }
    for (int i=0;i<100;i++) {
      win.clear();
      drawGrid3DC(win,rx,rz);
      rz+=0.05;
      win.refresh();
    }
    for (int i=0;i<100;i++) {
      win.clear();
      drawGrid3DC(win,rx,rz);
      rx+=0.05;
      rz+=0.01;
      win.refresh();
    }
  }
  return EXIT_SUCCESS;
}
//============================================================
