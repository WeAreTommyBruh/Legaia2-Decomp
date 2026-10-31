/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { int n; void (*fns[64])(int); int args[64]; } S_24ce40_0024CE40;
// MATCH func_0024CE40
void FUN_0024ce40(S_24ce40_0024CE40 *s) { int i; for (i = 0; i < s->n; i++) s->fns[i](s->args[i]); }
