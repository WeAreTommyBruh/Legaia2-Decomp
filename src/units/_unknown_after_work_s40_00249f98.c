// compiler: 990721-r5900
// cflags:
#include "../common.h"
extern int D_004A7210, D_004A720C; extern int D_005F7700[]; extern char D_0045D9C0[];
int func_001118F8(char *, ...);
int func_002E8758(void *, unsigned, int);
// MATCH func_00249F98
int FUN_00249f98(void) { unsigned i; if (D_004A7210 == 0) return 0; while (1) { if (func_002E8758(D_005F7700, 0x80000210, 0) < 0) { func_001118F8(D_0045D9C0); while (1); } if (D_005F7700[9] != 0) break; i = 0x10000; do { i--; } while (i != 0xffffffff); } D_004A720C = 1; return 0; }
