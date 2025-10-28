#include "raylib.h"
#include "exercises.h"
#include "fade.h"

Fade_variables fade = {0};

Rectangle foreground = {0,0,1280,720};
Color colour = WHITE;

void process_fade()
{
	if (exercise.stage >= 25) {return;}
	// increment fade
	if (exercise.time_remaining > exercise.exercises[exercise.stage].interval + exercise.delay-1)
	{
		fade.alpha -= GetFrameTime()*3;
	}
	else if (exercise.time_remaining  == 0)
	{
		fade.alpha += GetFrameTime()*3;
	}

	// keep fade in bounds
	if (fade.alpha < 0)
	{
		fade.alpha = 0;
	}
	else if (fade.alpha > 1)
	{
		fade.alpha = 1;
	}

	colour.a = fade.alpha * 255;

	DrawRectangleRec(foreground, colour);
}
