#ifndef EXERCISES_H
#define EXERCISES_H
#include "raylib.h"
#define STAGES 25
typedef struct Exercise
{
	char * label;
	Vector2 text_offset;
	float interval;
	Texture * image;
} Exercise;

typedef struct
{
	int paused;
	int stage;
	float delay;
	float  time_remaining;
	Exercise exercises[STAGES];
	Texture exercise_sprites;
} Exercise_variables;
extern Exercise_variables exercise;
void setup_exercises();
void process_exercises();
void reset_values(void);
#endif
