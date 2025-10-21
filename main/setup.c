#include "raylib.h"
#include "buttons.h"
#include "sounds.h"
#include "exercises.h"

RenderTexture2D virtual_screen;

void setup(bool web)
{
    InitWindow(1280, 720, "game");
	virtual_screen = LoadRenderTexture(1280, 720);
	if (!web) {SetTargetFPS(60);}
	InitAudioDevice();
	load_sounds();
	setup_buttons();
	setup_exercises();
}
