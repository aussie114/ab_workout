#include "raylib.h"
#include "sounds.h"
#include "keyboard.h"
#include "buttons.h"
#include "exercises.h"

extern RenderTexture2D virtual_screen;

void process(void)
{
	if (IsKeyPressed(KEY_S))
	{
		PlaySound(beep);
	}
	// Render to virtual screen
	BeginTextureMode(virtual_screen);
		ClearBackground(RAYWHITE);
		process_keyboard();
		process_exercises();
		process_buttons();
	EndTextureMode();

	// Render to actual screen
	BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexturePro
		(
			virtual_screen.texture,
			(Rectangle){0.0f, 0.0f, 1280.0f, -720.0f},                             // Source
			(Rectangle){0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},  // Destination
			(Vector2){ 0, 0 },                                                     // Origin
			0.0f,                                                                  // Rotation
			WHITE                                                                  // Tint
		);
	EndDrawing();
}

