/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

extern int D_004A6DA4, D_004A1A84; void func_0012AEA8(int); int func_00121918(int);
// MATCH func_00121980
void battle_00121980(int a, int step) { func_0012AEA8(8); do { if (D_004A6DA4 < 0) D_004A6DA4 = D_004A1A84 - 1; if (D_004A6DA4 >= D_004A1A84) D_004A6DA4 = 0; if (func_00121918(D_004A6DA4)) return; D_004A6DA4 += step; } while (1); }

typedef struct { char p[5216]; int a; int b; int c; int d; char q[240]; } E_00126798;
extern E_00126798 *D_004A1A20; extern int D_003279A0[];
// MATCH func_00126798
void battle_00126798(void) { int i; for (i = 0; i < 10; i++) { if (D_003279A0[i] != 0) { if (D_004A1A20[i].c <= D_004A1A20[i].a) D_004A1A20[i].c = D_004A1A20[i].a; if (D_004A1A20[i].b >= D_004A1A20[i].d) D_004A1A20[i].d = D_004A1A20[i].b; } } }

extern char D_0053FD00[]; extern int D_004A6DD0, D_004A6D00, D_004A6D04, D_004A6D08;
int func_0012C1E8(void); int func_0015ADE8(char *, int); int func_0015AE08(char *, int); int func_001565B0(int, int, int); int func_00156408(int, int, int); int func_00156D38(int, int, int); int func_00156B58(int, int);
// MATCH func_00118638
void battle_00118638(void) { int h; if (func_0012C1E8() == 0) return; h = func_0015ADE8(D_0053FD00, 0); if (h != 0) { if (D_004A6DD0 == 0) func_001565B0(h, 8768, 15760); if (D_004A6D00 != 0) func_00156408(h, D_004A6D04, D_004A6D08); } h = func_0015AE08(D_0053FD00, 0); if (h != 0) { if (D_004A6DD0 == 0) func_00156D38(h, 9792, 15768); if (D_004A6D00 != 0) func_00156B58(h, D_004A6D04); } D_004A6DD0 = 1; }
