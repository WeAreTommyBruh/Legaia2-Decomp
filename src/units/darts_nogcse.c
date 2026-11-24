/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { char pad[16]; long long *p; } G_0016F628;
extern G_0016F628 D_00314C20_16F628 __asm__("D_00314C20");
extern char D_00334AF0_16F628[] __asm__("D_00334AF0");
void func_00163A38_16F628(int, int, int, int, void *) __asm__("func_00163A38");
// MATCH func_0016F628
void darts_0016f628(int *o) { long long *q; int v, k; if (o[21] == 0) return; v = o[27]; q = D_00314C20_16F628.p; q[0] = 342; q[2] = (unsigned)((o[13] << 24) | 0x808080) | 0x3f80000000000000LL; q[3] = 1; q[1] = 0; D_00314C20_16F628.p = q + 4; k = 1; while ((v = v / 10) != 0) k++; func_00163A38_16F628((o[1] >> 4) - ((((short *)o[0])[2] - ((short *)o[0])[0]) * k) / 2, o[2] >> 4, o[27], k, D_00334AF0_16F628); }
