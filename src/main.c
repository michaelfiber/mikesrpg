#include "raylib.h"

int main(void)
{

	InitWindow(800, 600, "Mike's RPG");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}