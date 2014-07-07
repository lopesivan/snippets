#include <FL/Fl.H>

void Button_CB(Fl_Widget* o, void* v) {
  printf("Button Callback. User data='%s'\n", (const char*)v);
}

void WinQuit_CB(Fl_Widget* o, void* v) {
  printf("Window Quit Callback\n");
  exit(0);
}
