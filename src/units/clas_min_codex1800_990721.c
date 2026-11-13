/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

extern int D_004A69A8_002A3DD8 __asm__("D_004A69A8"); extern char D_00343010_002A3DD8[] __asm__("D_00343010"), D_0049A700_002A3DD8[] __asm__("D_0049A700"), D_005F9640_002A3DD8[] __asm__("D_005F9640"); void func_00180728_002A3DD8(char *) __asm__("func_00180728"); void func_001E3F20_002A3DD8(char *, int) __asm__("func_001E3F20"); void func_001621F8_002A3DD8(int, char *, int) __asm__("func_001621F8"); void func_002A0200_002A3DD8(char *) __asm__("func_002A0200"); void func_002B3198_002A3DD8(int, int) __asm__("func_002B3198");
// MATCH func_002A3DD8
void clas_min_002a3dd8(int *o) { int i; char *p; func_00180728_002A3DD8((char *)(o + 8)); if (o[7]) { func_001E3F20_002A3DD8(D_00343010_002A3DD8, o[7]); o[7] = 0; } if (o[1]) { func_001621F8_002A3DD8(o[1], D_0049A700_002A3DD8, 3776); o[1] = 0; } if (o[3]) { func_001621F8_002A3DD8(o[3], D_0049A700_002A3DD8, 3777); o[3] = 0; } if (o[4]) { func_001621F8_002A3DD8(o[4], D_0049A700_002A3DD8, 3778); o[4] = 0; } if (o[5]) { func_001621F8_002A3DD8(o[5], D_0049A700_002A3DD8, 3779); o[5] = 0; } if (o[6]) { func_001621F8_002A3DD8(o[6], D_0049A700_002A3DD8, 3780); o[6] = 0; } for (i=0;i<D_004A69A8_002A3DD8;i++) {p=D_005F9640_002A3DD8+i*608;func_002A0200_002A3DD8(p);} func_002B3198_002A3DD8(0, 0); }
