#include "raylib.h"
#include "setup.c"
#include "process.c"

int main(void)
{
	setup(false);
	while (!WindowShouldClose())
    {
        process();
    }
    CloseWindow();
    return 0;
}

