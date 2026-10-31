/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

typedef struct { int a, b, c, d, e; } O_001948A0;
// MATCH func_001948A0
void FUN_001948a0(O_001948A0 *o, int a, char *p, int n) { o->d = 0; o->a = a; o->c = 0; o->b = (int)p; o->e = n; if (n > 0) { do { *(int *)p = 0; p += 0x4ce40; } while (--n != 0); } }
