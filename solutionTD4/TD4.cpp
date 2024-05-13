#include <cstdlib>
#include <iostream>
#include <list>
#include <cmath>
#include "XWindow.h"
#include "Vector4D.h"
#include "Matrix4x4.h"
#include "Matrix.h"
#include "Particule.h"
#include <ctime>

using namespace std;

static const int X_SIZE  = 640;
static const int Y_SIZE  = 480;
static const int X_SIZEH = X_SIZE/2;
static const int Y_SIZEH = Y_SIZE/2;
static const int N_PART  = 20000;
static const float GRID_WIDTH = 20;
static const int GRID_SIZE = 10;

Matrix<Vector4D, GRID_SIZE> grille3D;
Matrix<Vector4D, GRID_SIZE> tmpGrid;

void buildGrille(Matrix<Vector4D,GRID_SIZE> &grille3D) {
  float dx = GRID_WIDTH/(float)(GRID_SIZE - 1);
  float dz = GRID_WIDTH/(float)(GRID_SIZE - 1);
  for (int i=0; i<GRID_SIZE; ++i)
    for (int j=0; j<GRID_SIZE; ++j)
      grille3D[i][j] = Vector4D(dx * float(i) - GRID_WIDTH/2. ,
				0 ,
				dz * float(j) - GRID_WIDTH/2., 1);
}

void drawGrid3DCPP(XWindow &win, const Matrix4x4 &projection) {
  int X_SIZE  = win.getWidth();
  int Y_SIZE  = win.getHeight();
  int X_SIZEH = X_SIZE/2;
  int Y_SIZEH = Y_SIZE/2;

  for (int i=0;i<GRID_SIZE;++i)
    for (int j=0;j<GRID_SIZE;++j) {
      Vector4D tmp =  projection * grille3D[i][j];
      tmp *= 1./tmp[3];
      tmp[0] += X_SIZEH;
      tmp[1] += Y_SIZEH;
      tmpGrid[i][j] = tmp;
    }

  for (int i=0;i<GRID_SIZE-1;++i)
    for (int j=0;j<GRID_SIZE-1;++j) {
      if ((i%2 == 0 && j%2 ==0) || (i%2 == 1 && j%2 ==1))
	win.setForeground(0x000077);
      else
	win.setForeground(0x007700);

	win.fillQuad((int)tmpGrid[i][j][0],
		     (int)tmpGrid[i][j][1],
		     (int)tmpGrid[i+1][j][0],
		     (int)tmpGrid[i+1][j][1],
		     (int)tmpGrid[i+1][j+1][0],
		     (int)tmpGrid[i+1][j+1][1],
		     (int)tmpGrid[i][j+1][0],
		     (int)tmpGrid[i][j+1][1]);
    }
}

int main() {
  XWindow win(X_SIZE,Y_SIZE);
  win.setBackground(win.black());
  win.setForeground(win.white());
  float rx = - M_PI / 6.0;
  float rz = M_PI;
  float ry = 3.14;

  buildGrille(grille3D);
  Particule *lPart[N_PART];

   for (int i=0;i<N_PART;++i) {
     float alpha = 2.*M_PI*(float(rand())/float(RAND_MAX));
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
    projection.projection(800,40); //projection on screen
    projection = projection * modelView;


    win.setForeground(0xFF0000);
    drawGrid3DCPP(win, projection);
    Vector4D tmpVect;
    for (int i=0; i<N_PART; ++i) {
      tmpVect  =  projection * (lPart[i])->getPosition();
      win.setForeground(0x9999FF);
      //      win.drawPoint((int)(tmpVect[0]/tmpVect[3] + X_SIZEH),
      //		    (int)(tmpVect[1]/tmpVect[3] + Y_SIZEH));
      win.drawCircle((int)(tmpVect[0]/tmpVect[3] + X_SIZEH),
		     (int)(tmpVect[1]/tmpVect[3] + Y_SIZEH), 1);
      (lPart[i])->move();
    }
    win.refresh();
    //    rx += 0.01;
    ry += 0.005;
    ++count ;
    if (count == 200) {
      clock_t delta = clock() - tmp_clock;
      float fps = 200.0 / (float(delta) / float(CLOCKS_PER_SEC));
      cout << " Frame per second : " << fps << endl;
      tmp_clock = clock();
      count = 0;
    }

  }
  return EXIT_SUCCESS;
}
