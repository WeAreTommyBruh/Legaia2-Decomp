/* Matched functions from this unit. */
#include "../common.h"

typedef struct { char p[6680]; unsigned short t[5][236]; } B_254040;
extern B_254040 D_003FEBA8;
extern unsigned short D_004005C0[][236];
int func_00250B68(void);
// MATCH func_00254040
int FUN_00254040(unsigned p)
{
  int n, i, j;
  n = func_00250B68();
  { char *bb = (char *)&D_003FEBA8; char *tb = bb + 6680; for (i = 0; i < 5; i++) { int o = i * 472 + 8; unsigned short *q = (unsigned short *)(o + (int)tb); for (j = 11; j >= 0; j--) { if (*q == p) n++; q++; } } }
  return n;
}
