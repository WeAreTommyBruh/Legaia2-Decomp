/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { char c[16]; } V16_001DFEA0;
typedef struct { char p[128]; V16_001DFEA0 v; } O_001DFEA0;
// MATCH func_001DFEA0
void mizuki_001dfea0(O_001DFEA0 *o, V16_001DFEA0 *s) { o->v = *s; }
