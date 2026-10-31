/* Functions of this report unit, matched by hand. */
// cflags: -fexceptions
#include "../common.h"

typedef struct { int n; } S_001809D0;
void func_001809F8(S_001809D0 *);
// MATCH func_001809D0
void FUN_001809d0(S_001809D0 *s) { s->n++; func_001809F8(s); }
