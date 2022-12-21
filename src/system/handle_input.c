// handle_input.c

#include "handle_input.h"
#include "../util/quit.h"
#include "../component/component.h"

void handle_input(struct Chunk* chunk, size_t entity) {
  struct EntityManager* mgr = &chunk->entity_manager;

  if(!HAS_COMPONENTS(mgr, entity, CONTROLLER_LOCK)) return;
  struct ControllerComponent* ctl = &mgr->controllers[entity];

  // controls available to all controllers
  int ch = getch();
  if(ch == ctl->quit) quit(0);

  if(!HAS_COMPONENTS(mgr, entity, POSITION_LOCK)) return;
  struct PositionComponent* pos = &mgr->positions[entity];

  // controls only available to controllers with positions
  if(ch == ctl->move_north)      pos->position.y += 1;
  else if(ch == ctl->move_south) pos->position.y -= 1;
  else if(ch == ctl->move_west)  pos->position.x -= 1;
  else if(ch == ctl->move_east)  pos->position.x += 1;
}
