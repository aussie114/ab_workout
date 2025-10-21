#include "raylib.h"
#include "buttons.h"
#include "sounds.h"
#include "exercises.h"

void setup(bool web)
{
    InitWindow(1280, 720, "game");
	if (!web) {SetTargetFPS(60);}
	InitAudioDevice();
	load_sounds();
	setup_buttons();
	setup_exercises();
}
