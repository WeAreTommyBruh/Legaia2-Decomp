// compiler: 991111-01-as210
#include "../common.h"
typedef struct { char p[4928]; int a[2][128]; int b[2][128]; char q[7004 - 6976]; int f[8]; } G_220820;
extern G_220820 *D_004A1AA8; extern char D_00343010[];
int akari_001e3890(char *, int, int); void FUN_001e3e38(char *, int, int); void akari_001e26a8(char *, int, int, int, float); void FUN_001e4308(char *, int, int);
// MATCH func_00220820
int FUN_00220820(int i, int j, int a, int b, float f) { int r; if (D_004A1AA8->f[i] == 0) return 0; r = akari_001e3890(D_00343010, D_004A1AA8->a[i][j], D_004A1AA8->b[i][j]); FUN_001e3e38(D_00343010, r, 0); akari_001e26a8(D_00343010, r, a, b, f); FUN_001e4308(D_00343010, r, 1); return r; }
