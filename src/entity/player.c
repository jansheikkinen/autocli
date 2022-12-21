// player.c

#include "player.h"

void init_player_entity(struct Chunk* chunk) {
  struct EntityManager* mgr = &chunk->entity_manager;
  size_t entities = mgr->entities++;

  mgr->entity_locks[entities] = POSITION_LOCK | CONTROLLER_LOCK;
  mgr->positions[entities] = (struct PositionComponent){ { 2, 2 }, true };
  mgr->controllers[entities] = (struct ControllerComponent){
    'q', 'w', 's', 'a', 'd'
  };
}
