#include <cstdlib>
#include <ctime>
#include "XWindow.h"
/***
    Pour compiler tapez :
     g++ -c XWindow.cpp
     g++ -L/usr/X11R6/lib -lX11 XWindow.o exo2bTD1.cpp -o exo2bTD1
*/
const int SIZE=100;
const int NUMBER_OF_POINT=1000;
int main()
{

  srand(time(NULL));

  XWindow win;
  win.setBackground(win.black());
  win.setForeground(win.white());
  win.clear();
  win.drawRectangle(320-SIZE/2,240-SIZE/2,SIZE,SIZE);
  for (int i=0;i<NUMBER_OF_POINT;++i)
    win.drawPoint(320-SIZE/2+int(double(rand())*double(SIZE)/RAND_MAX),240-SIZE/2+int(double(rand())*double(SIZE)/RAND_MAX));
  win.refresh();
  win.waitButtonRelease();
}






