#include "raylib.h"
#include "exercises.h"

void process_keyboard()
{
	if (stage == 25)
	{
		return;
	}
	if      (IsKeyPressed(KEY_RIGHT) && stage < STAGES - 2) 
	{
		stage++;
		reset_values();
	}
	else if (IsKeyPressed(KEY_LEFT) && stage > 0) 
	{
		stage--;
		reset_values();
	}
}
