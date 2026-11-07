/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef union { long long l[2]; float f[4]; } V4;
typedef struct N_ N_; struct N_ { float x, y, z; N_ *next; };
typedef struct { char p[56]; N_ *head; } O__00162520;
void *func_00162130_162520(int, char *, int) __asm__("func_00162130"); extern char D_0043C628_162520[] __asm__("D_0043C628");
// MATCH func_00162520
void crvmove_00162520(O__00162520 *o, V4 v) { N_ *n = func_00162130_162520(16, D_0043C628_162520, 113); N_ *q; V4 t = v; n->x = t.f[0]; n->next = 0; n->y = t.f[1]; n->z = t.f[2]; q = o->head; if (q == 0) o->head = n; else { for (; q->next != 0; q = q->next) ; q->next = n; } }

