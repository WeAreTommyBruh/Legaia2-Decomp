/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { char c[8]; } V8_00178700;
typedef struct { char p[476]; V8_00178700 v; } O_00178700;
extern V8_00178700 D_00336738[];
// MATCH func_00178700
void shuffle_00178700(O_00178700 *o, unsigned i) { if (i >= 4) i = 0; o->v = D_00336738[i]; }

typedef struct { char c[8]; } V8_00177D00;
typedef struct { char pad[476]; V8_00177D00 v; } O_00177D00;
extern V8_00177D00 D_004A3338[];
int func_00177BB0(void *);
// MATCH func_00177D00
int shuffle_00177d00(O_00177D00 *o){ o->v = D_004A3338[0]; func_00177BB0(o); return 0; }
