#include "raylib.h"
#include "sounds.h"
#include "keyboard.h"
#include "buttons.h"
#include "exercises.h"

extern float screen_width;
extern float screen_height;
extern float aspect_ration;
extern RenderTexture2D virtual_screen;

float screen_offset;
float adjusted_screen_width;
float adjusted_screen_height;

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

	if (IsWindowResized())
	{
		screen_width = GetScreenWidth();
		screen_height = GetScreenHeight();
	}

	// Render to actual screen
	BeginDrawing();
		ClearBackground(BLACK);
		if (screen_width > screen_height * aspect_ration) // Greater than the expected aspect_ration
		{
			adjusted_screen_width = screen_height * aspect_ration;
			screen_offset = (screen_width - adjusted_screen_width) / 2;
			DrawTexturePro
			(
				virtual_screen.texture,
				(Rectangle){0, 0, 1280, -720},                                         // Source
				(Rectangle){screen_offset, 0, adjusted_screen_width, screen_height},   // Destination
				(Vector2){ 0, 0 },                                                     // Origin
				0.0f,                                                                  // Rotation
				WHITE                                                                  // Tint
			);

		}
		else 
		{
			adjusted_screen_height = screen_width / aspect_ration;
			screen_offset = (screen_height - adjusted_screen_height) / 2;
			DrawTexturePro
			(
				virtual_screen.texture,
				(Rectangle){0, 0, 1280, -720},                                         // Source
				(Rectangle){0, screen_offset, screen_width, adjusted_screen_height},   // Destination
				(Vector2){ 0, 0 },                                                     // Origin
				0.0f,                                                                  // Rotation
				WHITE                                                                  // Tint
			);
		}
	EndDrawing();
}

