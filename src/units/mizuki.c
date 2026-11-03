/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[144]; void *w144; } O_001E0218;
extern char D_0044B4A0[]; void *func_001334D0(int, char *, int); void func_00133528_001E0218(void *, char *, int) __asm__("func_00133528");
// MATCH func_001E0218
int mizuki_001e0218(O_001E0218 *o, int n) { void *p; if (n <= 0) return 0; p = func_001334D0(n, D_0044B4A0, 320); if (p == 0) return -1; if (o->w144 != 0) func_00133528_001E0218(o->w144, D_0044B4A0, 322); o->w144 = p; return 1; }

typedef struct { char p[152]; float f98, f9c; char q[8]; int ia8, iac; } M__001E00C0;
int func_001DFDB0_1E00C0(M__001E00C0 *) __asm__("func_001DFDB0"); void func_001E25A8_1E00C0(M__001E00C0 *, int) __asm__("func_001E25A8"); void func_001E0218_1E00C0(M__001E00C0 *, int) __asm__("func_001E0218"); void func_001E02A8_1E00C0(M__001E00C0 *) __asm__("func_001E02A8");
// MATCH func_001E00C0
void mizuki_001e00c0(M__001E00C0 *o, float a, float b, int n, int v) { if (a < 1.0f) return; if (b < 1.0f) return; if (n <= 0) return; o->f98 = a; o->f9c = b; o->ia8 = n; o->iac = v; func_001E25A8_1E00C0(o, func_001DFDB0_1E00C0(o)); func_001E0218_1E00C0(o, func_001DFDB0_1E00C0(o)); func_001E02A8_1E00C0(o); }
