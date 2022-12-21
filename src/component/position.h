#ifndef POSITION_H
#define POSITION_H

#include <stdbool.h>

#include "../util/vector.h"

struct PositionComponent {
  struct Vector position;
  bool has_camera_focus;
};

#endif
