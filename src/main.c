#include "raylib.h"
#include "global.h"

int GameSeed = 12345;

void Update();
void Draw();

int main(void)
{

	InitWindow(640, 480, "Mike's RPG");

	TraceLog(LOG_INFO, TextFormat("Building game with GameSeed %d", GameSeed));

	while (!WindowShouldClose())
	{
		Update();
		Draw();
	}

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
	DrawFPS(10, 10);
	EndDrawing();
}