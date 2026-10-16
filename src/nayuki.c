/*
 * nayuki.cpp: the particle emitter of the effect system (see tools/efp_tool.py).
 * Functions marked MATCH compile to the original bytes with ee-gcc
 * 2.9-ee-991111-01 -O2 -G8 (check with tools/match.py).
 */
#include "common.h"
#include "effect.h"

/*
 * A particle parameter that changes over time: three terms (0 value,
 * 1 speed, 2 acceleration), each with a start value, a random spread and a
 * mode. The effect commands pt_<x>, pt_<x>sp and pt_<x>ap set the terms.
 */
typedef struct {
    float start[3];     /* 0x00 */
    int mode[3];        /* 0x0c */
    float cur[3];       /* 0x18 */
    float spread[3][2]; /* 0x24 */
    int seed[3];        /* 0x3c */
    int pad[2];         /* 0x48 */
} Curve;                /* 0x50 */

#define CURVE(e, off) ((Curve *)((char *)(e) + (off)))

/* command 0x26 pt_posx */
// MATCH func_001D84A0
void Emitter_pt_posx(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x4e8);

    c->start[0] = v;
    c->cur[0] = v;
    c->spread[0][0] = a;
    c->spread[0][1] = b;
    c->seed[0] = seed;
    if (mode >= 0)
        c->mode[0] = mode;
}

/* command 0x27 pt_posy */
// MATCH func_001D84C8
void Emitter_pt_posy(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x538);

    c->start[0] = v;
    c->cur[0] = v;
    c->spread[0][0] = a;
    c->spread[0][1] = b;
    c->seed[0] = seed;
    if (mode >= 0)
        c->mode[0] = mode;
}

/* command 0x28 pt_posz */
// MATCH func_001D84F0
void Emitter_pt_posz(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x588);

    c->start[0] = v;
    c->cur[0] = v;
    c->spread[0][0] = a;
    c->spread[0][1] = b;
    c->seed[0] = seed;
    if (mode >= 0)
        c->mode[0] = mode;
}

/* command 0x29 pt_spx */
// MATCH func_001D8518
void Emitter_pt_spx(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x4e8);

    c->start[1] = v;
    c->cur[1] = v;
    c->spread[1][0] = a;
    c->spread[1][1] = b;
    c->seed[1] = seed;
    if (mode >= 0)
        c->mode[1] = mode;
}

/* command 0x2a pt_spy */
// MATCH func_001D8540
void Emitter_pt_spy(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x538);

    c->start[1] = v;
    c->cur[1] = v;
    c->spread[1][0] = a;
    c->spread[1][1] = b;
    c->seed[1] = seed;
    if (mode >= 0)
        c->mode[1] = mode;
}

/* command 0x2b pt_spz */
// MATCH func_001D8568
void Emitter_pt_spz(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x588);

    c->start[1] = v;
    c->cur[1] = v;
    c->spread[1][0] = a;
    c->spread[1][1] = b;
    c->seed[1] = seed;
    if (mode >= 0)
        c->mode[1] = mode;
}

/* command 0x2c pt_apx */
// MATCH func_001D8590
void Emitter_pt_apx(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x4e8);

    c->start[2] = v;
    c->cur[2] = v;
    c->spread[2][0] = a;
    c->spread[2][1] = b;
    c->seed[2] = seed;
    if (mode >= 0)
        c->mode[2] = mode;
}

/* command 0x2d pt_apy */
// MATCH func_001D85B8
void Emitter_pt_apy(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x538);

    c->start[2] = v;
    c->cur[2] = v;
    c->spread[2][0] = a;
    c->spread[2][1] = b;
    c->seed[2] = seed;
    if (mode >= 0)
        c->mode[2] = mode;
}

/* command 0x2e pt_apz */
// MATCH func_001D85E0
void Emitter_pt_apz(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x588);

    c->start[2] = v;
    c->cur[2] = v;
    c->spread[2][0] = a;
    c->spread[2][1] = b;
    c->seed[2] = seed;
    if (mode >= 0)
        c->mode[2] = mode;
}

