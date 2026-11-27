#include "../common.h"
extern char D_00343028[], D_0049ACE0[]; int func_002A1E88(int, int, int, int); int func_0010AF68(char *, int, int, int); void func_001118F8(char *, ...);
// MATCH func_002A1B40
void clas_min_002a1b40(int x, int a, int b, int c) { int r; if (func_002A1E88(x, a, b, c) == 0) return; for (r = -1; r < 0; ) r = func_0010AF68(D_00343028, a, b, c); func_001118F8(D_0049ACE0, a, b, c, r); }
