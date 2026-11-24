/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

typedef struct { char p[8]; int w8; char q[16]; int w28; } J_00206F38;
typedef struct { char p0[20]; void *w20; char p1[160]; int w184; char p2[28]; J_00206F38 *w216; char p3[176]; int w396; } O_00206F38;
extern int D_00425510_206F38[] __asm__("D_00425510"); extern int D_00425710_206F38[] __asm__("D_00425710");
int func_002143F0_206F38(J_00206F38 *) __asm__("func_002143F0"); void func_00207048_206F38(void) __asm__("func_00207048");
// MATCH func_00206F38
void pchjob0_00206f38(O_00206F38 *o) { J_00206F38 *j = o->w216; int r; int pad[4]; if (j == 0) return; if (((D_00425510_206F38[o->w184 / 32] >> o->w184) ^ 1) & 1) { if (D_00425710_206F38[o->w396] >= 100) { if (j->w8 > 0) j->w8 = 0; } { register int v __asm__("$2"); int *q = &D_00425510_206F38[o->w184 / 32]; v = *q | 1 << o->w184; *q = v; } } r = func_002143F0_206F38(o->w216); D_00425710_206F38[o->w396] = o->w216->w28; if (r == 0) o->w20 = func_00207048_206F38; }
