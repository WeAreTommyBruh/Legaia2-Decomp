/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern int D_004A7138; extern char D_005F6A40[]; void func_00239568(char *);
// MATCH func_00239660
void FUN_00239660(void) { int i; for (i = 0; i < D_004A7138; i++) func_00239568(D_005F6A40 + i * 64); }

// MATCH func_0023C728
int FUN_0023c728(char *d, char *s) { while (*d++); d--; while (*s) *d++ = *s++; *d = 0; return 1; }

extern int D_004A1A20;
// MATCH func_00238030
void FUN_00238030(int param_1,int *param_2)  { int iVar1;  if (*param_2 < 0) { *param_2 = 0; } iVar1 = *(int *)(*(int *)(param_1 * 0x1560 + D_004A1A20 + 0x1444) + 4); if (iVar1 < *param_2) { *param_2 = iVar1; } return; }

