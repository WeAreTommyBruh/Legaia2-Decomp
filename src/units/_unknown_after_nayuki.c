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
