#include "raylib.h"
#include "fonts.h"
#include "exercises.h"
#include "button.h"
#include "fade.h"

Vector2 button_arrow_position = {25,630};

void process_footer()
{
	if (exercise.stage == 25) {return;}

	// Calculate text offset once to center text
	if (exercise.exercises[exercise.stage].text_offset.x == 0)
	{
		int length = TextLength(exercise.exercises[exercise.stage].label);
		if (length % 2 == 0)
		{
			exercise.exercises[exercise.stage].text_offset.x = 640 - (length / 2 * 40);
		}
		else
		{
			exercise.exercises[exercise.stage].text_offset.x = 640 - ((length / 2 * 40) + 20);
		}
	}
	DrawTextEx(fonts.ubuntu_mono_80, exercise.exercises[exercise.stage].label, exercise.exercises[exercise.stage].text_offset, 80, 0, fonts.colour);

	if (Button(0, 630, 90, 90) && exercise.stage > 0)
	{
		exercise.stage--;
		fade.alpha = 0;
		exercise.time_remaining = exercise.exercises[exercise.stage].interval + 5;
	}

	if (Button(1190, 630, 90, 90) && exercise.stage < 24)
	{
		exercise.stage++;
		fade.alpha = 0;
		exercise.time_remaining = exercise.exercises[exercise.stage].interval + 5;
	}

	DrawTextEx(fonts.ubuntu_mono_80, "<>", button_arrow_position, 80, 1150, WHITE);
}
