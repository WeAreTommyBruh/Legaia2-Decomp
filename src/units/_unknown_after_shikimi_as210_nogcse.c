/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
// cflags: -fno-gcse
#include "../common.h"

typedef struct { volatile unsigned flags; unsigned age; char p8[0x24]; unsigned short note; char p2e[0x20]; unsigned char prio; unsigned char trk; unsigned char ch; unsigned char state; char p52[2]; unsigned char key; char p55[3]; } Vc_2D1C70;
typedef struct { unsigned flags; int pc; char p8[0x10]; unsigned short key; char p1a[0x32]; unsigned short ch; unsigned short trk; } Trk_2D1C70;
Vc_2D1C70 *func_002CFF08_2D1C70(int) __asm__("func_002CFF08");
char *func_002CFF38_2D1C70(void) __asm__("func_002CFF38");
char *func_002CFFA0_2D1C70(void) __asm__("func_002CFFA0");
// MATCH func_002D1C70
int FUN_002d1c70(Trk_2D1C70 *t) {
  long b = 0, a = 0;
  char *g = func_002CFF38_2D1C70();
  char *s = func_002CFFA0_2D1C70();
  Vc_2D1C70 *p = func_002CFF08_2D1C70(0);
  int pc = t->pc;
  int i;
  for (i = 0; i < 48; i++) {
    if (p->state == 2 && (p->flags & 4)) {
      unsigned char *e = *(unsigned char **)(s + 0x10);
      if (p->note == e[3] && p->prio == e[1] && p->key == t->key) {
        if (p->ch == t->ch) a |= 1L << i;
        else b |= 1L << i;
      }
    }
    p++;
  }
  if (a == 0) a = b;
  for (i = 0; i < 48; i++) {
    if ((int)((a >> i) & 1)) *(unsigned long *)(g + 0x28) |= 1L << i;
  }
  t->pc = pc + 4;
  return 0;
}