/* command 0x2f pt_angx */
// MATCH func_001D8608
void Emitter_pt_angx(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x5d8);

    c->start[0] = v;
    c->cur[0] = v;
    c->spread[0][0] = a;
    c->spread[0][1] = b;
    c->seed[0] = seed;
    if (mode >= 0)
        c->mode[0] = mode;
}

/* command 0x30 pt_angy */
// MATCH func_001D8630
void Emitter_pt_angy(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x628);

    c->start[0] = v;
    c->cur[0] = v;
    c->spread[0][0] = a;
    c->spread[0][1] = b;
    c->seed[0] = seed;
    if (mode >= 0)
        c->mode[0] = mode;
}

/* command 0x31 pt_angz */
// MATCH func_001D8658
void Emitter_pt_angz(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x678);

    c->start[0] = v;
    c->cur[0] = v;
    c->spread[0][0] = a;
    c->spread[0][1] = b;
    c->seed[0] = seed;
    if (mode >= 0)
        c->mode[0] = mode;
}

/* command 0x32 pt_angspx */
// MATCH func_001D8680
void Emitter_pt_angspx(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x5d8);

    c->start[1] = v;
    c->cur[1] = v;
    c->spread[1][0] = a;
    c->spread[1][1] = b;
    c->seed[1] = seed;
    if (mode >= 0)
        c->mode[1] = mode;
}

/* command 0x33 pt_angspy */
// MATCH func_001D86A8
void Emitter_pt_angspy(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x628);

    c->start[1] = v;
    c->cur[1] = v;
    c->spread[1][0] = a;
    c->spread[1][1] = b;
    c->seed[1] = seed;
    if (mode >= 0)
        c->mode[1] = mode;
}

/* command 0x34 pt_angspz */
// MATCH func_001D86D0
void Emitter_pt_angspz(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x678);

    c->start[1] = v;
    c->cur[1] = v;
    c->spread[1][0] = a;
    c->spread[1][1] = b;
    c->seed[1] = seed;
    if (mode >= 0)
        c->mode[1] = mode;
}

/* command 0x35 pt_angapx */
// MATCH func_001D86F8
void Emitter_pt_angapx(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x5d8);

    c->start[2] = v;
    c->cur[2] = v;
    c->spread[2][0] = a;
    c->spread[2][1] = b;
    c->seed[2] = seed;
    if (mode >= 0)
        c->mode[2] = mode;
}

/* command 0x36 pt_angapy */
// MATCH func_001D8720
void Emitter_pt_angapy(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x628);

    c->start[2] = v;
    c->cur[2] = v;
    c->spread[2][0] = a;
    c->spread[2][1] = b;
    c->seed[2] = seed;
    if (mode >= 0)
        c->mode[2] = mode;
}

/* command 0x37 pt_angapz */
// MATCH func_001D8748
void Emitter_pt_angapz(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x678);

    c->start[2] = v;
    c->cur[2] = v;
    c->spread[2][0] = a;
    c->spread[2][1] = b;
    c->seed[2] = seed;
    if (mode >= 0)
        c->mode[2] = mode;
}

/* command 0x38 pt_rotx */
// MATCH func_001D8770
void Emitter_pt_rotx(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x6c8);

    c->start[0] = v;
    c->cur[0] = v;
    c->spread[0][0] = a;
    c->spread[0][1] = b;
    c->seed[0] = seed;
    if (mode >= 0)
        c->mode[0] = mode;
}

/* command 0x39 pt_roty */
// MATCH func_001D8798
void Emitter_pt_roty(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x718);

    c->start[0] = v;
    c->cur[0] = v;
    c->spread[0][0] = a;
    c->spread[0][1] = b;
    c->seed[0] = seed;
    if (mode >= 0)
        c->mode[0] = mode;
}

