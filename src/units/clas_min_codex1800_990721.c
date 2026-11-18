/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

extern int D_004A69A8_002A3DD8 __asm__("D_004A69A8"); extern char D_00343010_002A3DD8[] __asm__("D_00343010"), D_0049A700_002A3DD8[] __asm__("D_0049A700"), D_005F9640_002A3DD8[] __asm__("D_005F9640"); void func_00180728_002A3DD8(char *) __asm__("func_00180728"); void func_001E3F20_002A3DD8(char *, int) __asm__("func_001E3F20"); void func_001621F8_002A3DD8(int, char *, int) __asm__("func_001621F8"); void func_002A0200_002A3DD8(char *) __asm__("func_002A0200"); void func_002B3198_002A3DD8(int, int) __asm__("func_002B3198");
// MATCH func_002A3DD8
void clas_min_002a3dd8(int *o) { int i; char *p; func_00180728_002A3DD8((char *)(o + 8)); if (o[7]) { func_001E3F20_002A3DD8(D_00343010_002A3DD8, o[7]); o[7] = 0; } if (o[1]) { func_001621F8_002A3DD8(o[1], D_0049A700_002A3DD8, 3776); o[1] = 0; } if (o[3]) { func_001621F8_002A3DD8(o[3], D_0049A700_002A3DD8, 3777); o[3] = 0; } if (o[4]) { func_001621F8_002A3DD8(o[4], D_0049A700_002A3DD8, 3778); o[4] = 0; } if (o[5]) { func_001621F8_002A3DD8(o[5], D_0049A700_002A3DD8, 3779); o[5] = 0; } if (o[6]) { func_001621F8_002A3DD8(o[6], D_0049A700_002A3DD8, 3780); o[6] = 0; } for (i=0;i<D_004A69A8_002A3DD8;i++) {p=D_005F9640_002A3DD8+i*608;func_002A0200_002A3DD8(p);} func_002B3198_002A3DD8(0, 0); }

typedef struct K_29D120 { float f0; int n4; int n8; unsigned fl; struct K_29D120 *next; } K_29D120;
typedef K_29D120 S_29D120;
void func_002BF2C0(K_29D120 *, int);
// MATCH func_0029D120
void clas_min_0029d120(S_29D120 *s, float *out) {
  K_29D120 *k = s->next, *q;
  if (k->n8 == 0) *out = k->f0;
  else *out = s->f0 + (k->f0 - s->f0) * (float)k->n4 / (float)k->n8;
  k->n4++;
  if (k->n8 < k->n4) {
    s->f0 = k->f0;
    if (k->fl & 2) {
      for (q = k; q->next != 0; q = q->next);
      q->next = k;
      k->n4 = 0;
      s->next = k->next;
      k->next = 0;
    } else {
      s->next = k->next;
      func_002BF2C0(k, 3);
    }
  }
}
