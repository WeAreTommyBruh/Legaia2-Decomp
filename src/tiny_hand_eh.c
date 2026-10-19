/* Small functions built with exceptions on (no tail calls). Matched by hand. */
// cflags: -fexceptions
#include "common.h"

typedef struct { int a, b, c; } Triple;
void func_00246CE0(int, int, int, int);

// MATCH func_00246D88
void work_00246d88(Triple *s, int x)
{
    func_00246CE0(x, s->a, s->b, s->c);
}
