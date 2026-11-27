#include "../common.h"
typedef struct { char p[32]; unsigned char k; } K; typedef struct { char p[12]; int n; char q[0x140 - 16]; K *l[1]; } T;
static inline int cnt(T *t) { return t->n; }
// MATCH func_00291D00
int FUN_00291d00(char *o, char a) { T *t = *(T **)(o + 0xa8); unsigned i; int c = 0; K **l; l = t->l; for (i = 0; i < cnt(t); i++) { if (l[i]->k == a) c++; } return c; }
