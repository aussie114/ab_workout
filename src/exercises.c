#include "raylib.h"
#include "exercises.h"
#include "sounds.h"
#include "fade.h"
#include "fonts.h"
#include "textures.h"

Exercise_variables exercise = 
{
	0,
	0,
	5,
	34,
	{
		{"plank",                     (Vector2){0, 630},  29, &textures.plank                }, // 0 
		{"plank twists",              (Vector2){0, 630},  29, &textures.plank_twist          }, // 1 
		{"mountain climbers",         (Vector2){0, 630},  29, &textures.mountain_climbers    }, // 2 
		{"spiderman planks",          (Vector2){0, 630},  29, &textures.spider_man_planks    }, // 3 
		{"side plank",                (Vector2){0, 630},  19, &textures.sideplank            }, // 4 
		{"side planks (dips)",        (Vector2){0, 630},  19, &textures.sideplank_dips       }, // 5 
		{"side planks (leg raises)",   (Vector2){0, 630},  9, &textures.sideplank_leg_raises }, // 6 
		{"side planks (reaches)",     (Vector2){0, 630},   9, &textures.sideplank_reachers   }, // 7 

		{"scissor kicks",             (Vector2){0, 630},  19, &textures.scissor_kicks        }, // 8
		{"butterfly kicks",           (Vector2){0, 630},  19, &textures.butterfly_kicks      }, // 9 
		{"mermaids",                  (Vector2){0, 630},  19, &textures.mermaids             }, //10
		{"toe touches (both hands)",  (Vector2){0, 630},  19, &textures.toe_touch            }, //11 
		{"toe touches (alternating)", (Vector2){0, 630},  19, &textures.toe_touch            }, //12 
		{"toe touches (side by side)",(Vector2){0, 630},  19, &textures.toe_touch            }, //13 

		{"crunches (90 degrees)",     (Vector2){0, 630},  29, &textures.crunches_90_degrees  }, //14 
		{"crunches (180 degrees)",    (Vector2){0, 630},  29, &textures.crunches_180_degrees }, //15
		{"bicycle kicks",             (Vector2){0, 630},  29, &textures.bicycle_kicks        }, //16 
		{"reverse crunches",          (Vector2){0, 630},  29, &textures.reverse_crunches     }, //17 

		{"swaskickers (slow)",        (Vector2){0, 630},  29, &textures.swaskickers          }, //18
		{"swaskickers (fast)",        (Vector2){0, 630},  29, &textures.swaskickers          }, //19 
		{"crunches",                  (Vector2){0, 630},  29, &textures.crunches             }, //20 
		{"knee reachers",             (Vector2){0, 630},  19, &textures.knee_reaches         }, //21 
		{"ankle touches",             (Vector2){0, 630},  19, &textures.ankle_touches        }, //22 
		{"in and outs",               (Vector2){0, 630},  29, &textures.in_and_outs          }, //23 
		{"russian twists",            (Vector2){0, 630},  29, &textures.russian_twists       }, //24
	},
	{0,0,0,0,0},
};

Rectangle draw_destination = {0, 0, 1280, 480};
Vector2 draw_position = {0, -120};

void process_exercises()
{
	if (exercise.stage == 25)
	{
		DrawTexture(textures.end_screen, 0, 0, WHITE);
		return;
	}
	DrawTexture(*exercise.exercises[exercise.stage].image, 0, 120, WHITE);

	if      (IsKeyPressed(KEY_RIGHT) && exercise.stage < STAGES - 1) 
	{
		exercise.stage++;
		fade.alpha = 0;
		exercise.time_remaining = exercise.exercises[exercise.stage].interval + exercise.delay;
	}
	else if (IsKeyPressed(KEY_LEFT) && exercise.stage > 0) 
	{
		exercise.stage--;
		fade.alpha = 0;
		exercise.time_remaining = exercise.exercises[exercise.stage].interval + exercise.delay;
	}

	if (exercise.time_remaining > 0 && !exercise.paused)
	{
		exercise.time_remaining -= GetFrameTime();
	}
	
	if (exercise.time_remaining < 0)
	{
		exercise.time_remaining = 0;
		PlaySound(sounds.beep);
	}

	if (exercise.time_remaining == 0 && fade.alpha == 1)
	{
		exercise.stage++;
		exercise.time_remaining = exercise.exercises[exercise.stage].interval + exercise.delay;
	}
}
