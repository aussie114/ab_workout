PROJECT = ab_workout
DESKTOP_OBJECTS = $(patsubst src/%.c, build/desktop/%.o, $(wildcard src/*.c))
WEB_OBJECTS =     $(patsubst src/%.c, build/web/%.o, $(wildcard src/*.c))

PLATFORM ?= DESKTOP

ifeq ($(PLATFORM), DESKTOP)

run: build
	./$(PROJECT)

build: $(DESKTOP_OBJECTS)
	gcc -o $(PROJECT)  main/desktop_main.c lib/libraylib.a     build/desktop/*.o -Iinclude -Wall -Wextra -lGL -lm -lpthread -ldl -lrt -lX11

build/desktop/%.o: src/%.c
	gcc  -Wall -Wextra -Iinclude -c $< -o $@

clean:
	rm -rf build/desktop/* $(PROJECT)

endif

ifeq ($(PLATFORM), WEB)

run: build
	emrun web_export/index.html

build:   $(WEB_OBJECTS)
	emcc -o web_export/index.html main/web_main.c      lib/libraylib.web.a build/web/*.o -Iinclude -Wall -Wextra -Os  --shell-file include/shell.html -s USE_GLFW=3 -s ASYNCIFY --preload-file data -s TOTAL_MEMORY=134217728
	zip web_export/$(PROJECT).zip web_export/index.*

build/web/%.o: src/%.c
	emcc -Wall -Wextra -Iinclude -c $< -o $@

clean:
	rm -rf build/web/* web_export/*

endif
