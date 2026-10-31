/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { char c[16]; } V16_0012AF88;
typedef struct { char p[48]; V16_0012AF88 v; } O_0012AF88;
// MATCH func_0012AF88
void battle_0012af88(O_0012AF88 *o, V16_0012AF88 *s) { o->v = *s; }

typedef struct { char c[16]; } V16_0012C918;
typedef struct { char p[128]; V16_0012C918 v; } O_0012C918;
extern O_0012C918 *D_003279A0[]; extern V16_0012C918 D_0055B3B0;
// MATCH func_0012C918
void battle_0012c918(int i) { D_0055B3B0 = D_003279A0[i]->v; }
