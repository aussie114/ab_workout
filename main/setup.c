#include "raylib.h"
#include "mouse.h"
#include "screen.h"
#include "sounds.h"
#include "fonts.h"
#include "exercises.h"
#include "process.h"
#include "textures.h"

Mouse_variables mouse;
Screen_variables screen;
Sounds_variables sounds;
Font_variables fonts;
//Texture_variables textures;

void setup(int web)
{
	InitWindow(SCREEN_X, SCREEN_Y, "Ab Workout");
	if (!web) {SetTargetFPS(60);}

	// Load mouse
	mouse.position = GetMousePosition();

	// Load screen
	screen.width  = 1280;
	screen.height =  720;
	screen.position = (Vector2){0,0};
	screen.scale  = 1;
	screen.virtual_screen = LoadRenderTexture(screen.width, screen.height);
	screen.virtual_area   = (Rectangle){0,0,1280,-720};
	screen.destination    = (Rectangle){0,0,1280,720};

	// Load sounds
	InitAudioDevice();
	sounds.beep = LoadSound("data/beep.wav");

	// Load fonts
	fonts.ubuntu_mono_80  = LoadFontEx("data/UbuntuMono-Regular.ttf",  80, 0, 0);
	fonts.ubuntu_mono_130 = LoadFontEx("data/UbuntuMono-Regular.ttf", 130, 0, 0);
	fonts.colour = (Color){51, 51, 51, 255};

	// Load textures
	load_textures();
}
