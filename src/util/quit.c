// quit.c

#include "common.h"

void quit(int err) {
  endwin();
  exit(err);
}
