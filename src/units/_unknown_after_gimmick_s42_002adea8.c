#include "../common.h"
extern float D_004A0EC8;
typedef struct { char p[188]; short s188; short pad; unsigned u192; int pad2; float f200; char q[380 - 204]; float f380; } E;
typedef struct { E *e; char p[492]; unsigned fl; } B;
typedef struct { char p[8]; unsigned f; char q[20]; unsigned g; short h; short k; } A;
void func_002BEEA0(B *);
void func_002A0190(B *);
// MATCH func_002ADEA8
void FUN_002adea8(A *a, B *b) { b->fl |= 0x20000; func_002BEEA0(b); func_002A0190(b); if (a->k != -1 && !(a->f & 2)) { E *e = b->e; float x = e->f200 * D_004A0EC8; a->g = e->u192; a->h = e->s188; e->s188 = a->k; e->f380 = __builtin_fabsf(x); e->u192 &= ~0x800; } }
