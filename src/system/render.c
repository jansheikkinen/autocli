// render.c

#include "render.h"
#include "../component/component.h"
#include "../util/common.h"
#include "../util/tiles.h"

static void render_entity(const struct Vector* screen_pos,
    const struct TileData* tile_data) {
  attron(tile_data->attrs);
  mvaddch(screen_pos->y, screen_pos->x, tile_data->tile);
  attroff(tile_data->attrs);
}

void update_render(struct Chunk* chunk, size_t entity) {
  struct EntityManager* mgr = &chunk->entity_manager;

  if(!HAS_COMPONENTS(mgr, entity, RENDER_LOCK | POSITION_LOCK)) return;

  struct RenderComponent* render = &mgr->renders[entity];
  struct PositionComponent* pos = &mgr->positions[entity];

  if(!render->is_visible) return;

  struct Vector screen_pos =
    mult_scalar_vec(
        &CHUNK_TO_WORLD_POS(chunk, &pos->position),
        TILE_SIZE
    );

  struct TileData tile_data = GET_TILEDATA(render->id);
  render_entity(&screen_pos, &tile_data);
}