/* command 0x3a pt_rotz */
// MATCH func_001D87C0
void Emitter_pt_rotz(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x768);

    c->start[0] = v;
    c->cur[0] = v;
    c->spread[0][0] = a;
    c->spread[0][1] = b;
    c->seed[0] = seed;
    if (mode >= 0)
        c->mode[0] = mode;
}

/* command 0x3b pt_rotspx */
// MATCH func_001D87E8
void Emitter_pt_rotspx(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x6c8);

    c->start[1] = v;
    c->cur[1] = v;
    c->spread[1][0] = a;
    c->spread[1][1] = b;
    c->seed[1] = seed;
    if (mode >= 0)
        c->mode[1] = mode;
}

/* command 0x3c pt_rotspy */
// MATCH func_001D8810
void Emitter_pt_rotspy(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x718);

    c->start[1] = v;
    c->cur[1] = v;
    c->spread[1][0] = a;
    c->spread[1][1] = b;
    c->seed[1] = seed;
    if (mode >= 0)
        c->mode[1] = mode;
}

/* command 0x3d pt_rotspz */
// MATCH func_001D8838
void Emitter_pt_rotspz(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x768);

    c->start[1] = v;
    c->cur[1] = v;
    c->spread[1][0] = a;
    c->spread[1][1] = b;
    c->seed[1] = seed;
    if (mode >= 0)
        c->mode[1] = mode;
}

/* command 0x3e pt_rotapx */
// MATCH func_001D8860
void Emitter_pt_rotapx(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x6c8);

    c->start[2] = v;
    c->cur[2] = v;
    c->spread[2][0] = a;
    c->spread[2][1] = b;
    c->seed[2] = seed;
    if (mode >= 0)
        c->mode[2] = mode;
}

/* command 0x3f pt_rotapy */
// MATCH func_001D8888
void Emitter_pt_rotapy(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x718);

    c->start[2] = v;
    c->cur[2] = v;
    c->spread[2][0] = a;
    c->spread[2][1] = b;
    c->seed[2] = seed;
    if (mode >= 0)
        c->mode[2] = mode;
}

/* command 0x40 pt_rotapz */
// MATCH func_001D88B0
void Emitter_pt_rotapz(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x768);

    c->start[2] = v;
    c->cur[2] = v;
    c->spread[2][0] = a;
    c->spread[2][1] = b;
    c->seed[2] = seed;
    if (mode >= 0)
        c->mode[2] = mode;
}

/* command 0x41 pt_sizex */
// MATCH func_001D88D8
void Emitter_pt_sizex(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x118);

    c->start[0] = v;
    c->cur[0] = v;
    c->spread[0][0] = a;
    c->spread[0][1] = b;
    c->seed[0] = seed;
    if (mode >= 0)
        c->mode[0] = mode;
}

/* command 0x42 pt_sizey */
// MATCH func_001D8900
void Emitter_pt_sizey(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x168);

    c->start[0] = v;
    c->cur[0] = v;
    c->spread[0][0] = a;
    c->spread[0][1] = b;
    c->seed[0] = seed;
    if (mode >= 0)
        c->mode[0] = mode;
}

/* command 0x43 pt_sizespx */
// MATCH func_001D8928
void Emitter_pt_sizespx(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x118);

    c->start[1] = v;
    c->cur[1] = v;
    c->spread[1][0] = a;
    c->spread[1][1] = b;
    c->seed[1] = seed;
    if (mode >= 0)
        c->mode[1] = mode;
}

/* command 0x44 pt_sizespy */
// MATCH func_001D8950
void Emitter_pt_sizespy(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x168);

    c->start[1] = v;
    c->cur[1] = v;
    c->spread[1][0] = a;
    c->spread[1][1] = b;
    c->seed[1] = seed;
    if (mode >= 0)
        c->mode[1] = mode;
}

