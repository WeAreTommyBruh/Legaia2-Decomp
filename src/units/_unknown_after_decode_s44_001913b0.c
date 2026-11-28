#include "../common.h"
typedef struct { char p[0x44]; int base; int size; int rd; } R_13B0;
// MATCH func_001913B0
void FUN_001913b0(int *a, int *b, int *c, int *d, R_13B0 *s, int pos) { int size = s->size; int rd = s->rd; int n = (pos + size - rd - 0x400) % size; n = n / 1024 * 1024; if (n <= size - rd) { *a = s->base + rd; *b = n; *c = 0; *d = 0; return; } *a = s->base + rd; *b = s->size - s->rd; *c = s->base; *d = n - (s->size - s->rd); }
