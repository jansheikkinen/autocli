#ifndef PLAYER_H
#define PLAYER_H

#include "../game/chunk.h"
#include "../component/component.h"

void init_player_entity(struct Chunk*);

#define PLAYER_COMPONENTS \
  (POSITION_LOCK | RENDER_LOCK | COLLIDER_LOCK | CONTROLLER_LOCK)

#endif
