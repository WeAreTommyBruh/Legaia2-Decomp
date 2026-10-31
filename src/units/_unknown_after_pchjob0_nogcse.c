/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct N__0020B3A8 { struct N__0020B3A8 *next; int p[3]; void (*fn)(void *); } N__0020B3A8;
extern N__0020B3A8 *D_002F9804_0020B3A8[] __asm__("D_002F9804");
void func_00205F78(void *); void func_00207728(void *); void func_002077B8(void *); void func_00207848(void *);
// MATCH func_0020B3A8
void FUN_0020b3a8(void)
{
    N__0020B3A8 *n;
    for (n = D_002F9804_0020B3A8[0]; n != 0; n = n->next) {
        void (*f)(void *) = n->fn;
        if (f == func_00205F78 || f == func_00207728 || f == func_002077B8 || f == func_00207848)
            f(n);
    }
}
