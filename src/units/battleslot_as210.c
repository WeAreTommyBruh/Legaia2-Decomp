/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { char c[8]; } V8_00294D98;
typedef struct { char p[76]; V8_00294D98 v; } O_00294D98;
extern V8_00294D98 D_0041EF28[];
// MATCH func_00294D98
void battleslot_00294d98(O_00294D98 *o, unsigned i) { if (i >= 3) i = 0; o->v = D_0041EF28[i]; }
