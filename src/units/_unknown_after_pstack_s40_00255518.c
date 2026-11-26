// compiler: 990721-r5900
#include "../common.h"
typedef struct { char p[376]; unsigned char n; unsigned char ids[95]; } E472; extern E472 D_00400498[], D_003FE270[];
int func_00255818(int, int);
// MATCH func_00255518
void FUN_00255518(int a, int b) {
  E472 *e; int i, k;
  if (a < 5) e = &D_00400498[a]; else { char *q = (char *)D_003FE270; q -= 2360; e = (E472 *)(q + a * 472); }
  if (func_00255818(a, b) != 0) return;
  if (e->n >= 16) return;
  for (i = 0; i < e->n && b < e->ids[i]; i++) ;
  for (k = e->n; i < k; k--) e->ids[k] = e->ids[k - 1];
  e->ids[i] = b;
  e->n++;
}
