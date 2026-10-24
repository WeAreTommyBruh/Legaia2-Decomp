/* Small functions matched by hand. */
// cflags: -fexceptions
#include "common.h"

void func_0015CD90(int);
// MATCH func_0015A9A8
void FUN_0015a9a8(int *p) { func_0015CD90(*p); }

void func_00184428(float);
// MATCH func_00184408
void FUN_00184408(void) { func_00184428(0.0f); }

void func_00113108(char *);
extern char D_00315D88[];
// MATCH func_00111968
void FUN_00111968(void) { func_00113108(D_00315D88); }

typedef struct { int n; } S_001809D0;
void func_001809F8(S_001809D0 *);
// MATCH func_001809D0
void FUN_001809d0(S_001809D0 *s) { s->n++; func_001809F8(s); }

void func_00155D40(float, float, float, float, float, float);
// MATCH func_00155D18
void sky_00155d18(float a, float b, float c, float d) { func_00155D40(a, b, c, d, 1.0f, 1.0f); }

void func_0015A730(int, int, int, int, int);
// MATCH func_0015A868
void FUN_0015a868(int a, int b, int c, int d) { func_0015A730(a, b, c, d, 1); }

void func_002380C0(int, int, int, int, int, int, int);
// MATCH func_00238070
void FUN_00238070(int a, int b, int c, int d, int e, int f) { func_002380C0(a, b, c, d, e, f, 1); }

void func_002207E8(float);
// MATCH func_002207C0
void FUN_002207c0(void) { func_002207E8(1.0f); }

extern int D_004A7240, D_004A7244; void func_0024BD78(int, int, int, int, int, int);
// MATCH func_0024BD50
void init_0024bd50(int a, int b, int c, int d, int e, int f, int g) { D_004A7240 = f; D_004A7244 = g; func_0024BD78(a, b, c, d, e, 0); }

void func_0022F5A0(float, float);
typedef struct { char p[128]; float x; char p2[4]; float y; } O_0024D490;
// MATCH func_0024D490
void FUN_0024d490(O_0024D490 *a, O_0024D490 *b) { func_0022F5A0(b->x - a->x, b->y - a->y); }

extern int D_004A12A4; void func_002562F8(void); void func_002594B0(void);
// MATCH func_00256260
void FUN_00256260(void) { if (D_004A12A4 == 11) func_002562F8(); else func_002594B0(); }

void func_00291DF0(int, int, int, int, int, int, int);
// MATCH func_00291DC0
void FUN_00291dc0(int a, int b, int c, signed char d, signed char e, int f) { func_00291DF0(a, b, c, d, e, f, 0); }

void func_002C1CF0(int, int, int, int, int);
// MATCH func_002C1FE8
void FUN_002c1fe8(int a, int b, int c) { func_002C1CF0(a, b, c, 0, -1); }

extern char D_0062B8D8[]; void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCC10
void FUN_002ccc10(int a) { func_002CCF20(a, 0, 0, 9, D_0062B8D8); }

extern char D_0062B8D8_002CCC40[] __asm__("D_0062B8D8"); void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCC40
void FUN_002ccc40(int a) { func_002CCF20(a, 0, 0, 4, D_0062B8D8_002CCC40); }

extern char D_0062B8D8_002CCBA8[] __asm__("D_0062B8D8"); extern int D_00427DB0[]; void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCBA8
void FUN_002ccba8(int a, int b, int c) { D_00427DB0[0] = 0; func_002CCF20(a, b, c, 5, D_0062B8D8_002CCBA8); }

void func_00220820(int, int, int, int, float);
// MATCH func_002207E8
void FUN_002207e8(int a, int b, int c) { func_00220820(0, a, b, c, 1.0f); }

extern char D_0049F708[];
void func_002ED680(int, void *, int, int);
// MATCH func_002ED7A8
void FUN_002ed7a8(int a, int b) { func_002ED680(a, D_0049F708, b, 1); }

void func_002ED680_002ED788(int, int, int, int) __asm__("func_002ED680");
// MATCH func_002ED788
void FUN_002ed788(int a, int b, int c) { func_002ED680_002ED788(a, b, c, 1); }

extern int D_00427DB0_002CCE30[] __asm__("D_00427DB0"); extern int D_00426350[]; extern char D_0049E238[], D_0049E250[], D_0049E268[]; extern char D_0062B8D8_002CCE30[] __asm__("D_0062B8D8");
void func_002E7940(void *); void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCE30
void sceCdStPause(void) { D_00427DB0_002CCE30[0] = 0; if (D_00426350[0] > 0) func_002E7940(D_0049E238); func_002CCF20(0, 0, 0, 7, D_0062B8D8_002CCE30); }

extern int D_00427DB0_002CCE80[] __asm__("D_00427DB0"); extern int D_00426350_002CCE80[] __asm__("D_00426350"); extern char D_0049E238_002CCE80[] __asm__("D_0049E238"), D_0049E250[], D_0049E268[]; extern char D_0062B8D8_002CCE80[] __asm__("D_0062B8D8");
void func_002E7940(void *); void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCE80
void sceCdStResume(void) { D_00427DB0_002CCE80[0] = 1; if (D_00426350_002CCE80[0] > 0) func_002E7940(D_0049E250); func_002CCF20(0, 0, 0, 8, D_0062B8D8_002CCE80); }

extern int D_00427DB0_002CCED8[] __asm__("D_00427DB0"); extern int D_00426350_002CCED8[] __asm__("D_00426350"); extern char D_0049E238_002CCED8[] __asm__("D_0049E238"), D_0049E250[], D_0049E268[]; extern char D_0062B8D8_002CCED8[] __asm__("D_0062B8D8");
void func_002E7940(void *); void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCED8
void sceCdStStat(void) { if (D_00426350_002CCED8[0] > 0) func_002E7940(D_0049E268); func_002CCF20(0, 0, 0, 6, D_0062B8D8_002CCED8); }

void func_002E7D58(int, int, int, int, int, int, int);
// MATCH func_002E7ED0
void FUN_002e7ed0(int a, int b, int c, int d, int e, int f) { func_002E7D58(a, 1, b, c, d, e, f); }

void func_002E7D58(int, int, int, int, int, int, int);
// MATCH func_002E7E90
void FUN_002e7e90(int a, int b, int c, int d, int e, int f) { func_002E7D58(a, 0, b, c, d, e, f); }

int func_002DBC48(void); void func_002D8148(void) __attribute__((noreturn));
// MATCH func_002D8228
void FUN_002d8228(void) { if (func_002DBC48() == 0) func_002D8148(); }

typedef struct { char p[4]; int w4; } Q_002BAF58;
typedef struct { char p[576]; Q_002BAF58 *w576; } R_002BAF58;
typedef struct { char p[216]; R_002BAF58 *w216; } O_002BAF58;
void func_002ADCC8(Q_002BAF58 *, O_002BAF58 *); void func_002AE0C8(Q_002BAF58 *, O_002BAF58 *);
// MATCH func_002BAF58
void FUN_002baf58(O_002BAF58 *o) { Q_002BAF58 *q = o->w216->w576; if (q != 0) { switch (q->w4) { case 0: func_002ADCC8(q, o); break; case 1: func_002AE0C8(q, o); break; } } }
