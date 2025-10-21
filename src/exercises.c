#include "exercises.h"
#include "sounds.h"
#include "colours.h"

int paused = 0;
int stage = 0;
float time_remaining = 32;
int fade = 255;
Exercise exercises[STAGES];

void setup_exercises()
{
	exercises[ 0] = (Exercise){"plank",                    29, LoadTexture("data/plank.png")};
	exercises[ 1] = (Exercise){"plank twist",              29, LoadTexture("data/plank_twist.png")};
	exercises[ 2] = (Exercise){"mountain climbers",        29, LoadTexture("data/mountain_climbers.png")};
	exercises[ 3] = (Exercise){"spiderman plank",          29, LoadTexture("data/spiderman_planks.png")};

	exercises[ 4] = (Exercise){"side plank",               19, LoadTexture("data/side_plank.png")};
	exercises[ 5] = (Exercise){"side plank (dips)",        19, LoadTexture("data/side_plank_dip.png")};
	exercises[ 6] = (Exercise){"side plank (leg lifts)",    9, LoadTexture("data/side_plank_leg_raises.png")};
	exercises[ 7] = (Exercise){"side plank (reaches)",      9, LoadTexture("data/side_plank_reaches.png")};

	exercises[ 8] = (Exercise){"scissor_kicks",            19, LoadTexture("data/scissor_kicks.png")};
	exercises[ 9] = (Exercise){"butterfly kicks",          19, LoadTexture("data/butterfly_kicks.png")};
	exercises[10] = (Exercise){"mermaids",                 19, LoadTexture("data/mermaids.png")};

	exercises[11] = (Exercise){"toe touch (both hands)",   19, LoadTexture("data/toe_touch.png")};
	exercises[12] = (Exercise){"toe touch (alternating)",  19, exercises[11].image};
	exercises[13] = (Exercise){"toe touch (side by side)", 19, exercises[11].image};

	exercises[14] = (Exercise){"crunches (90 degree)",     29, LoadTexture("data/90_degree_crunches.png")};
	exercises[15] = (Exercise){"crunches (180 degree)",    29, LoadTexture("data/180_degree_crunches.png")};

	exercises[16] = (Exercise){"bicycle kicks",            29, LoadTexture("data/bicycle_kicks.png")};

	exercises[17] = (Exercise){"reverse crunches",         29, LoadTexture("data/reverse_crunches.png")};

	exercises[18] = (Exercise){"swaskickers (slow)",       29, LoadTexture("data/swaskickers.png")};
	exercises[19] = (Exercise){"swaskickers (fast)",       29, exercises[18].image};

	exercises[20] = (Exercise){"crunches",                 29, LoadTexture("data/crunches.png")};

	exercises[21] = (Exercise){"knee Reachers",            19, LoadTexture("data/knee_reaches.png")};

	exercises[22] = (Exercise){"ankle touches",            19, LoadTexture("data/ankle_touches.png")};
	
	exercises[23] = (Exercise){"in and outs",              29, LoadTexture("data/in_and_outs.png")};
	
	exercises[24] = (Exercise){"russian twists",           29, LoadTexture("data/russian_twists.png")};

	exercises[25] = (Exercise){"",                          0, LoadTexture("data/end_background.png")};
}

void reset_values(void)
{
	fade = 255;
	time_remaining = exercises[stage].interval + 3;
}

void process_exercises()
{

	DrawTexture(exercises[stage].image, 0, 0, (Color){255, 255, 255, fade});           // Draw exercise image
	if (stage == 25)
	{
		DrawText("you did it!", 500, 30, 150, COLOUR_TEXT);
		return;
	}


	if (time_remaining > exercises[stage].interval)
	{
		DrawText("Next exercise", 355, 5, 80, COLOUR_TEXT);
	}
	else
	{
		DrawText(TextFormat("%02.0f", time_remaining), 600, 5, 80, COLOUR_TEXT); // Draw time remaining
	}

	int spacing = (TextLength(exercises[stage].label) / 2) * 40;
	DrawText(exercises[stage].label, 640 - spacing, 630, 80, COLOUR_TEXT);                               // Draw Exercise label

	if (time_remaining > 0 && !paused)
	{
		time_remaining -= GetFrameTime();
	}
	
	if (time_remaining < 0)
	{
		time_remaining = 0;
		PlaySound(beep);
	}

	if (time_remaining == 0 && stage < STAGES - 1 && !paused)
	{
		fade -= 5;
	}

	if (fade < 5)
	{
		stage++;
		reset_values();
	}


}













