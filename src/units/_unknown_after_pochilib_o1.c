/* Functions of this report unit, matched by hand. */
// cflags: -O1
#include "../common.h"

typedef struct N_001624E0 { int a[3]; struct N_001624E0 *n; } N_001624E0;
// MATCH func_001624E0
N_001624E0 *FUN_001624e0(char *o) { N_001624E0 *p = *(N_001624E0 **)(o + 56); if (p != 0 && p->n != 0) { do { p = p->n; } while (p->n != 0); } return p; }
