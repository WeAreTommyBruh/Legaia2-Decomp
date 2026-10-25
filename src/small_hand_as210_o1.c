/* Small functions matched by hand. */
// compiler: 991111-01-as210
// cflags: -O1
#include "common.h"

typedef struct { char pad[16]; int v; } I_00165AB8;
typedef struct { I_00165AB8 *i; char p[24]; float r; } O_00165AB8;
// MATCH func_00165AB8
void pachislot_00165ab8(O_00165AB8 *o, float f) { *(int *)&o->r = (int)((float)o->i->v * f); }

