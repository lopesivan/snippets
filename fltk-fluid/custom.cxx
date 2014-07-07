#include <cstdio>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include "hello.h"
using namespace std;

int main() {
  printf("Hello world!\n");
  MainWindow* w = new MainWindow(400,400, "Application");
  w->end();
  w->show();
  return Fl::run();

  return 0;
}
