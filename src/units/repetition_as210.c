/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { char c[8]; } V8_00175E80;
typedef struct { char p[408]; V8_00175E80 v; } O_00175E80;
extern V8_00175E80 D_00336530[];
// MATCH func_00175E80
void repetition_00175e80(O_00175E80 *o, unsigned i) { if (i >= 4) i = 0; o->v = D_00336530[i]; }
