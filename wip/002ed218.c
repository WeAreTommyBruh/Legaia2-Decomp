#include "../src/common.h"
extern int D_006357C0[]; extern char D_006359C0[];
int func_002ECC40(int); int func_002ECD40(void);
int func_002E8928(char *, int, int, int *, int, int *, int, int, int);
// WIP func_002ED218
int FUN_002ed218(int x) { int r; if (func_002ECC40(x) < 0) return -65536; if (func_002ECD40() != 0) return -65540; D_006357C0[0] = x; r = func_002E8928(D_006359C0, 8, 0, D_006357C0, 4, D_006357C0, 4, 0, 0); if (r < 0) return -65537; return D_006357C0[0]; }
