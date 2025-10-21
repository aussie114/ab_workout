PROJECT = ab_workout
DESKTOP_OBJECTS = $(patsubst src/%.c, build/desktop/%.o, $(wildcard src/*.c))
WEB_OBJECTS =     $(patsubst src/%.c, build/web/%.o, $(wildcard src/*.c))

PLATFORM ?= DESKTOP

ifeq ($(PLATFORM), DESKTOP)

run: build
	bin/$(PROJECT)

build: $(DESKTOP_OBJECTS)
	gcc -o bin/$(PROJECT)  main/desktop_main.c lib/libraylib.a     build/desktop/*.o -Iinclude -Wall -Wextra -lGL -lm -lpthread -ldl -lrt -lX11

build/desktop/%.o: src/%.c
	gcc  -Wall -Wextra -Iinclude -c $< -o $@

clean:
	rm -rf build/desktop/* bin/$(PROJECT)

endif

ifeq ($(PLATFORM), WEB)

run: build
	emrun bin/index.html

build:   $(WEB_OBJECTS)
	emcc -o bin/index.html main/web_main.c      lib/libraylib.web.a build/web/*.o -Iinclude -Wall -Wextra -Os  --shell-file include/shell.html -s USE_GLFW=3 -s ASYNCIFY --preload-file data -s TOTAL_MEMORY=67108864 
	zip bin/game.zip bin/index.*

build/web/%.o: src/%.c
	emcc -Wall -Wextra -Iinclude -c $< -o $@

clean:
	rm -rf build/web/* bin/index.* bin/*.zip

endif
