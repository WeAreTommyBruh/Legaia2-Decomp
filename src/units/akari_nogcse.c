/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern char D_004A380A; extern char D_00346780[]; extern char D_0035A780[];
int func_00202920(int); int func_002034A0(int, int, int); int func_00203378(int, int); int func_001E3D98(int, int, int);
// MATCH func_001E3600
int akari_001e3600(int a, int b) { int n; int i; int x; int y; if (D_004A380A == 0) return 0; n = func_00202920(b); if (n <= 0) return 0; for (i = 0; i < n; i++) { x = func_002034A0(b, i, 0); y = func_00203378(b, i); func_001E3D98(a, x, y); } { char *b = D_00346780; short *p = (short *)(b + 74322); for (i = 290; i >= 0; i--) { *p = 0; p = (short *)((char *)p - 256); } } { char *b = D_0035A780; short *p = (short *)(b + 19026); for (i = 74; i >= 0; i--) { *p = 0; p = (short *)((char *)p - 256); } } return n; }
