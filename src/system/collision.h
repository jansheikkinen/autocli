#ifndef COLLISION_H
#define COLLISION_H

#include "../game/chunk.h"

// the IDs of the entities in the adjacent tiles, or ENTITY_LIMIT if none
struct Collision {
  int north;
  int south;
  int west;
  int east;
};

struct Collision has_collisions(struct Chunk*, size_t);

#define HAS_COLLISION(collision, direction) \
  ((collision)->direction != ENTITY_LIMIT)

#endif
