// chunk.c

#include "chunk.h"
#include "../util/tiles.h"
#include "../system/render.h"
#include "../system/handle_input.h"

void init_debug_chunk(struct Chunk* chunk) {
  for(size_t y = 0; y < CHUNK_SIZE; y++) {
    for(size_t x = 0; x < CHUNK_SIZE; x++) {
      struct Vector chunk_pos = (struct Vector){ x, y };
      size_t index = vec_to_index(&chunk_pos, CHUNK_SIZE);

      chunk->tiles[index] = (x == 0 || y == 0) ? TILE_WALL : TILE_GROUND;
    }
  }
}

void render_tiles(const struct Chunk* chunk) {
  for(size_t chunk_y = 0; chunk_y < CHUNK_SIZE; chunk_y++) {
    for(size_t chunk_x = 0; chunk_x < CHUNK_SIZE; chunk_x++) {
      struct Vector chunk_pos = (struct Vector){ chunk_x, chunk_y };
      struct Vector world_pos = CHUNK_TO_WORLD_POS(chunk, &chunk_pos);
      struct Vector screen_pos = mult_scalar_vec(&world_pos, TILE_SIZE);

      size_t index = vec_to_index(&chunk_pos, CHUNK_SIZE);
      struct TileData tile_data = GET_TILEDATA(chunk->tiles[index]);
      mvaddch(screen_pos.y, screen_pos.x, tile_data.tile);
    }
  }
}

void update_chunk(struct Chunk* chunk) {
  render_tiles(chunk);

  for(size_t entity = 0; entity < chunk->entity_manager.entities; entity++) {
    update_input(chunk, entity);
    update_render(chunk, entity);
  }
}
