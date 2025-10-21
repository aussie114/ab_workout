#include "raylib.h"
#include "setup.c"
#include "process.c"
#include <emscripten/emscripten.h>

int main(void)
{
	setup(true);
	emscripten_set_main_loop(process, 0, 1);
	CloseWindow();
    return 0;
}


