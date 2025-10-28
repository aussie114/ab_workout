#include "button.h"
#include "mouse.h"

Color button_border_colour = { 43,  46,  57, 255};
Color button_normal_colour = { 68,  74,  88, 255};
Color button_hover_colour  = { 80,  86, 102, 255};

bool Button(int x, int y, int w, int h)
{
	Rectangle border = (Rectangle){x, y, w, h};
	DrawRectangleRounded( border, 0.1, 5, button_border_colour);

	if (CheckCollisionPointRec(mouse.position, border))
	{
		DrawRectangleRounded((Rectangle){x+2, y+2, w-4, h-4}, 0.1, 5, button_hover_colour);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			return true;
		}
	}
	else
	{
		DrawRectangleRounded((Rectangle){x+2, y+2, w-4, h-4}, 0.1, 5, button_normal_colour);
	}
	return false;
}
