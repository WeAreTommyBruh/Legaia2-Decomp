/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A140C, D_004A6E1C; void func_001265D0(int);
// MATCH func_00116FF8
int FUN_00116ff8(int a) { if (a == 0) return 0; if ((D_004A140C & 8) == 0) return 0; func_001265D0(D_004A6E1C); return 0; }

// MATCH func_001171B8
void FUN_001171b8(char *p, int v, int n) { signed char c = v; while (n != 0) { *p = c; n--; p++; } }

extern int D_004A140C_00116F78 __asm__("D_004A140C"); extern char D_0042FA50[], D_0042FA70[], D_0042FA88[], D_003246D0[]; void func_001118F8_00116F78(char *, ...) __asm__("func_001118F8"); void func_0018B998(char *, char *, int); void func_0023F090(int, int, char *, void *); void func_00116F78(void);
// MATCH func_00116F78
int FUN_00116f78(int a) { if (a == 0) return 0; if (a & 8) { func_001118F8_00116F78(D_0042FA50); func_0018B998(D_0042FA70, D_003246D0, 10240); return 0; } if (D_004A140C_00116F78 & 8) func_0023F090(100, 100, D_0042FA88, (void *)func_00116F78); return 0; }
