/* Small functions of several source files, matched by hand. */
#include "common.h"

/* a write cursor at +16: store a zero word and advance */
typedef struct { char pad[16]; int *cur; } Cursor;
/* two words read from a stream whose position is kept in *pp */
typedef struct { char pad[12]; int a, b; } Pair12;
typedef struct { char pad[20]; int a, b; } Pair20;

// MATCH func_00156910
void FUN_00156910(Cursor *s)
{
    *s->cur++ = 0;
}

// MATCH func_0015F588
void FUN_0015f588(Cursor *s)
{
    *s->cur++ = 0;
}

// MATCH func_001808D8
void FUN_001808d8(Cursor *s)
{
    *s->cur++ = 0;
}

// MATCH func_00163FC8
int FUN_00163fc8(Pair12 *s, int **pp)
{
    int *p = *pp;

    s->a = *p++;
    *pp = p + 1;
    s->b = *p++;
    return 0;
}

// MATCH func_00163FF0
int FUN_00163ff0(Pair20 *s, int **pp)
{
    int *p = *pp;

    s->a = *p++;
    *pp = p + 1;
    s->b = *p++;
    return 0;
}