/* command 0x45 pt_sizeapx */
// MATCH func_001D8978
void Emitter_pt_sizeapx(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x118);

    c->start[2] = v;
    c->cur[2] = v;
    c->spread[2][0] = a;
    c->spread[2][1] = b;
    c->seed[2] = seed;
    if (mode >= 0)
        c->mode[2] = mode;
}

/* command 0x46 pt_sizeapy */
// MATCH func_001D89A0
void Emitter_pt_sizeapy(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x168);

    c->start[2] = v;
    c->cur[2] = v;
    c->spread[2][0] = a;
    c->spread[2][1] = b;
    c->seed[2] = seed;
    if (mode >= 0)
        c->mode[2] = mode;
}

/* command 0x47 pt_alpha */
// MATCH func_001D89C8
void Emitter_pt_alpha(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x1b8);

    c->start[0] = v;
    c->cur[0] = v;
    c->spread[0][0] = a;
    c->spread[0][1] = b;
    c->seed[0] = seed;
    if (mode >= 0)
        c->mode[0] = mode;
}

/* command 0x48 pt_alphasp */
// MATCH func_001D89F0
void Emitter_pt_alphasp(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x1b8);

    c->start[1] = v;
    c->cur[1] = v;
    c->spread[1][0] = a;
    c->spread[1][1] = b;
    c->seed[1] = seed;
    if (mode >= 0)
        c->mode[1] = mode;
}

/* command 0x49 pt_alphaap */
// MATCH func_001D8A18
void Emitter_pt_alphaap(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x1b8);

    c->start[2] = v;
    c->cur[2] = v;
    c->spread[2][0] = a;
    c->spread[2][1] = b;
    c->seed[2] = seed;
    if (mode >= 0)
        c->mode[2] = mode;
}

/* command 0x4a pt_cl_r */
// MATCH func_001D8A40
void Emitter_pt_cl_r(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x914);

    c->start[0] = v;
    c->cur[0] = v;
    c->spread[0][0] = a;
    c->spread[0][1] = b;
    c->seed[0] = seed;
    if (mode >= 0)
        c->mode[0] = mode;
}

/* command 0x4b pt_cl_g */
// MATCH func_001D8A68
void Emitter_pt_cl_g(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x964);

    c->start[0] = v;
    c->cur[0] = v;
    c->spread[0][0] = a;
    c->spread[0][1] = b;
    c->seed[0] = seed;
    if (mode >= 0)
        c->mode[0] = mode;
}

/* command 0x4c pt_cl_b */
// MATCH func_001D8A90
void Emitter_pt_cl_b(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x9b4);

    c->start[0] = v;
    c->cur[0] = v;
    c->spread[0][0] = a;
    c->spread[0][1] = b;
    c->seed[0] = seed;
    if (mode >= 0)
        c->mode[0] = mode;
}

/* command 0x4d pt_clsp_r */
// MATCH func_001D8AB8
void Emitter_pt_clsp_r(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x914);

    c->start[1] = v;
    c->cur[1] = v;
    c->spread[1][0] = a;
    c->spread[1][1] = b;
    c->seed[1] = seed;
    if (mode >= 0)
        c->mode[1] = mode;
}

/* command 0x4e pt_clsp_g */
// MATCH func_001D8AE0
void Emitter_pt_clsp_g(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x964);

    c->start[1] = v;
    c->cur[1] = v;
    c->spread[1][0] = a;
    c->spread[1][1] = b;
    c->seed[1] = seed;
    if (mode >= 0)
        c->mode[1] = mode;
}

/* command 0x4f pt_clsp_b */
// MATCH func_001D8B08
void Emitter_pt_clsp_b(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x9b4);

    c->start[1] = v;
    c->cur[1] = v;
    c->spread[1][0] = a;
    c->spread[1][1] = b;
    c->seed[1] = seed;
    if (mode >= 0)
        c->mode[1] = mode;
}

