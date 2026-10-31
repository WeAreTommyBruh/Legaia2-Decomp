/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

typedef struct { char pad[20]; char sub[20]; int a40; int a44; } S_2a6498_002A6498;
void func_0029CFB8(void *);
// MATCH func_002A6498
void FUN_002a6498(S_2a6498_002A6498 *s) { func_0029CFB8(s); func_0029CFB8(s->sub); s->a40 = 0; s->a44 = 0; }

typedef struct { int w0, w4, w8, w12, w16; } S_002A6430;
typedef struct { int w0, w4, w8, w12, w16, w20, w24, w28, w32, w36, w40, w44, w48, w52, w56, w60, w64, w68, w72, w76, w80, w84; } O_002A6430;
// MATCH func_002A6430
void FUN_002a6430(O_002A6430 *o) { S_002A6430 *s = (S_002A6430 *)&o->w20; o->w76 = 20; o->w80 = 0; o->w40 = 0; o->w44 = 0; o->w56 = 0; o->w64 = 0; o->w48 = 0; o->w60 = 0; o->w68 = 0; o->w52 = 0; o->w72 = 0; o->w12 = 0; o->w8 = 0; o->w4 = 0; o->w16 = 0; s->w4 = 0; o->w20 = 0; o->w84 = 0; o->w0 = 0; s->w16 = 0; s->w12 = 0; s->w8 = 0; }
