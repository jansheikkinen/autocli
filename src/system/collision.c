// collision.c

#include "collision.h"
#include "../component/component.h"

// TODO: handle collision between chunks
struct Collision has_collisions(struct Chunk* chunk, size_t entity) {
  struct EntityManager* mgr = &chunk->entity_manager;
  struct Collision collision = {
    ENTITY_LIMIT, ENTITY_LIMIT, ENTITY_LIMIT, ENTITY_LIMIT
  };

  for(size_t entity2 = 0; entity2 < mgr->entities; entity2++) {
    if(!HAS_COMPONENTS(mgr, entity2, COLLIDER_LOCK | POSITION_LOCK))
      return collision;

    struct Vector* pos1 = &mgr->positions[entity].position;
    struct Vector* pos2 = &mgr->positions[entity2].position;

    if(vec_eq(&INIT_VEC(pos1->x, pos1->y - 1), pos2))
      collision.north = entity2;
    else if(vec_eq(&INIT_VEC(pos1->x, pos1->y + 1), pos2))
      collision.south = entity2;
    else if(vec_eq(&INIT_VEC(pos1->x - 1, pos1->y), pos2))
      collision.west = entity2;
    else if(vec_eq(&INIT_VEC(pos1->x + 1, pos1->y), pos2))
      collision.east = entity2;
  }

  return collision;
}
