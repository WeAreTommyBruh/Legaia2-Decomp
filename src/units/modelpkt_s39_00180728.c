// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"
typedef struct { char p0[52]; void *a; char p1[4]; int *b; } O_;
volatile short func_001621F8(void *, char *, int); extern char D_0043E318[];
// MATCH func_00180728
void modelpkt_00180728(O_ *o) {
  int *p; int n, i, i1; register int j __asm__("$17"); int *r; unsigned char *q;
  func_001621F8(o->a, D_0043E318, 3532);
  p = o->b; o->a = 0;
  if (p != 0) {
    n = p[0]; i = 0;
    if (n > 0) {
      do {
        int *t;
        j = 0;
        q = (char *)p + p[i + 1] * 4;
        t = (int *)(q + 16);
        if (q[3] != 0) { r = t; do { j++; func_001621F8((void *)r[16], D_0043E318, 3545); r[16] = 0; r = r + 40; { register int c __asm__("$2"); c = j < (unsigned char)q[3]; if (!c) break; } } while (1); }
        i++;
      } while (i < n);
    }
  }
}
