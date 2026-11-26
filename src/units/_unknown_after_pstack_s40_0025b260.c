// compiler: 990721-r5900
#include "../common.h"
typedef struct { int id; int v; int w8, w12; char d[116]; } E132; extern E132 D_0040F398[][32];
extern char D_00414628[];
int func_0025AE60(int, int);
// MATCH func_0025B260
char *FUN_0025b260(int a, int b) { int i; if (func_0025AE60(a, b) >= 0) { for (i = 0; i < 32; i++) if (b == D_0040F398[a][i].id) break; return D_0040F398[a][i].d; } return D_00414628; }
