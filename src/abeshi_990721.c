/* Small functions of abeshi.cpp built like after_abeshi_990721.c. Matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "common.h"

typedef struct { char c[8]; } V8;
/* a record with a countdown at +308 and two 8-byte values at +412 and +420 */
typedef struct { char pad[308]; int n; char pad2[412 - 312]; V8 a; V8 b; } Cd;
/* a record with a countdown at +20 and an 8-byte value at +412 */
typedef struct { char pad[20]; int n; char pad2[412 - 24]; V8 a; } Fd;
extern V8 D_004A5A18[2];

// MATCH func_0025F1F8
void abeshi_0025f1f8(int *p, int a)
{
    int v = a ? a : 1;
    p[0] = v;
    p[1] = v;
}

// MATCH func_0025F220
int abeshi_0025f220(Cd *o)
{
    if (o->n-- <= 0) {
        o->n = 0;
        o->a = o->b;
    }
    return 0;
}

// MATCH func_0025F740
int abeshi_0025f740(Fd *o)
{
    o->n -= 16;
    if (o->n < 0) {
        o->n = 0;
        o->a = D_004A5A18[0];
    }
    return 0;
}
