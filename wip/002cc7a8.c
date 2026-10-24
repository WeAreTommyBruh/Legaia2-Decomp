#include "../src/common.h"
extern int D_00426394[]; extern int D_00426370[]; extern int D_00426368[]; extern char D_00427510[];
int func_002CBAE8(void); int func_002CB978(int); int func_002E8928(char *, int, int, int, int, int, int, void *, int *); void func_002E58C0(int); void func_002CB108(void);
// WIP func_002CC7A8
int FUN_002cc7a8(void) { int *p; if (func_002CBAE8() == 6) return 0; if (func_002CB978(10) == 0) return 0; p = D_00426394;
D_00426370[0] = 1;
*p = 5;
if (func_002E8928(D_00427510, 6, 1, 0, 0, 0, 0, func_002CB108, p) < 0) { *p = 0; D_00426370[0] = 0; func_002E58C0(D_00426368[0]); return 0; } return 1; }
