// compiler: 990721-r5900
#include "../common.h"
typedef struct { char p[5236]; int flags; char q[5472 - 5240]; } P_116AB8;
extern P_116AB8 *D_004A1A20; extern int D_004A6E08, D_004A6D14; extern long long D_004A1300; extern char *D_00323720[]; extern char D_0055B3D0[], D_0042F9C0[], D_0042F9D8[], D_0042F9F0[]; extern char *D_003D1220[][4];
void func_00239568(char *, int, int); int func_0023C728(char *, char *);
// MATCH func_00116AB8
int FUN_00116ab8(int a) {
  if (a == 0) return 0; {
    if ((D_004A1A20[D_004A6E08].flags >> D_004A6D14) & 1) func_00239568(D_0042F9C0, 100, 100); else func_00239568(D_0042F9D8, 100, 100);
    __builtin_memcpy(D_0055B3D0, D_0042F9F0, 9);
    func_0023C728(D_0055B3D0, D_003D1220[D_004A6D14][0]);
    D_00323720[0] = D_0055B3D0;
    if (D_004A1300 & 0x10) D_004A1A20[D_004A6E08].flags ^= 1 << D_004A6D14;
  }
  return 0; }
