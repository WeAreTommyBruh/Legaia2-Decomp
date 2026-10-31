/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { char c[8]; } V8_0016E4E0;
typedef struct { char p[104]; V8_0016E4E0 v; } O_0016E4E0;
extern V8_0016E4E0 D_00334E70[];
// MATCH func_0016E4E0
void darts_0016e4e0(O_0016E4E0 *o, unsigned i) { if (i >= 8) i = 0; o->v = D_00334E70[i]; }
