/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

typedef struct { char p[56]; unsigned char a, b, c, d; char p2[8]; float f1; float f2; } O_00201CE0;
// MATCH func_00201CE0
void sprite_00201ce0(O_00201CE0 *o) { o->d = 127; o->f2 = 1.0f; o->a = 127; o->b = 127; o->c = 127; o->f1 = 1.0f; }
