/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { char *base; int off; int cnt; unsigned align; } PL_00112B28;
char *strcpy(char *, const char *);
// MATCH func_00112B28
void FUN_00112b28(PL_00112B28 *o, unsigned size, char *src, char *name) { unsigned i = 0; char *base = o->base; char *ent = base + 16; char *dst = base + o->off; int n; if (size != 0) { do { dst[i] = src[i]; i++; } while (i < size); } *(int *)(ent + o->cnt * 36) = o->off; strcpy(ent + o->cnt * 36 + 4, name); o->off = o->off + ((size + o->align - 1) / o->align) * o->align; n = o->cnt + 1; o->cnt = n; *(int *)(base + 8) = n; *(int *)(base + 12) = o->off; }

