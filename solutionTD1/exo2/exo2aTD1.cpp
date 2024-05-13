#include "XWindow.h"
/***
    Pour compiler tapez :
    g++ -c XWindow.cpp
    g++ -L/usr/X11R6/lib -lX11 XWindow.o exo2aTD1.cpp -o exo2aTD1
*/

#include <cstdlib>

using namespace std;

int main() {
  XWindow win;
  win.setBackground(win.black());
  win.setForeground(win.white());
  win.clear();
  win.drawString(280,235,string("Hello World"));
  win.refresh();
  win.waitButtonRelease();
  return EXIT_SUCCESS;
}









