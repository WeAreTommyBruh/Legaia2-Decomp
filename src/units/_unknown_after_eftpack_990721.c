/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

typedef struct { char p[8]; int w8; char q[4]; char *w16; int *w20; int *w24; char *w28; signed char b32; } O__002033C0;
int func_002DD4B0(void *, void *);
// MATCH func_002033C0
char *FUN_002033c0(O__002033C0 *o, char *key, int *out)
{
    int i, off;
    if (out != 0) *out = 0;
    if (o->b32 == 1) {
        off = 0;
        for (i = 0; i < o->w8; i++, off += 16) {
            if (func_002DD4B0(key, o->w28 + off) == 0) {
                if (out != 0) *out = o->w20[i];
                return o->w16 + o->w24[i];
            }
        }
    }
    return 0;
}
