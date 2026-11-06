/* Functions of this report unit, matched by hand. */
// cflags: -fexceptions
#include "../common.h"

typedef struct { char c[16]; } B16_001891C0;
extern char *D_00341348_1891C0[] __asm__("D_00341348"); short func_002469A0_1891C0(char *, char *) __asm__("func_002469A0"); void func_00187068_1891C0(char *) __asm__("func_00187068");
// MATCH func_001891C0
void srivus_001891c0(char *o) { if (*(int *)(o + 1780) == 42) { unsigned n; *(B16_001891C0 *)(*(char **)(o + 1036) + 32) = *(B16_001891C0 *)(*(char **)(o + 1792) + 32); n = *(int *)(o + 2092) - 1; if (n < 5) { char *q2 = *(char **)(o + 1036); *(unsigned *)(q2 + 192) &= 0xfffffffd; *(short *)(*(char **)(o + 1036) + 188) = func_002469A0_1891C0(q2, D_00341348_1891C0[n]); } } func_00187068_1891C0(o); }

