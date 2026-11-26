// compiler: 990721-r5900
#include "../common.h"
typedef struct { int id; int v; char p[124]; } E132; extern E132 D_0040F398[][32];
extern int D_003FEC28[], D_00314CC8[]; extern int D_004A12A4, D_004A66C4;
int func_0025AE60(int, int);
// MATCH func_0025B6E0
int FUN_0025b6e0(int a, int b) { int i; if (func_0025AE60(a, b) >= 0) { for (i = 0; i < 32; i++) if (b == D_0040F398[a][i].id) break; if (b == 10 && a == 0 && D_003FEC28[0] != 0) { if (D_004A12A4 == 11 && D_00314CC8[0] == 173 && (D_004A66C4 & 1)) return D_0040F398[a][i].v; return 10; } return D_0040F398[a][i].v; } return -1; }
