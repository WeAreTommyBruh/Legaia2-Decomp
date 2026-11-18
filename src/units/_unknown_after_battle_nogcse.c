/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern char *D_004A1A20; extern char D_00431C68[]; void func_001118F8_0012D248(char *, ...) __asm__("func_001118F8");
// MATCH func_0012D248
void FUN_0012d248(void) { int i, off = 0; for (i = 0; i < 20; i++) { char *e = (char *)(off + (int)D_004A1A20); int *p, *q; off += 5472; p = *(int **)(e + 5424); if (p) { *(int *)(e + 5364) = p[17]; func_001118F8_0012D248(D_00431C68, i, p[17]); } else { q = *(int **)(e + 5380); if (q) *(int *)(e + 5364) = q[17]; } } }

typedef struct { char p0[188]; short h188; char p190[2]; unsigned w192; char p196[4]; float f200; char p204[172]; short h376, h378; } U_12CE40;
typedef struct { char p0[56]; int w56; } Q_12CE40;
typedef struct { char p0[4816]; unsigned fl; char p4820[164]; int w4984; char p4988[200]; Q_12CE40 *w5188; char p5192[280]; } B_12CE40;
extern U_12CE40 *D_003279A0[]; extern B_12CE40 *D_004A1A20_12CE40 __asm__("D_004A1A20"); extern int D_004A6E24; extern char D_00431BF0[];
void func_001118F8(char *, ...); void func_0021B550(B_12CE40 *);
// MATCH func_0012CE40
void FUN_0012ce40(void) {
  int i; U_12CE40 **p = D_003279A0;
  for (i = 0; i < 10; i++, p++) {
    if (*p != 0 && !(D_004A1A20_12CE40[i].fl & 0x800)) {
      U_12CE40 *u;
      if (D_004A6E24 != 0) func_001118F8(D_00431BF0, i, D_004A1A20_12CE40[i].w5188->w56);
      u = *p;
      u->h188 = 0;
      u->h376 = 0;
      u->h378 = 0;
      u->f200 = 1.0f;
      u->w192 &= ~4;
      D_004A1A20_12CE40[i].w4984 = 0;
      D_004A1A20_12CE40[i].fl &= ~0x40000;
      func_0021B550(&D_004A1A20_12CE40[i]);
    }
  }
}
