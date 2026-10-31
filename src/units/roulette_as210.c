/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { char c[8]; } V8_00170910;
typedef struct { char p[136]; V8_00170910 v; } O_00170910;
extern V8_00170910 D_00335628[];
// MATCH func_00170910
void roulette_00170910(O_00170910 *o, unsigned i) { if (i >= 3) i = 0; o->v = D_00335628[i]; }

typedef struct { char c[8]; } V8_00171980;
typedef struct { char p[44]; V8_00171980 v; } O_00171980;
extern V8_00171980 D_00335690[];
// MATCH func_00171980
void roulette_00171980(O_00171980 *o, unsigned i) { if (i >= 5) i = 0; o->v = D_00335690[i]; }
