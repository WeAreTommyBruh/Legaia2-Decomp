#include "../src/common.h"
typedef struct { char pad[8]; short adj; short p2; void (*fn)(void *); } VT_2479f0;
typedef struct { char pad[8]; int a8; char pad2[12]; VT_2479f0 *vt; } O_2479f0;
extern O_2479f0 *D_004A1524; extern int D_004A1540, D_004A152C;
void func_00190420(void *);
// 5 words differ
// WIP func_002479F0
void FUN_002479f0(void) { func_00190420(D_004A1524); if (D_004A1540 == 0) { O_2479f0 *o = D_004A1524; o->a8 = D_004A152C; o->vt->fn((char *)o + o->vt->adj); } }
