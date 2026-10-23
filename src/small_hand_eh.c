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

void func_0010B1A8(int, int, int, int, int, int);
// OFF func_0010B188
void rsound_0010b188(int a, int b, int c, int d, int e) { func_0010B1A8(a, b, c, d, e, -1); }

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
