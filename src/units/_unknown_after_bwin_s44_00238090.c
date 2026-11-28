#include "../common.h"
typedef int u128 __attribute__((mode(TI)));
typedef struct { u128 q[3]; } S48_8090;
// MATCH func_00238090
void FUN_00238090(S48_8090 *d, S48_8090 *s) { u128 c, b, a; volatile S48_8090 t; a = t.q[0]; b = t.q[1]; c = t.q[2]; b = s->q[1]; c = s->q[2]; a = s->q[0]; d->q[1] = b; d->q[2] = c; d->q[0] = a; }
