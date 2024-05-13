/*-*-c++-*-*/

#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/X.h>
#include <string>

typedef unsigned long Color;

class XWindow {
public:
  ///Construit une fenêtre de largeur wid et de hauteur heig.
  XWindow(unsigned int width=640, unsigned int height=480,
	  const std::string &name=std::string("X11 window"));
  ~XWindow();
  //===========================================================================
  ///Change le nom de la fenêtre par name.
  void setName(const std::string &name);
  ///Change la couleur d'avant plan.
  void setForeground(Color);
  ///Change la couleur d'arrière plan.
  void setBackground(Color);
  ///Change la largeur de ligne.
  void setLineWidth(unsigned w);
  //===========================================================================
  /***
      Permute le buffer utilisé pour l'affichage sur l'écran
      avec celui utilisé pour le dessin. (double buffer)
  */
  void refresh();
  ///Efface le buffer courant.
  void clear();
  //===========================================================================
  ///Renvoie vraie si un boutton de la souris est relaché.
  bool isButtonRelease();
  ///Attend un relachement de bouton de souris.
  void waitButtonRelease ();
  ///Dessine un rectangle plein dans le buffer courant.
  void fillRectangle(unsigned x, unsigned y, unsigned width, unsigned height);
  ///Dessine un rectangle dans le buffer courant.
  void drawRectangle(unsigned x,unsigned y,unsigned width,unsigned height);
  ///Affiche le texte txt à la position x,y dans le buffer courant.
  void drawString(int x,int y,const std::string &txt);
  ///Dessine un point dans le buffer courant.
  void drawPoint(int x, int y); 
  ///Dessine une ligne dans le buffer courant.
  void drawLine(unsigned x,unsigned y,unsigned x1,unsigned y1);
  ///Dessine un cercle dans le buffer courant.
  void drawCircle(int x, int y, unsigned r);
  ///Dessine un cercle plein dans le buffer courant.
  void fillCircle(int x,int y,unsigned r);
  //===========================================================================
  ///Retourne la largeur de la fenêtre.
  unsigned getWidth() const;
  ///Retourne la hauteur de la fenêtre.
  unsigned getHeight() const;
  ///Renvoie la couleur d'avant plan.
  Color getForeground() const;
  ///Renvoie la couleur d'arrière plan.
  Color getBackground() const;
  ///Renvoie la couleur noire.
  Color black() const;
  ///Renvoie la couleur blanche.
  Color white() const;

protected:
  Pixmap createPixmapFromBitmapData(char *data,unsigned wid,unsigned heig);
  Pixmap createBitmapFromData(char *data,unsigned wid,unsigned heig);
  int readBitmapFile(char *filename,unsigned *wid,unsigned *heig,Pixmap *p,int *xx,int *yy);
  void copyArea(Drawable src,int src_x,int src_y,int w,int h,int dest_x,int dest_y);
  void mapRaised();
  void waitExposure();
  int getScreenNumber() const;
  int pending();
  void flushEvent();

private:
  Display *dpy;
  Window win;
  GC gc;
  int screenNumber;
  unsigned width,height;
  Color blackColor;
  Color whiteColor;
  Color backgroundColor;
  Color foregroundColor;
  Pixmap pixm;
};

inline void XWindow::drawString(int x, int y, const std::string &txt) {
  XDrawString(dpy,pixm,gc,x,y,txt.c_str(),txt.size());
}

inline int XWindow::pending() { 
  return XPending(dpy);
}

inline Color XWindow::black() const {
  return blackColor;
}

inline Color XWindow::white() const {
  return whiteColor;
}

inline void XWindow::mapRaised () { 
  XMapRaised(dpy,win); 
}

inline void XWindow::drawPoint(int x, int y) { 
  XDrawPoint(dpy,pixm,gc, x, y); 
}

inline void XWindow::setLineWidth(unsigned w) { 
  XSetLineAttributes(dpy, gc,w, LineSolid,CapNotLast,JoinRound); 
}

inline void XWindow::drawLine(unsigned x, unsigned y, unsigned x1, unsigned y1) {
  XDrawLine(dpy,pixm,gc,x,y,x1,y1);
}

inline void XWindow::drawRectangle(unsigned x, unsigned y, unsigned width, unsigned height) {
  XDrawRectangle(dpy, pixm, gc, x, y, width, height);
}

inline void XWindow::drawCircle(int x, int y, unsigned r) {
  XDrawArc(dpy, pixm, gc, x, y, r, r, 0, 360*64);
}

inline void XWindow::fillCircle(int x, int y, unsigned r) {
  XFillArc(dpy, pixm, gc, x, y, r, r, 0, 360*64);
}

inline unsigned XWindow::getWidth() const { 
  return width; 
}

inline unsigned XWindow::getHeight() const { 
  return height; 
} 

inline void XWindow::fillRectangle(unsigned x, unsigned y, unsigned width, unsigned height) {
  XFillRectangle(dpy,pixm,gc,x,y,width,height);
}

inline Pixmap XWindow::createPixmapFromBitmapData(char *data, unsigned width, unsigned height) {
  return XCreatePixmapFromBitmapData(dpy,pixm,data,width,height,white(),black(),DefaultDepth(dpy,screenNumber));
}

inline Pixmap XWindow::createBitmapFromData(char *data, unsigned width, unsigned height) {
  return XCreateBitmapFromData(dpy,pixm,data,width,height);
}

inline int XWindow::readBitmapFile(char *filename, unsigned *width, unsigned *height,
				   Pixmap *p, int *xx, int *yy) {
  return XReadBitmapFile(dpy,pixm,filename,width,height,p,xx,yy);
}

inline void XWindow::copyArea(Drawable src, int src_x, int src_y,
			      int w, int h, int dest_x, int dest_y) {
  XCopyArea(dpy, src, pixm, gc, src_x, src_y, w, h, dest_x, dest_y);
}

inline void XWindow::setName(const std::string &name) { 
  XStoreName(dpy, win, name.c_str()); 
}

inline Color XWindow::getForeground() const {
  return foregroundColor;
}

inline Color XWindow::getBackground() const {
  return backgroundColor;
}

inline int XWindow::getScreenNumber() const {
  return screenNumber;
}

#endif










