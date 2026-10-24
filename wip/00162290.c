#include "../src/common.h"
extern int *D_004A6F44;
typedef struct N_162290 { struct N_162290 *next; int pad; unsigned v; } N_162290;
typedef struct { char pad[128]; N_162290 head; } G_162290;
// 12 words differ
// WIP func_00162290
unsigned FUN_00162290(void) { G_162290 *g = *(G_162290 **)D_004A6F44; N_162290 *n; unsigned m = 0; for (n = g->head.next; n != &g->head; n = n->next) if (n->v > m) m = n->v; return m; }
