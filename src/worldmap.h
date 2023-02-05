#ifndef WORLDMAP_H
#define WORLDMAP_H

#include "raylib.h"

#define BIOME_WATER 0
#define BIOME_SAND 1
#define BIOME_GRASS 2
#define BIOME_ROCKY 3
#define BIOME_SNOW 4
#define BIOME_PEAK 5

#define BIOME_COUNT 6

Image GenerateWorldMapImage(int width, int height);

#endif