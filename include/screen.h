#ifndef SCREEN_H
#define SCREEN_H
#define SCREEN_X 1280.0f
#define SCREEN_Y  720.0f
typedef struct
{
	float width;
	float height;
	Vector2 position;
	float scale;
	RenderTexture2D virtual_screen;  // Surface everything gets rendered to
	Rectangle virtual_area;          // Area of that surface
	Rectangle destination;           // Actual screen size with aspect ratio maintained
} Screen_variables;
extern Screen_variables screen;
#endif
