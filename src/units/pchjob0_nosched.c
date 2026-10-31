/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

typedef struct { char p[24]; int w24; char q[156]; int w184; int pad; int w192; } O_00207728;
extern int D_00425510[]; extern int D_00425710[]; extern int D_004A4550;
int func_0016EEF8(int);
// MATCH func_00207728
void pchjob0_00207728(O_00207728 *o) { int i = o->w184; if (((D_00425510[i / 32] >> i) ^ 1) & 1) o->w24 |= 8; else *(int *)((char *)D_00425710 + (o->w192 << 2)) = func_0016EEF8(D_004A4550); }

typedef struct { char p[24]; int w24; char q[156]; int w184; int pad; int w192; } O_002077B8;
extern int D_00425510_002077B8[] __asm__("D_00425510"); extern int D_00425710_002077B8[] __asm__("D_00425710"); extern int D_004A4550_002077B8 __asm__("D_004A4550");
int func_00171AE8(int);
// MATCH func_002077B8
void pchjob0_002077b8(O_002077B8 *o) { int i = o->w184; if (((D_00425510_002077B8[i / 32] >> i) ^ 1) & 1) o->w24 |= 8; else *(int *)((char *)D_00425710_002077B8 + (o->w192 << 2)) = func_00171AE8(D_004A4550_002077B8); }

typedef struct { char p[16]; short adj; short pad; int (*fn)(void *); } VT_00207848;
typedef struct { char p[896]; VT_00207848 *vt; } G_00207848;
typedef struct { char p[24]; int w24; char q[156]; int w184; int pad; int w192; } O_00207848;
extern int D_00425510_00207848[] __asm__("D_00425510"); extern int D_00425710_00207848[] __asm__("D_00425710"); extern G_00207848 *D_004A4550_00207848 __asm__("D_004A4550");
// MATCH func_00207848
void pchjob0_00207848(O_00207848 *o) { int i = o->w184; if (((D_00425510_00207848[i / 32] >> i) ^ 1) & 1) o->w24 |= 8; else { G_00207848 *g = D_004A4550_00207848; int r = g->vt->fn((char *)g + g->vt->adj); { int *d = D_00425710_00207848 + o->w192; *d = r; } } }
