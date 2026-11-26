// compiler: 990721-r5900
#include "../common.h"
typedef struct { char p[376]; unsigned char n; unsigned char ids[95]; } E472; extern E472 D_00400498[], D_003FE270[];
typedef struct { char p[8]; short s8; char q[10]; } E20; extern E20 D_003E3D20[];
// MATCH func_00255818
int FUN_00255818(int a, int b) {
  E472 *e; int i;
  if ((unsigned)a >= 10 || b <= 0 || (unsigned)b >= 94) return -1;
  if (a < 5) { if (b < a * 16 + 1 || (a + 1) * 16 < b) return -1; }
  if ((&D_003E3D20[b])->s8 == 100) return -1;
  if (a < 5) e = &D_00400498[a]; else { char *q = (char *)D_003FE270; q -= 2360; e = (E472 *)(q + a * 472); }
  for (i = 0; i < e->n; i++) if (e->ids[i] == b) return 1;
  return 0;
}
