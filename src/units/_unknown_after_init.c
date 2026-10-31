/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { int n; int a[64]; int b[64]; } O_0024CDD0;
extern char D_0045DFF0[]; void func_001118F8_0024CDD0(char *) __asm__("func_001118F8");
// MATCH func_0024CDD0
int FUN_0024cdd0(O_0024CDD0 *o, int a, int b) { if (o->n >= 64) { func_001118F8_0024CDD0(D_0045DFF0); return 0; } o->a[o->n] = a; o->b[o->n] = b; o->n++; return 1; }
