#include "raylib.h"
#include "colours.h"
#include "exercises.h"

Texture2D play_button_normal;
Texture2D play_button_hover;
Texture2D pause_button_normal;
Texture2D pause_button_hover;

Rectangle play_pause_button = {   0,   0, 90, 90};

Texture2D navigation_button_normal;
Texture2D navigation_button_hover;

Rectangle previous_button   = {   0, 630, 90, 90};
Rectangle next_button       = {1190, 630, 90, 90};


void setup_buttons(void)
{
	navigation_button_normal = LoadTexture("data/navigation_button_normal.png");
	navigation_button_hover  = LoadTexture("data/navigation_button_hover.png");

	play_button_normal = LoadTexture("data/play_button_normal.png");
	play_button_hover  = LoadTexture("data/play_button_hover.png");

	pause_button_normal = LoadTexture("data/pause_button_normal.png");
	pause_button_hover = LoadTexture("data/pause_button_hover.png");
}

void process_buttons(void)
{
	if (stage == 25)
	{
		return;
	}

	// Play/Pause button
	
	if (paused)
	{
		if (CheckCollisionPointRec(GetMousePosition(), play_pause_button))
		{
			DrawTextureRec(play_button_hover,  (Rectangle){0,0,90,90},  (Vector2){0, 0}, WHITE);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && time_remaining < exercises[stage].interval)
			{
				paused = !paused;
			}
		}
		else
		{
			DrawTextureRec(play_button_normal,  (Rectangle){0,0,90,90}, (Vector2){0, 0}, WHITE);
		}
	}
	else
	{
		if (CheckCollisionPointRec(GetMousePosition(), play_pause_button))
		{
			DrawTextureRec(pause_button_hover,  (Rectangle){0,0,90,90},   (Vector2){0, 0}, WHITE);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && time_remaining < exercises[stage].interval)
			{
				paused = !paused;
			}
		}
		else
		{
			DrawTextureRec(pause_button_normal,  (Rectangle){0,0,90,90},  (Vector2){0, 0}, WHITE);
		}
	}


	// Previous button
	if (CheckCollisionPointRec(GetMousePosition(), previous_button))
	{
		DrawTextureRec(navigation_button_hover,  (Rectangle){0,0,90,90}, (Vector2){0, 630}, WHITE);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && stage > 0)
		{
			stage--;
			reset_values();
		}
	}
	else
	{
		DrawTextureRec(navigation_button_normal, (Rectangle){0,0,90,90}, (Vector2){0, 630}, WHITE);
	}

	// Next button
	if (CheckCollisionPointRec(GetMousePosition(), next_button))
	{
		DrawTextureRec(navigation_button_hover,  (Rectangle){0,0,-90,90}, (Vector2){1190, 630}, WHITE);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && stage < STAGES - 2)
		{
			stage++;
			reset_values();
		}
	}
	else
	{
		DrawTextureRec(navigation_button_normal, (Rectangle){0,0,-90,90}, (Vector2){1190, 630}, WHITE);

	}














}

