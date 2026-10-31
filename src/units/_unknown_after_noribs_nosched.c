/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

typedef struct { char p[52]; void *vt; char q[56]; float f112; int w116, w120; float f124; char r[4]; } O_00154B10;
extern float D_0049FF68; extern char D_0043B3B8[]; void func_0015EA80(void *, int, int, int, int);
// MATCH func_00154B10
O_00154B10 *FUN_00154b10(O_00154B10 *o) { o->w116 = 0; o->w120 = 0; o->f112 = 1.0f; o->f124 = D_0049FF68; o->vt = D_0043B3B8; func_0015EA80((char *)o + 128, 0, 3, 14, 6); return o; }
