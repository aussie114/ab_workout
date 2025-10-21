#ifndef EXERCISES_H
#define EXERCISES_H
#include "raylib.h"
#define STAGES 26
typedef struct Exercise
{
	char * label;
	float interval;
	Texture image;
} Exercise;
extern int paused;
extern int stage;
extern int fade;
extern float time_remaining;
extern Exercise exercises[STAGES];
void setup_exercises();
void process_exercises();
void reset_values(void);
#endif
