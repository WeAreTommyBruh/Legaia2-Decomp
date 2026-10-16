/*
 * yue.cpp: "model" effects, shapes built from circles (rings, cylinders); see
 * tools/efp_tool.py. Functions marked MATCH compile to the original bytes with
 * ee-gcc 2.9-ee-991111-01 -O2 -G8 (check with tools/match.py).
 */
#include "common.h"
#include "effect.h"

/* the float tween behind a command: mode, then start/end over dur after delay */
#define FLOAT_TWEEN(t, start, end, dur, delay, mode)            \
    float len;                                                  \
                                                                \
    if (mode < 3)                                               \
        t->mode = mode;                                         \
    t->start = start;                                           \
    t->end = end;                                               \
    if (delay < 0 || dur < 0)                                   \
        return;                                                 \
    t->on = 1;                                                  \
    t->delay = delay;                                           \
    t->stop = delay + dur;                                      \
    len = t->stop - delay;                                      \
    if (len != 0)                                               \
        t->rate = (end - start) / len;                          \
    else                                                        \
        t->rate = 0;                                            \
    t->on = 1;                                                  \
    t->cur = t->start;                                          \
    t->time = 0;

/* command scale */
// MATCH func_001E93D0
void Model_scale(float start, float end, float dur, float delay, void *m, int mode)
{
    Tween *t = (Tween *)((char *)m + 0xbc);

    FLOAT_TWEEN(t, start, end, dur, delay, mode)
}

/* command pos_x */
// MATCH func_001E95D0
void Model_pos_x(float start, float end, float dur, float delay, void *m, int mode)
{
    Tween *t = (Tween *)((char *)m + 0x128);

    FLOAT_TWEEN(t, start, end, dur, delay, mode)
}

/* command pos_y */
// MATCH func_001E9668
void Model_pos_y(float start, float end, float dur, float delay, void *m, int mode)
{
    Tween *t = (Tween *)((char *)m + 0x14c);

    FLOAT_TWEEN(t, start, end, dur, delay, mode)
}

/* command pos_z */
// MATCH func_001E9700
void Model_pos_z(float start, float end, float dur, float delay, void *m, int mode)
{
    Tween *t = (Tween *)((char *)m + 0x170);

    FLOAT_TWEEN(t, start, end, dur, delay, mode)
}

/* command angle_x */
// MATCH func_001E9810
void Model_angle_x(float start, float end, float dur, float delay, void *m, int mode)
{
    Tween *t = (Tween *)((char *)m + 0x26c);

    FLOAT_TWEEN(t, start, end, dur, delay, mode)
}

/* command angle_y */
// MATCH func_001E98A8
void Model_angle_y(float start, float end, float dur, float delay, void *m, int mode)
{
    Tween *t = (Tween *)((char *)m + 0x290);

    FLOAT_TWEEN(t, start, end, dur, delay, mode)
}

/* command angle_z */
// MATCH func_001E9940
void Model_angle_z(float start, float end, float dur, float delay, void *m, int mode)
{
    Tween *t = (Tween *)((char *)m + 0x2b4);

    FLOAT_TWEEN(t, start, end, dur, delay, mode)
}

/* command rot_x */
// MATCH func_001E9A50
void Model_rot_x(float start, float end, float dur, float delay, void *m, int mode)
{
    Tween *t = (Tween *)((char *)m + 0x2d8);

    FLOAT_TWEEN(t, start, end, dur, delay, mode)
}

/* command rot_y */
// MATCH func_001E9AE8
void Model_rot_y(float start, float end, float dur, float delay, void *m, int mode)
{
    Tween *t = (Tween *)((char *)m + 0x2fc);

    FLOAT_TWEEN(t, start, end, dur, delay, mode)
}

/* command rot_z */
// MATCH func_001E9B80
void Model_rot_z(float start, float end, float dur, float delay, void *m, int mode)
{
    Tween *t = (Tween *)((char *)m + 0x320);

    FLOAT_TWEEN(t, start, end, dur, delay, mode)
}

/* command rolltx (stored, never read) */
// MATCH func_001EA120
void Model_rolltx(float start, float end, float dur, float delay, void *m, int mode)
{
    ITween *t = (ITween *)((char *)m + 0xe0);
    int d, n;

    if (mode < 3)
        t->mode = mode;
    d = delay;
    n = dur;
    t->start = start;
    t->end = end;
    if (d < 0 || n < 0)
        return;
    t->on = 1;
    t->delay = d;
    t->stop = d + n;
    if (t->stop != d)
        t->rate = (float)(t->end - t->start) / (float)(t->stop - d);
    else
        t->rate = 0;
    t->on = 1;
    t->cur = t->start;
    t->time = 0;
}

