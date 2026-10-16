/* Shared records of the effect system (nayuki.cpp particles, mizuki.cpp
   water, yue.cpp models); see tools/efp_tool.py for the effect commands. */
#ifndef EFFECT_H
#define EFFECT_H

/* a value tweened from start to end over `dur` frames after `delay` frames */
typedef struct {
    float cur;      /* 0x00 */
    float start;    /* 0x04 */
    float end;      /* 0x08 */
    float time;     /* 0x0c */
    float stop;     /* 0x10 delay + dur */
    float delay;    /* 0x14 */
    float rate;     /* 0x18 */
    int mode;       /* 0x1c */
    int on;         /* 0x20 */
} Tween;

/* an integer value tweened like Tween */
typedef struct {
    int cur;        /* 0x00 */
    int start;      /* 0x04 */
    int end;        /* 0x08 */
    int time;       /* 0x0c */
    int stop;       /* 0x10 */
    int delay;      /* 0x14 */
    float rate;     /* 0x18 */
    int mode;       /* 0x1c */
    int on;         /* 0x20 */
} ITween;

#endif
