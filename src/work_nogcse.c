/* work.cpp functions that need -fno-gcse. Matched by hand. */
// cflags: -fno-gcse
#include "common.h"

int DbgPrintf(char *, ...);
extern char D_0045D500[], D_0045D510[];
typedef struct { char pad[384]; char *buf; } PoolA;
typedef struct { char pad[388]; char *buf; } PoolB;

/* the 16-byte entry i of the pool's buffer (the last one when i is out of range) */
// MATCH func_00245EE8
char *work_00245ee8(PoolA *s, unsigned i)
{
    if (s->buf == 0)
        return 0;
    if (i >= 64) {
        DbgPrintf(D_0045D500);
        i = 63;
    }
    return s->buf + i * 16;
}

// MATCH func_00245F40
char *work_00245f40(PoolB *s, unsigned i)
{
    if (s->buf == 0)
        return 0;
    if (i >= 64) {
        DbgPrintf(D_0045D510);
        i = 63;
    }
    return s->buf + i * 16;
}