/* command rollty (stored, never read) */
// MATCH func_001EA1C8
void Model_rollty(float start, float end, float dur, float delay, void *m, int mode)
{
    ITween *t = (ITween *)((char *)m + 0x104);
    int d, n;

    if (mode < 3)
        t->mode = mode;
    d = delay;
    n = dur;
    t->start = start;
    t->end = end;
    if (d < 0 || n < 0)
        return;
    t->on = 1;
    t->delay = d;
    t->stop = d + n;
    if (t->stop != d)
        t->rate = (float)(t->end - t->start) / (float)(t->stop - d);
    else
        t->rate = 0;
    t->on = 1;
    t->cur = t->start;
    t->time = 0;
}

/* command wa_height: per-circle tween (the circle count is at +0x7c)
   NONMATCHING: the original copies the record address into another register */
#ifdef NONMATCHING
void Model_wa_height(float start, float end, float dur, float delay, void *m, int circle, int mode)
{
    Tween *t;

    if (circle > FIELD(int, m, 0x7c) || circle < 0)
        return;
    t = (Tween *)(circle * 0x24 + FIELD(int, m, 0x358));
    {
        FLOAT_TWEEN(t, start, end, dur, delay, mode)
    }
}
#endif

/* command wa_radiusx: per-circle tween (the circle count is at +0x7c)
   NONMATCHING: the original copies the record address into another register */
#ifdef NONMATCHING
void Model_wa_radiusx(float start, float end, float dur, float delay, void *m, int circle, int mode)
{
    Tween *t;

    if (circle > FIELD(int, m, 0x7c) || circle < 0)
        return;
    t = (Tween *)(circle * 0x24 + FIELD(int, m, 0x350));
    {
        FLOAT_TWEEN(t, start, end, dur, delay, mode)
    }
}
#endif

/* command wa_radiusy: per-circle tween (the circle count is at +0x7c)
   NONMATCHING: the original copies the record address into another register */
#ifdef NONMATCHING
void Model_wa_radiusy(float start, float end, float dur, float delay, void *m, int circle, int mode)
{
    Tween *t;

    if (circle > FIELD(int, m, 0x7c) || circle < 0)
        return;
    t = (Tween *)(circle * 0x24 + FIELD(int, m, 0x354));
    {
        FLOAT_TWEEN(t, start, end, dur, delay, mode)
    }
}
#endif

/* command wa_see: per-circle tween (the circle count is at +0x7c)
   NONMATCHING: the original copies the record address into another register */
#ifdef NONMATCHING
void Model_wa_see(float start, float end, float dur, float delay, void *m, int circle, int mode)
{
    Tween *t;

    if (circle > FIELD(int, m, 0x7c) || circle < 0)
        return;
    t = (Tween *)(circle * 0x24 + FIELD(int, m, 0x368));
    {
        FLOAT_TWEEN(t, start, end, dur, delay, mode)
    }
}
#endif

/* command wa_colorr: per-circle tween (the circle count is at +0x7c)
   NONMATCHING: the original copies the record address into another register */
#ifdef NONMATCHING
void Model_wa_colorr(float start, float end, float dur, float delay, void *m, int circle, int mode)
{
    Tween *t;

    if (circle > FIELD(int, m, 0x7c) || circle < 0)
        return;
    t = (Tween *)(circle * 0x24 + FIELD(int, m, 0x35c));
    {
        FLOAT_TWEEN(t, start, end, dur, delay, mode)
    }
}
#endif

/* command wa_colorg: per-circle tween (the circle count is at +0x7c)
   NONMATCHING: the original copies the record address into another register */
#ifdef NONMATCHING
void Model_wa_colorg(float start, float end, float dur, float delay, void *m, int circle, int mode)
{
    Tween *t;

    if (circle > FIELD(int, m, 0x7c) || circle < 0)
        return;
    t = (Tween *)(circle * 0x24 + FIELD(int, m, 0x360));
    {
        FLOAT_TWEEN(t, start, end, dur, delay, mode)
    }
}
#endif

/* command wa_colorb: per-circle tween (the circle count is at +0x7c)
   NONMATCHING: the original copies the record address into another register */
#ifdef NONMATCHING
void Model_wa_colorb(float start, float end, float dur, float delay, void *m, int circle, int mode)
{
    Tween *t;

    if (circle > FIELD(int, m, 0x7c) || circle < 0)
        return;
    t = (Tween *)(circle * 0x24 + FIELD(int, m, 0x364));
    {
        FLOAT_TWEEN(t, start, end, dur, delay, mode)
    }
}
#endif
