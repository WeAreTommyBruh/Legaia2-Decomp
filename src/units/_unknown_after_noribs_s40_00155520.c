#include "../common.h"
typedef struct { char p[64]; short adj; char p2[2]; void (*fn)(void *, int); } VT_155520;
typedef struct { char p[48]; int on; VT_155520 *vt; } E_155520;
typedef struct { char p[176]; E_155520 *a[5]; E_155520 *b[32]; } O_155520;
// MATCH func_00155520
void FUN_00155520(O_155520 *o, int a1) {
  E_155520 *e; int i, j;
  for (i = 0; i < 4; i++) { e = o->a[i]; if (e->on != 0) { e->vt->fn((char *)e + e->vt->adj, a1); return; } }
  for (j = 0; j < 32; j++) { e = o->b[j]; if (e->on != 0) { e->vt->fn((char *)e + e->vt->adj, a1); return; } }
}
