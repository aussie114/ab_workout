#include "raylib.h"
#include "fonts.h"
#include "exercises.h"
#include "button.h"

Vector2 paused_position =        {505, 0};
Vector2 next_exercise_postition = {380, 0};
Vector2 time_position = {600,0};

Vector2 play_button[] = {
	{30,15},
	{30,73},
	{67,44}
};

Rectangle pause_button[] = {
	{33,15,5,58},
	{52,15,5,58}
};

void process_header()
{

	if (exercise.stage >= 25) {return;}


	if (exercise.paused)
	{
		if ( (int)(GetTime() * 2) % 2 ) {DrawTextEx(fonts.ubuntu_mono_80, "paused!", paused_position, 80, 0, RED);}
	}
	else if (exercise.time_remaining > exercise.exercises[exercise.stage].interval)
	{
		DrawTextEx(fonts.ubuntu_mono_80, "Next exercise", next_exercise_postition, 80, 0, fonts.colour);
	}
	else
	{
		DrawTextEx(fonts.ubuntu_mono_80, TextFormat("%02.0f", exercise.time_remaining), time_position, 80, 0, fonts.colour);
	}

	if (Button(0, 0, 90, 90) || IsKeyPressed(KEY_SPACE))
	{
		exercise.paused = !exercise.paused;
	}

	if (exercise.paused)
	{
		DrawTriangle(play_button[0], play_button[1], play_button[2], WHITE);
	}
	else
	{
		DrawRectangleRec(pause_button[0], WHITE);
		DrawRectangleRec(pause_button[1], WHITE);
	}
}
