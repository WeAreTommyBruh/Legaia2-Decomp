/* Small functions matched by hand. */
// cflags: -O1
#include "common.h"

typedef struct { char p[36]; int a, b, c, d, e, f, g, h; } O_0021A510;
// MATCH func_0021A510
void FUN_0021a510(O_0021A510 *o, int x, int y, int w, int h) { int y2 = y + h; int x2 = x + w; o->h = y2; o->e = x; o->g = x2; o->a = x; o->b = y; o->c = x2; o->d = y; o->f = y2; }

extern int D_004A1510, D_004A12A4; typedef struct { char p[28]; int w; } O_00215A90;
// MATCH func_00215A90
int FUN_00215a90(O_00215A90 *o) { o->w = 0; D_004A1510 = 2; D_004A12A4 = 0; return 0; }
