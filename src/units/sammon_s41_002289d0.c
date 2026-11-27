#include "../common.h"
typedef struct { char p[40]; int f; char q[12]; } E56; typedef struct { char p[2064]; E56 *t; } O;
int func_00223620(O *, int); int func_00228940(void);
// MATCH func_002289D0
int sammon_002289d0(O *o, int b) { int i, r; if (func_00228940() != b) return 0; for (i = 0; i < 32; i++) { r = func_00223620(o, i); if (r >= 0) { if (o->t[i].f & 0x200) return 1; } else { if (o->t[i].f & 0x200) return 1; i = 32; } } return 2; }
