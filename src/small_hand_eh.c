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
