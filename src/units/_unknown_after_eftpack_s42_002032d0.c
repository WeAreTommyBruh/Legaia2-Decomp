#include "../common.h"
typedef struct { int a, b, n, c, d; int *vals; int e; char *names; signed char f; } O;
int func_002DD4B0(char *, char *);
// MATCH func_002032D0
int FUN_002032d0(O *o, char *name) { int i, off; if (o->f != 1) return 0; for (i = 0, off = 0; i < o->n; i++, off += 16) if (func_002DD4B0(name, o->names + off) == 0) return o->vals[i]; return 0; }
