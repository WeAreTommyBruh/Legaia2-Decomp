#include "../common.h"
typedef struct { int p0, p4; unsigned f; char q[28]; float g; int h; } A;
typedef struct { char *e; char p[492]; unsigned fl; } B;
void func_002B9CE0(B *, int, int, int);
// MATCH func_002ADFD8
void FUN_002adfd8(A *a, B *b, int c) { unsigned v; b->fl |= 0x20000; v = a->f; if (v & 8) { if (!(v & 0x20)) goto L; } if (v & 4) return; if (a->h == 0) return; L: a->g = *(float *)(b->e + 68); func_002B9CE0(b, c, 0, a->h); }
