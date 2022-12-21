// game.c

#include "game.h"

void init_game(struct Game* game, struct Settings settings) {
  game->settings = settings;
}

// TODO: add keybinds to settings, then set controller component's controls
// to these ones by default
void init_default_settings(struct Settings* settings) {
  settings->render_distance = 8;
}

void init_chunks(struct Game* game, struct World* world) {
  size_t render_distance = GET_RENDER_DISTANCE(game);

  for(size_t y = 0; y < render_distance; y++) {
    for(size_t x = 0; x < render_distance; x++) {
      struct Vector pos = (struct Vector){ x, y };
      size_t index = vec_to_index(&pos, render_distance);

      world->chunks[index] = malloc(sizeof(struct Chunk));
      world->chunks[index]->position = pos;

      init_debug_chunk(world->chunks[index]);
    }
  }
}

void init_world(struct Game* game, struct World* world) {
  size_t render_distance = GET_RENDER_DISTANCE(game);

  world->size = render_distance * render_distance;
  world->chunks = calloc(world->size, sizeof(world->chunks));
  init_chunks(game, world);
}

void update_world(struct World* world) {
  for(size_t i = 0; i < world->size; i++) {
    update_chunk(world->chunks[i]);
  }
}
