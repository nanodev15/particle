/**
 Author: David Auber
 Email : auber@labri.fr
 Last modification : 01/09/2004
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by  
 the Free Software Foundation; either version 2 of the License, or     
 (at your option) any later version.
*/

#include <cstdlib>
#include "XWindow.h"

using namespace std;
const int SIZE=100;
const int NUMBER_OF_POINT=1000;
const double SPEEDX=1;
const double SPEEDY=1;
const double G=0.1;
const double AMORT=0.8;

int main() {
  XWindow win;
  double x,y;
  x=y=0;
  double speedX=SPEEDX;
  double speedY=SPEEDY;
  double FLOOR = 479;
  win.setBackground(win.black());
  win.setForeground(win.white());
  win.clear();
  while(x<640) {
    win.drawPoint(int(x),int(y));
    x+=speedX;
    speedY+=G;
    y+=speedY;
    if (y>FLOOR) {
      speedY *= -AMORT;
      y = FLOOR;
    }
    win.refresh();
  }
  win.waitButtonRelease();
  return EXIT_SUCCESS;
}
