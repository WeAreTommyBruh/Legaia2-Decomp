/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

typedef struct { int on; char c[6]; } S_113038;
extern char D_0053F700[2][256]; extern char D_0042F1D0[], D_0042F1F0[];
void func_002C9658(int); int func_002C98B8(int, int, char *); int func_001114C0(void); void func_001118F8(char *, ...);
// MATCH func_00113038
void FUN_00113038(S_113038 *s) {
  int i; char *p;
  if (s->on != 0) return;
  for (i = 5, p = &s->c[5]; i >= 0; i--) *p-- = 0;
  s->on = 1;
  func_002C9658(0);
  if (func_002C98B8(0, 0, D_0053F700[0]) == 0) { func_001118F8(D_0042F1D0); return; }
  if (func_001114C0() == 0 && func_002C98B8(1, 0, D_0053F700[1]) == 0) func_001118F8(D_0042F1F0);
}
