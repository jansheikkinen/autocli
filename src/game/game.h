#ifndef GAME_H
#define GAME_H

#include "chunk.h"

struct Settings {
  size_t render_distance;
};

#define GET_RENDER_DISTANCE(game) (game->settings.render_distance)

struct World {
  struct Chunk** chunks;
  size_t size;
};

struct Game {
  struct World* world;
  struct Settings settings;
};

void init_game(struct Game*, struct Settings);
void init_default_settings(struct Settings*);

void init_world(struct Game*, struct World*);
void update_world(struct World*);

#endif
