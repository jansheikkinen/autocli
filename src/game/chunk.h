#ifndef CHUNK_H
#define CHUNK_H

#include "../util/common.h"
#include "../util/vector.h"

#include "../component/render.h"
#include "../component/position.h"
#include "../component/collider.h"
#include "../component/controller.h"

struct EntityManager {
  size_t entities;

  size_t entity_locks[ENTITY_LIMIT];

  struct RenderComponent renders[ENTITY_LIMIT];
  struct PositionComponent positions[ENTITY_LIMIT];
  struct ColliderComponent colliders[ENTITY_LIMIT];
  struct ControllerComponent controllers[ENTITY_LIMIT];
};

struct Chunk {
  struct Vector position;
  struct EntityManager entity_manager;
  size_t tiles[CHUNK_SIZE * CHUNK_SIZE];
};

void init_debug_chunk(struct Chunk*);
void update_chunk(struct Chunk*);

#define CHUNK_TO_WORLD_POS(chunk, chunkPos) ((struct Vector){ \
    ((chunk)->position.x * CHUNK_SIZE) + (chunkPos)->x, \
    ((chunk)->position.y * CHUNK_SIZE) + (chunkPos)->y  \
  })

#endif
