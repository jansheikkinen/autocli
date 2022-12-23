// player.c

#include "player.h"
#include "../util/tiles.h"

void init_player_entity(struct Chunk* chunk) {
  struct EntityManager* mgr = &chunk->entity_manager;
  size_t entities = mgr->entities++;

  mgr->entity_locks[entities] =
    POSITION_LOCK | RENDER_LOCK | COLLIDER_LOCK | CONTROLLER_LOCK;
  mgr->positions[entities] = (struct PositionComponent){ { 2, 2 }, true };
  mgr->renders[entities] = (struct RenderComponent){ TILE_PLAYER, true };
  mgr->colliders[entities] = (struct ColliderComponent){ true };
  mgr->controllers[entities] = (struct ControllerComponent){
    'q', 'w', 's', 'a', 'd'
  };
}
