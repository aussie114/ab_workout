#include "raylib.h"
#include "buttons.h"
#include "sounds.h"
#include "exercises.h"

float screen_width = 1280;
float screen_height = 720;
float aspect_ration = 0;
RenderTexture2D virtual_screen;

void setup(bool web)
{
	aspect_ration = screen_width / screen_height;
//	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screen_width, screen_height, "game");
	virtual_screen = LoadRenderTexture(screen_width, screen_height);
	if (!web) {SetTargetFPS(60);}
	InitAudioDevice();
	load_sounds();
	setup_buttons();
	setup_exercises();
}
