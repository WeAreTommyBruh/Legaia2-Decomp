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

/* work.cpp: a buffer allocated on first use */
extern char D_0045D4F0[];
void *MemAllocDbg(int, char *, int);
typedef struct { char pad[384]; void *buf; } Buf384;
typedef struct { char pad[388]; void *buf; } Buf388;

// MATCH func_00245E58
void work_00245e58(Buf384 *s)
{
    if (s->buf == 0)
        s->buf = MemAllocDbg(1024, D_0045D4F0, 28);
}

// MATCH func_00245EA0
void work_00245ea0(Buf388 *s)
{
    if (s->buf == 0)
        s->buf = MemAllocDbg(1024, D_0045D4F0, 37);
}

/* work.cpp: a byte looked up through a table of offsets */
typedef struct { char pad[152]; int *t; char pad2[188 - 156]; short i; } Tbl;

// MATCH func_002464B0
int work_002464b0(Tbl *s)
{
    int *t = s->t;

    if (t == 0)
        return 0;
    return ((u8 *)t)[t[s->i + 1]];
}

/* work.cpp: the address of entry idx of a table of offsets (0 when out of range) */
typedef struct { char pad[152]; int *t; } Tbl2;

// MATCH func_00246A40
int work_00246a40(Tbl2 *s, int idx)
{
    int *t = s->t;

    if (t == 0)
        return 0;
    if (idx < 0 || (unsigned)idx >= (unsigned)t[0])
        return 0;
    return (int)t + t[idx + 1] + 8;
}

void func_00246140(void *);
void func_00108B80(void *);

// MATCH func_00245F98
void work_00245f98(void *p, int flags)
{
    func_00246140(p);
    if (flags & 1)
        func_00108B80(p);
}
