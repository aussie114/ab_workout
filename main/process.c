#include "raylib.h"
#include "sounds.h"
#include "keyboard.h"
#include "buttons.h"
#include "exercises.h"

void process(void)
{
	if (IsKeyPressed(KEY_S))
	{
		PlaySound(beep);
	}
	BeginDrawing();
	ClearBackground(RAYWHITE);
	process_keyboard();
	process_exercises();
	process_buttons();
	EndDrawing();
}

















/*
#include "raylib.h"
#include "sound.h"
#include "exercises.h"

Vector2 mouse_position = {0,0};
int button_border_size = 4;
Color button_colour = {25, 116, 186, 255};
Rectangle previous_button        = {1146, 14, 120, 120};
Rectangle next_button     = {1142, 582, 128, 128};


void process(void)
{
	if (audio_loaded == 0)
	{
	    BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("press a to continue...", 0, 0, 100, BLACK);

		if (GetKeyPressed() == 'A')
		{
			InitAudioDevice();
//			load_sounds();
			audio_loaded = 1;
		}
	    EndDrawing();
		return;	
	}

    BeginDrawing();

	mouse_position = GetMousePosition();
	ClearBackground(RAYWHITE);

	process_exercises();

	// Previous button
	if (CheckCollisionPointRec(mouse_position, previous_button))
	{
		DrawRectangleRec(previous_button, button_colour);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && stage > 0)
		{
			exercises[stage].time_remaining = exercises[stage].interval + 3;
			stage--;
		}
	}
	else
	{
		DrawRectangleRec(previous_button, BLACK);
		DrawRectangle(
			previous_button.x + button_border_size, 
			previous_button.y + button_border_size,
			previous_button.width - button_border_size * 2,
			previous_button.height - button_border_size * 2,
			button_colour
		);
	}



	// next_button
	if (CheckCollisionPointRec(mouse_position, next_button))
	{
		DrawRectangleRec(next_button, GREEN);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && stage < STAGES - 1)
		{
			exercises[stage].time_remaining = exercises[stage].interval + 3;
			stage++;
		}
	}
	else
	{
		DrawRectangleRec(next_button, BLACK);
	}

    EndDrawing();
}
*/
