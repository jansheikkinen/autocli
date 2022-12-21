#ifndef PLAYER_H
#define PLAYER_H

#include "../chunk.h"
#include "../component/component.h"

void init_player_entity(struct Chunk*);

#define PLAYER_COMPONENTS (POSITION_LOCK | CONTROLLER_LOCK)

#endif