/* command 0x50 pt_clap_r */
// MATCH func_001D8B30
void Emitter_pt_clap_r(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x914);

    c->start[2] = v;
    c->cur[2] = v;
    c->spread[2][0] = a;
    c->spread[2][1] = b;
    c->seed[2] = seed;
    if (mode >= 0)
        c->mode[2] = mode;
}

/* command 0x51 pt_clap_g */
// MATCH func_001D8B58
void Emitter_pt_clap_g(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x964);

    c->start[2] = v;
    c->cur[2] = v;
    c->spread[2][0] = a;
    c->spread[2][1] = b;
    c->seed[2] = seed;
    if (mode >= 0)
        c->mode[2] = mode;
}

/* command 0x52 pt_clap_b */
// MATCH func_001D8B80
void Emitter_pt_clap_b(float v, float a, float b, void *e, int mode, int seed)
{
    Curve *c = CURVE(e, 0x9b4);

    c->start[2] = v;
    c->cur[2] = v;
    c->spread[2][0] = a;
    c->spread[2][1] = b;
    c->seed[2] = seed;
    if (mode >= 0)
        c->mode[2] = mode;
}

/* single-value commands */

/* command 0x0b apptime: frames the emitter keeps spawning (0 = forever) */
// MATCH func_001D8438
void Emitter_apptime(void *e, int v)
{
    if (v >= 0)
        FIELD(float, e, 0x108) = v;
}

/* command 0x0a drawtime: particle lifetime in frames */
// MATCH func_001D8458
void Emitter_drawtime(void *e, int v)
{
    if (v >= 0)
        FIELD(int, e, 0x104) = v;
}

/* command 0x25 texanipt: texture animation pattern count */
// MATCH func_001D8468
void Emitter_texanipt(void *e, int v)
{
    if (v > 0)
        FIELD(int, e, 0xd4) = v;
}

/* command 0x54 option: flags */
// MATCH func_001D8490
void Emitter_option(void *e, int v)
{
    if (v >= 0)
        FIELD(int, e, 0xa04) = v;
}

/* command 0x20 form: render form (0-8) */
// MATCH func_001D8F18
void Emitter_form(void *e, unsigned int v)
{
    if (v < 9)
        FIELD(int, e, 0x80) = v;
}

void FUN_001d7f00(int texture);

/* command 0x21 texdraw: 1 = textured; 0 releases the texture */
// MATCH func_001D8D08
void Emitter_texdraw(void *e, unsigned int v)
{
    if (v < 2)
        FIELD(int, e, 0x114) = v;
    if (FIELD(int, e, 0x114) == 0)
        FUN_001d7f00(FIELD(int, e, 0x84));
}

/* command 0x24 ptnum, third argument */
// MATCH func_001D8358
void Emitter_ptnum_c(void *e, int v)
{
    if (v > 0)
        FIELD(int, e, 0xdc) = v;
}

/* command 0x58 drper: spawn chance out of 1000 */
// MATCH func_001D83B0
void Emitter_drper(float start, float end, float dur, float delay, void *e)
{
    Tween *t = (Tween *)((char *)e + 0xe0);
    float len;

    t->end = end;
    t->start = start;
    if (delay < 0 || dur < 0)
        return;
    t->on = 1;
    t->delay = delay;
    t->stop = delay + dur;
    len = t->stop - delay;
    if (len != 0)
        t->rate = (end - start) / len;
    else
        t->rate = 0;
    t->on = 1;
    t->cur = t->start;
    t->time = 0;
}

/* commands 0x18 rolltx and 0x19 rollty: texture scroll (stored, never read) */
// MATCH func_001D8DC8
void Emitter_rolltx(float start, float end, float dur, float delay, void *e, int mode)
{
    ITween *t = (ITween *)((char *)e + 0x88);
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

// MATCH func_001D8E70
void Emitter_rollty(float start, float end, float dur, float delay, void *e, int mode)
{
    ITween *t = (ITween *)((char *)e + 0xac);
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
