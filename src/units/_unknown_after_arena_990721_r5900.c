/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

typedef struct { int a[3]; } K_2231D8;
typedef struct { char p0[4872]; char x[600]; } B_2231D8;
extern int D_004A14B0, D_004A1A8C; extern K_2231D8 D_0045A0E8[]; extern B_2231D8 *D_004A1A20; extern char D_004A4DF0[];
void func_00239568(char *, ...); void func_00127000(int, int, int, int, int, char *, int, float, int, int);
// MATCH func_002231D8
void FUN_002231d8(char *p, int c) {
  K_2231D8 k; int i; int *q;
  D_004A14B0 = c;
  k = D_0045A0E8[0];
  for (i = 0; i < D_004A1A8C; i++) {
    int v = k.a[i];
    func_00239568(D_004A4DF0, v, p, D_004A1A20[i].x);
    func_00127000(3, i, 0, 0, v, p + 12, c, 0.0f, 0, 0x808080);
    func_00127000(3, i, 1, 0, v, p + 24, c, 0.0f, 0, 0x808080);
  }
  D_004A14B0 = 128;
}
