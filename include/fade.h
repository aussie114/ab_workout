#ifndef FADE_H
#define FADE_H
typedef struct {
    float alpha;
} Fade_variables;
extern Fade_variables fade;
void process_fade();
#endif
