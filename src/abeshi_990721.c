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
extern char D_00489110[];
int DbgPrintf(char *, ...);
extern V8 D_004A5A00[2];
void FUN_0025de00(void *, float);
extern V8 D_004A59F8[2];
extern char D_00489038[];
void abeshi_0025ee38(void *);
int abeshi_0025ea38(void *, void *);
void *MemAllocDbg(int, char *, int);

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

/* resets the record (countdown and the 8-byte value) after a call */
// MATCH func_0025F250
int abeshi_0025f250(Cd *o)
{
    abeshi_0025ee38(o);
    o->n = 0;
    o->a = D_004A59F8[0];
    return 0;
}

// MATCH func_0025FE10
int abeshi_0025fe10(void *o)
{
    return abeshi_0025ea38(MemAllocDbg(428, D_00489038, 995), o);
}

/* fades four sub-records in over 75 frames, then snaps to 1.0 */
typedef struct { char pad[308]; int n; char pad2[412 - 312]; V8 a; } Fade;
// MATCH func_0025F298
int abeshi_0025f298(Fade *o)
{
  float f;
  if (++o->n < 75) {
    f = (float)((double)o->n / 75.0);
    FUN_0025de00((char *)o + 28, f);
    FUN_0025de00((char *)o + 96, f);
    FUN_0025de00((char *)o + 164, f);
    FUN_0025de00((char *)o + 232, f);
  } else {
    f = 1.0f;
    FUN_0025de00((char *)o + 28, f);
    FUN_0025de00((char *)o + 96, f);
    FUN_0025de00((char *)o + 164, f);
    FUN_0025de00((char *)o + 232, f);
    o->a = D_004A5A00[0];
  }
  return 0;
}

/* prints the three words when the first is not the sum of the other two, and returns the last */
// MATCH func_0025FDC8
int abeshi_0025fdc8(int *o)
{
    if (o[0] != o[2] + o[3])
        DbgPrintf(D_00489110, o[0], o[2], o[3]);
    return o[3];
}
