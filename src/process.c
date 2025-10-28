#include "raylib.h"
#include "screen.h"
#include "sounds.h"
#include "exercises.h"
#include "mouse.h"
#include "fade.h"
#include "header.h"
#include "footer.h"

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

void process(void)
{
	if (IsWindowResized())
	{
		screen.width = GetScreenWidth();
		screen.height = GetScreenHeight();
	}

	screen.scale = MIN(screen.width / SCREEN_X, screen.height / SCREEN_Y);
	mouse.position.x = MIN(SCREEN_X, MAX(0.0f, (GetMouseX() - ( screen.width  - (SCREEN_X * screen.scale) ) * 0.5f) / screen.scale ));
	mouse.position.y = MIN(SCREEN_Y, MAX(0.0f, (GetMouseY() - ( screen.height - (SCREEN_Y * screen.scale) ) * 0.5f) / screen.scale ));

	// Render to virtual screen
	BeginTextureMode(screen.virtual_screen);
		ClearBackground(WHITE);
		process_exercises();
		process_fade();
		process_header();
		process_footer();
	EndTextureMode();

	screen.destination.x = (screen.width  - (SCREEN_X * screen.scale)) * 0.5f;
	screen.destination.y = (screen.height - ( SCREEN_Y * screen.scale)) * 0.5f;
	screen.destination.width  = SCREEN_X * screen.scale;
	screen.destination.height =  SCREEN_Y * screen.scale;

	// Render to actual screen
	BeginDrawing();
		ClearBackground(BLANK);
		DrawRectangleRec(screen.destination, WHITE);
		DrawTexturePro(screen.virtual_screen.texture, screen.virtual_area, screen.destination, screen.position, 0.0f, WHITE);
	EndDrawing();
}

