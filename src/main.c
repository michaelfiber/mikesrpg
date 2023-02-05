#include "raylib.h"
#include "global.h"
#include "npc.h"
#include "worldmap.h"

int GameSeed = 12345;

int NpcWidth = 16;
int NpcHeight = 32;

void Load();
void Update();
void Draw();
void Unload();

Texture2D worldMapTex = {0};

int main(void)
{
	InitWindow(640, 480, "Mike's RPG");

	TraceLog(LOG_INFO, TextFormat("Building game with GameSeed %d", GameSeed));

	Load();

	while (!WindowShouldClose())
	{
		Update();
		Draw();
	}

	Unload();

	CloseWindow();

	return 0;
}

void Update()
{
}

void Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawTexture(worldMapTex, 0, 0, WHITE);
	DrawFPS(10, 10);
	EndDrawing();
}

void Load()
{
	Image worldmap = GenerateWorldMapImage(400, 400);
	worldMapTex = LoadTextureFromImage(worldmap);
	UnloadImage(worldmap);
}

void Unload()
{
	UnloadTexture(worldMapTex);
}