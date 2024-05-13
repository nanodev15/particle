#include <cstdlib>
#include <iostream>
#include "XWindow.h"

using namespace std;

static const unsigned long DEFAULT_MASK = ButtonReleaseMask | ExposureMask;
//====================================================================
XWindow::XWindow(unsigned width, unsigned height, const string &name):
  width(width),
  height(height) {
  dpy = XOpenDisplay(NULL);
  if (!dpy) {
    cerr << "can't open display";
    exit(-1);
  }
  screenNumber = DefaultScreen(dpy);
  foregroundColor=blackColor = BlackPixel(dpy, getScreenNumber());
  backgroundColor=whiteColor = WhitePixel(dpy, getScreenNumber());
  win = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 100,
			    100, width, height, 0, white(), black());
  XSelectInput(dpy, win, DEFAULT_MASK|ButtonReleaseMask|ButtonPressMask );
  XGCValues gcv;
  gc = XCreateGC(dpy,win,0,&gcv);
  XSetFont(dpy, gc, XLoadFont(dpy, "-adobe-courier-*-*-normal-*-12-*-*-*-*-*-*-*"));
  pixm = XCreatePixmap(dpy, win, width, height, DefaultDepth(dpy, screenNumber));
  XFillRectangle(dpy, pixm, gc, 0, 0, width, height);
  XMapWindow(dpy, win);
  XMapRaised(dpy, win);
  waitExposure();
  setName(name);
}
//====================================================================
XWindow::~XWindow() {
  XFreeGC(dpy,gc);
  XFreePixmap(dpy, pixm);
  XDestroyWindow(dpy, win);
  XCloseDisplay(dpy);
}
//====================================================================
void XWindow::waitButtonRelease() {
  while(!isButtonRelease()) flushEvent();
}
//====================================================================
void XWindow::waitExposure() {
  XEvent ev;
  while(!XCheckWindowEvent(dpy, win, ExposureMask, &ev));
}
//====================================================================
void XWindow::clear() {
  Color save=getForeground();
  setForeground(backgroundColor);
  XFillRectangle(dpy, pixm, gc, 0, 0, width, height);
  setForeground(save);
}
//====================================================================
void XWindow::setForeground(Color color) {
  XSetForeground(dpy, gc, color);
  foregroundColor = color;
}
//====================================================================
void XWindow::setBackground(Color color) {
  XSetBackground(dpy, gc, color);
  backgroundColor = color;
}
//====================================================================
void XWindow::refresh() {
  XCopyArea(dpy, pixm, win, gc, 0, 0, width, height, 0, 0);
  XFlush(dpy);
}
//====================================================================
void XWindow::flushEvent() {
  XEvent ev;
  while (XPending(dpy))
    XNextEvent(dpy, &ev);
}
//====================================================================
bool XWindow::isButtonRelease() {
  XEvent ev;
  return XCheckWindowEvent(dpy, win, ButtonReleaseMask, &ev);
}
//====================================================================




