#ifndef TILES_H
#define TILES_H

#include "common.h"

enum Tiles {
  TILE_NONE,
  TILE_GROUND,
  TILE_WALL,
  TILE_PLAYER,
  TILE_ENEMY,
};

struct TileData {
  int tile;
  attr_t attrs;
};

extern struct TileData TILE_DATA[];

#define GET_TILEDATA(tile) (TILE_DATA[tile])

#endif
