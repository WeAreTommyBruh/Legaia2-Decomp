#include "../common.h"
extern char D_0042F050[], D_004A1588[]; int func_001118F8(char *, ...);
// MATCH func_00112878
char *FUN_00112878(int *p, int i) { int b = *p; int q; if (b == 0) { func_001118F8(D_0042F050); return 0; } q = b + 16; if (i >= *(int *)(b + 8)) { func_001118F8(D_004A1588); return 0; } return (char *)b + *(int *)(i * 36 + q); }
