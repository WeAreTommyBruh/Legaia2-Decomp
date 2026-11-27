#include "../common.h"
typedef struct { unsigned long key; unsigned short sub; } E_A358;
typedef struct { char p[10]; unsigned short n; char q[4]; E_A358 e[1]; } T_A358;
// MATCH func_0018A358
E_A358 *file_0018a358(T_A358 *t, unsigned long key, unsigned sub) {
  int lo, hi, mid; E_A358 *e; E_A358 *b = t->e;
  lo = 0; hi = t->n - 1;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    e = &b[mid];
    { unsigned long k = e->key; unsigned s = e->sub; if (key < k) hi = mid - 1; else if (key > k) lo = mid + 1; else if (sub < s) hi = mid - 1; else if (sub > s) lo = mid + 1; else return e; }
  }
  return 0;
}
