#include <cstdlib>
#include "XWindow.h"
/***
    Pour compiler tapez :
     g++ -c XWindow.cpp
     g++ -L/usr/X11R6/lib -lX11 XWindow.o exo2bTD1.cpp -o exo2bTD1
*/
const int SIZE=10;
const int NUMBER_OF_CELL=20;

int main()
{
  XWindow win;
  win.setBackground(win.black());
  win.setForeground(win.white());
  win.clear();
  for (int i=0;i<=NUMBER_OF_CELL;++i)
    {
      win.drawLine(320-NUMBER_OF_CELL*SIZE/2+SIZE*i
		   ,240-NUMBER_OF_CELL*SIZE/2
		   ,320-NUMBER_OF_CELL*SIZE/2+SIZE*i
		   ,240+NUMBER_OF_CELL*SIZE/2
		   );
      win.drawLine(320-NUMBER_OF_CELL*SIZE/2
		   ,240-NUMBER_OF_CELL*SIZE/2+SIZE*i
		   ,320+NUMBER_OF_CELL*SIZE/2
		   ,240-NUMBER_OF_CELL*SIZE/2+SIZE*i
		   );
    }
  win.refresh();
  win.waitButtonRelease();
}
