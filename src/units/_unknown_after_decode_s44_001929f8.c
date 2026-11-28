// compiler: 991111-01-as210
#include "../common.h"
typedef struct { char c[4]; } C4_29F8;
extern C4_29F8 D_004A3750[];
void func_00192350(void *);
void func_00192928(char *, int *, int *, int *, int *);
void func_00192930(void *, int);
int func_00192C50(int, int, int, int, void *, int, void *, int);
extern char D_00321588[];
// MATCH func_001929F8
int FUN_001929f8(char *o) { C4_29F8 b[4]; int a1, n1, a2, n2; int r; b[0] = D_004A3750[0]; func_00192928(o, &a1, &n1, &a2, &n2); if (n1 + n2 < 4) return 0; r = func_00192C50(a1 & 0xfffffff | 0x20000000, n1, a2 & 0xfffffff | 0x20000000, n2, b, 4, 0, 0); func_00192930(D_00321588, r); func_00192350(o + 0x48); if (*(int *)(o + 0xa8) == 0) *(int *)(o + 0xa8) = 2; return 1; }
