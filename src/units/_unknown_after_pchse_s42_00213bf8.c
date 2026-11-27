#include "../common.h"
typedef struct { char c[16]; } B16;
typedef struct { char pad0[4]; signed char sh; char pad5[47]; int off52; } Clip;
typedef struct { char pad0[12]; unsigned short k12, k14, k16; } Ch;
void *func_00212F00(void *, int);
int func_00213150(void *, int);
void func_00213480(void *, void *, void *, void *, void *, int, int);
void func_00213AE8(void *, int, int, int, float *);
void func_0018EED8(float *, float);
// MATCH func_00213BF8
int FUN_00213bf8(void *m, int c1, int c2, int ch, int f1, int f2, float *o1, float *o2) { Clip *clip; Ch *p; short v[6]; B16 t; int swap; float a, b; if (c1 != c2 || (f1 + 1 != f2 && f1 - 1 != f2)) { func_00213AE8(m, c1, ch, f1, o1); func_00213AE8(m, c2, ch, f2, o2); return 1; } swap = 0; if (f1 - 1 == f2) { f1 = f2; swap = 1; } clip = func_00212F00(m, c1); p = (Ch *)((char *)clip + clip->off52 + ch * 24); a = func_00213150(m, c1) != 0 ? 0.000383495120331645f : 0.00153398048132658f; b = func_00213150(m, c2) != 0 ? 0.000383495120331645f : 0.00153398048132658f; func_00213480(m, &v[0], &v[1], clip, p, p->k12, f1); func_00213480(m, &v[2], &v[3], clip, p, p->k14, f1); func_00213480(m, &v[4], &v[5], clip, p, p->k16, f1); o1[0] = v[0]; o1[1] = v[2]; o1[2] = v[4]; o2[0] = v[1]; o2[1] = v[3]; o2[2] = v[5]; func_0018EED8(o1, a); func_0018EED8(o2, b); if (swap) { t = *(B16 *)o1; *(B16 *)o1 = *(B16 *)o2; *(B16 *)o2 = t; } return 1; }
