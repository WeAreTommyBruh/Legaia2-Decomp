/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { int n; int a; void *p; } O_0024CEA8;
extern char D_0045E008[]; void *func_00162130(int, void *, int);
// MATCH func_0024CEA8
void pstack_0024cea8(O_0024CEA8 *o, int n) { o->n = n; o->p = func_00162130(n * 4, D_0045E008, 35); }
