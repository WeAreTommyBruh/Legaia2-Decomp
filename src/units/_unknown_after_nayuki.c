/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[100]; void *w100; } Q_001DFA00;
typedef struct { char p[16]; short adj; short pad; void (*fn)(void *); } VT_001DFA00;
typedef struct { char p[100]; VT_001DFA00 *vt; } P_001DFA00;
typedef struct { char p[304]; P_001DFA00 *w304; char q[252]; int w560; } S_001DFA00;
extern S_001DFA00 D_003B0BD0; void func_001E2530(P_001DFA00 *); void func_001E06C0(P_001DFA00 *, int);
// MATCH func_001DFA00
int FUN_001dfa00(int a) { S_001DFA00 *s = &D_003B0BD0; P_001DFA00 *p; if (s->w560 != 2) return -1; p = s->w304; func_001E2530(p); func_001E06C0(p, a); p->vt->fn((char *)p + p->vt->adj); return 1; }

int func_001E24D8(void *); int func_001E24E8(void *); int func_001E24E0(void *); void func_001E2530_001DF7B8(void *) __asm__("func_001E2530"); int func_001E2588(void *); void func_001E06C0_001DF7B8(void *, int) __asm__("func_001E06C0"); int func_001322C0_001DF7B8(int, int, int) __asm__("func_001322C0");
// MATCH func_001DF7B8
int FUN_001df7b8(void *o, int a, int b) { if (func_001E24D8(o) == 0 && func_001E24E8(o) == 0) return func_001322C0_001DF7B8(a, b, 1); if (func_001E24E0(o) == 0) return 0; func_001E2530_001DF7B8(o); if (func_001E2588(o) != 1) return 0; func_001E06C0_001DF7B8(o, 0); return 0; }

extern float D_004A02B8_001DF8B0 __asm__("D_004A02B8"), D_004A02BC_001DF8B0 __asm__("D_004A02BC"), D_004A02C0_001DF8B0 __asm__("D_004A02C0"), D_004A02C4_001DF8B0 __asm__("D_004A02C4"), D_004A02C8_001DF8B0 __asm__("D_004A02C8"); extern int D_003B0BD0_001DF8B0[] __asm__("D_003B0BD0");
int func_001DFA70_001DF8B0(char *, int, int) __asm__("func_001DFA70"); void func_001E2488_001DF8B0(int, int) __asm__("func_001E2488"); void func_001E24A8_001DF8B0(int, int) __asm__("func_001E24A8"); void func_001E2478_001DF8B0(int, int) __asm__("func_001E2478");
void func_001E01B0_001DF8B0(int, float) __asm__("func_001E01B0"); void func_001E01A0_001DF8B0(int, float, float, float) __asm__("func_001E01A0"); void func_001E00C0_001DF8B0(int, int, int, float, float) __asm__("func_001E00C0");
void func_001E0188_001DF8B0(int, float, float, float) __asm__("func_001E0188"); void func_001E0200_001DF8B0(int, float, float, float, float) __asm__("func_001E0200");
void func_001DFED0_001DF8B0(int, float) __asm__("func_001DFED0"); void func_001DFED8_001DF8B0(int, float) __asm__("func_001DFED8"); void func_001DFEE0_001DF8B0(int, float) __asm__("func_001DFEE0");
// MATCH func_001DF8B0
int FUN_001df8b0(void) {
  char buf[16]; int h;
  h = func_001DFA70_001DF8B0(buf, 0, 0);
  if (h == 0) return -1;
  func_001E2488_001DF8B0(h, 1);
  func_001E24A8_001DF8B0(h, 1);
  func_001E2478_001DF8B0(h, 1);
  func_001E01B0_001DF8B0(h, 0.0f);
  func_001E01A0_001DF8B0(h, D_004A02B8_001DF8B0, 0.0f, 0.0f);
  func_001E00C0_001DF8B0(h, 20, 20, D_004A02BC_001DF8B0, D_004A02BC_001DF8B0);
  func_001E0188_001DF8B0(h, 0.0f, D_004A02C0_001DF8B0, 100.0f);
  func_001E0200_001DF8B0(h, D_004A02C4_001DF8B0, -0.5f, 0.02f, 0.0f);
  func_001DFED0_001DF8B0(h, 10.0f);
  func_001DFED8_001DF8B0(h, 100.0f);
  func_001DFEE0_001DF8B0(h, 0.0f);
  D_003B0BD0_001DF8B0[76] = h;
  D_003B0BD0_001DF8B0[140] = 2;
  return 1;
}
