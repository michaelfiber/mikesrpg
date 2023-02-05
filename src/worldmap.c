#include "raylib.h"
#include "global.h"
#include "worldmap.h"

#define FNL_IMPL 1
#include "fastnoiselite.h"
#include "stdlib.h"

unsigned char *heights = NULL;

Image GenerateHeightMapImage(int width, int height)
{
	unsigned char *data = (unsigned char *)MemAlloc(sizeof(unsigned char) * width * height);
	fnl_state noise = fnlCreateState();

	noise.noise_type = FNL_NOISE_OPENSIMPLEX2;
	noise.seed = GameSeed;

	int index = 0;
	int max = 0;

	float maxDistance = sqrtf(pow(width, 2) + pow(height, 2));

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int dx = abs(x - (width / 2));
			int dy = abs(y - (height / 2));
			float distance = sqrt((dx * dx) + (dy * dy));
			data[index++] = (fnlGetNoise2D(&noise, x, y) + 1) * 128 * pow((185 - distance) / maxDistance, 1.1);
			if (data[index - 1] > max)
				max = data[index - 1];
		}
	}

	float rate = (max * 1.0f) / 255;
	for (int i = 0; i < 256 * 256; i++)
	{
		data[i] = data[i] / rate;
	}

	Image heightmap = {
		.data = data,
		.format = PIXELFORMAT_UNCOMPRESSED_GRAYSCALE,
		.width = width,
		.height = height,
		.mipmaps = 1};

	return heightmap;
}

int GetBiome(int elevation)
{
	int biome = BIOME_WATER;
	if (elevation < 75)
	{
		biome = BIOME_WATER;
	}
	else if (elevation < 90)
	{
		biome = BIOME_SAND;
	}
	else if (elevation < 170)
	{
		biome = BIOME_GRASS;
	}
	else if (elevation < 225)
	{
		biome = BIOME_ROCKY;
	}
	else if (elevation < 250)
	{
		biome = BIOME_SNOW;
	}
	else
	{
		biome = BIOME_PEAK;
	}
	return biome;
}

Color GetBiomeColor(int biome)
{
	Color color = BLUE;

	switch (biome)
	{
	case BIOME_WATER:
		color = BLUE;
		break;
	case BIOME_PEAK:
		color = WHITE;
		break;
	case BIOME_ROCKY:
		color = BROWN;
		break;
	case BIOME_GRASS:
		color = GREEN;
		break;
	case BIOME_SNOW:
		color = LIGHTGRAY;
		break;
	case BIOME_SAND:
		color = YELLOW;
		break;
	}

	return color;
}

Image GenerateWorldImageFromHeightMap(Image heightMap)
{
	if (heights != NULL)
	{
		MemFree(heights);
		heights = NULL;
	}

	heights = (unsigned char *)MemAlloc(sizeof(unsigned char) * heightMap.width * heightMap.height);

	Image worldImage = (Image){
		.data = MemAlloc(sizeof(Color) * heightMap.width * heightMap.height),
		.width = heightMap.width,
		.height = heightMap.height,
		.mipmaps = 1,
		.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8};

	Color *colorData = (Color *)(worldImage.data);

	unsigned char *pixels = heightMap.data;

	for (int i = 0; i < heightMap.width * heightMap.height; i++)
	{
		int biome = GetBiome(pixels[i]);
		heights[i] = pixels[i];
		colorData[i] = GetBiomeColor(biome);
	}

	return worldImage;
}

Image GenerateWorldMapImage(int width, int height)
{
	Image heightMap = GenerateHeightMapImage(width, height);

	Image worldMap = GenerateWorldImageFromHeightMap(heightMap);

	UnloadImage(heightMap);

	return worldMap;
}