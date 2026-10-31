/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

typedef struct { char p[20]; int w20; } P_00294598;
typedef union { int w; struct { unsigned short a; short b; } s; } U;
typedef struct { P_00294598 *p; int pad4; U u; int w12; char pad16[24]; short d40; short i42; short v44; short v46; } O_00294598;
extern long D_004A12C8; extern long D_004A12D8; extern long D_004A12E0; extern char D_00343028_00294598[] __asm__("D_00343028");
int func_001114B0(void); void func_00164C10(O_00294598 *); void func_0010C2B0(char *, int, int, int, int, int, int);
// MATCH func_00294598
void FUN_00294598(O_00294598 *o) { int idx; void (*fn)(void *); int d; int dl; long e; if (func_001114B0() != 0) { func_00164C10(o); } else if ((D_004A12C8 & 4) != 0) { o->u.s.a = 0xffff; o->w12 = o->u.s.b; if (((D_004A12D8 | D_004A12E0) & 0x1000) != 0) o->u.s.b = (unsigned short)o->u.s.b - 1; if (((D_004A12D8 | D_004A12E0) & 0x4000) != 0) o->u.s.b = (unsigned short)o->u.s.b + 1; if (o->u.s.b < 0) o->u.s.b = (unsigned short)o->u.s.b + *(unsigned short *)&o->p->w20; if (o->u.s.b >= o->p->w20) o->u.s.b = (unsigned short)o->u.s.b - *(unsigned short *)&o->p->w20; idx = o->i42; if (idx > 0) { long *vt = *(long **)((char *)o + o->v44); e = vt[idx - 1]; fn = (void (*)(void *))(e >> 32); } else fn = *(void (**)(void *))&o->v44; dl = o->d40; d = idx > 0 ? (short)e + dl : dl; fn((char *)o + d); } else { func_00164C10(o); } if (o->w12 != o->u.s.b) func_0010C2B0(D_00343028_00294598, 120, 13, 1, 0, 1, 0); }
