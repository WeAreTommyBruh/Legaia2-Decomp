/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { char c[8]; } V8_0025F778;
typedef struct { char p[412]; V8_0025F778 v; } O_0025F778;
extern V8_0025F778 D_00402450[];
// MATCH func_0025F778
void abeshi_0025f778(O_0025F778 *o, unsigned i) { if (i >= 4) i = 0; o->v = D_00402450[i]; }
