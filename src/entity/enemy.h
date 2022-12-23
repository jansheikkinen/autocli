#ifndef ENEMY_H
#define ENEMY_H

#include "../game/chunk.h"
#include "../component/component.h"

void init_enemy_entity(struct Chunk*, const struct Vector*);

#define ENEMY_COMPONENTS \
  (POSITION_LOCK | RENDER_LOCK | COLLIDER_LOCK)

#endif
