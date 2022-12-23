// enemy.c

#include "enemy.h"
#include "../util/tiles.h"

void init_enemy_entity(struct Chunk* chunk, const struct Vector* pos) {
  struct EntityManager* mgr = &chunk->entity_manager;
  size_t entities = mgr->entities++;

  mgr->entity_locks[entities] =
    POSITION_LOCK | RENDER_LOCK | COLLIDER_LOCK;
  mgr->positions[entities] = (struct PositionComponent){ *pos, true };
  mgr->renders[entities] = (struct RenderComponent){ TILE_ENEMY, true };
  mgr->colliders[entities] = (struct ColliderComponent){ true };
}
