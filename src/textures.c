#include "textures.h"
Texture_variables textures;
void load_textures()
{
	textures.plank                 = LoadTexture("data/plank.png");
	textures.plank_twist           = LoadTexture("data/plank_twists.png");
	textures.mountain_climbers     = LoadTexture("data/mountain_climbers.png");
	textures.spider_man_planks     = LoadTexture("data/spiderman_planks.png"); 
	textures.sideplank             = LoadTexture("data/sideplank.png");
	textures.sideplank_dips        = LoadTexture("data/sideplank_dips.png");
	textures.sideplank_leg_raises  = LoadTexture("data/sideplank_leg_raises.png");
	textures.sideplank_reachers    = LoadTexture("data/sideplank_reachers.png");
	textures.scissor_kicks         = LoadTexture("data/scissor_kicks.png");
	textures.butterfly_kicks       = LoadTexture("data/butterfly_kicks.png");
	textures.mermaids              = LoadTexture("data/mermaids.png");
	textures.toe_touch             = LoadTexture("data/toe_touches.png");
	textures.crunches_90_degrees   = LoadTexture("data/crunches_90_degrees.png");
	textures.crunches_180_degrees  = LoadTexture("data/crunches_180_degrees.png");
	textures.bicycle_kicks         = LoadTexture("data/bicycle_kicks.png");
	textures.reverse_crunches      = LoadTexture("data/reverse_crunches.png");
	textures.swaskickers           = LoadTexture("data/swaskickers.png");
	textures.crunches              = LoadTexture("data/crunches.png");
	textures.knee_reaches          = LoadTexture("data/knee_reaches.png");
	textures.ankle_touches         = LoadTexture("data/ankle_touches.png");
	textures.in_and_outs           = LoadTexture("data/in_and_outs.png");
	textures.russian_twists        = LoadTexture("data/russian_twists.png");
	textures.end_screen            = LoadTexture("data/end_screen.png");
}
