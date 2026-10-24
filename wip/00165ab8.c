// cflags: -O1
#include "../src/common.h"
typedef struct { char pad[16]; int v; } I; typedef struct { I *i; char p[24]; float r; } O;
// 3 words differ
// WIP func_00165AB8
void pachislot_00165ab8(O *o, float f) { *(int *)&o->r = (int)((float)o->i->v * f); }
