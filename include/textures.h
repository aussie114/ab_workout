#ifndef TEXTURES_H
#define TEXTURES_H
#include "raylib.h"
typedef struct
{
	Texture plank;
	Texture plank_twist;
	Texture mountain_climbers;
	Texture spider_man_planks;
	Texture sideplank;
	Texture sideplank_dips;
	Texture sideplank_leg_raises;
	Texture sideplank_reachers;
	Texture scissor_kicks;
	Texture butterfly_kicks;
	Texture mermaids;
	Texture toe_touch;
	Texture crunches_90_degrees;
	Texture crunches_180_degrees;
	Texture bicycle_kicks;
	Texture reverse_crunches;
	Texture swaskickers;
	Texture crunches;
	Texture knee_reaches;
	Texture ankle_touches;
	Texture in_and_outs;
	Texture russian_twists;
	Texture end_screen;
} Texture_variables;
extern Texture_variables textures;
void load_textures();
#endif
