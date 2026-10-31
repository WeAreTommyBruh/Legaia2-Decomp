/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { char pad[8]; short adj; short p; void (*fn)(void *, int); } VT_1645a0_001645A0;
typedef struct N_1645a0_001645A0 { char pad[92]; struct N_1645a0_001645A0 *next; char pad2[8]; VT_1645a0_001645A0 *vt; } N_1645a0_001645A0;
typedef struct { N_1645a0_001645A0 *head; } S_1645a0_001645A0;
// MATCH func_001645A0
void FUN_001645a0(S_1645a0_001645A0 *s) { N_1645a0_001645A0 *n = s->head->next; while (n != s->head) { N_1645a0_001645A0 *nx; nx = n->next; if (n != 0) n->vt->fn((char *)n + n->vt->adj, 3); n = nx; } }
