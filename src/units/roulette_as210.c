/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { char c[8]; } V8_00170910;
typedef struct { char p[136]; V8_00170910 v; } O_00170910;
extern V8_00170910 D_00335628[];
// MATCH func_00170910
void roulette_00170910(O_00170910 *o, unsigned i) { if (i >= 3) i = 0; o->v = D_00335628[i]; }

typedef struct { char c[8]; } V8_00171980;
typedef struct { char p[44]; V8_00171980 v; } O_00171980;
extern V8_00171980 D_00335690[];
// MATCH func_00171980
void roulette_00171980(O_00171980 *o, unsigned i) { if (i >= 5) i = 0; o->v = D_00335690[i]; }


typedef struct { char c[8]; } V8_001705B0;
typedef struct { int p0, p1; int n[12]; char p[36]; int a; char p2[40]; V8_001705B0 x; } O_001705B0;
extern V8_001705B0 D_004A30F0_1705B0[2] __asm__("D_004A30F0"), D_004A30C0_1705B0[2] __asm__("D_004A30C0");
int func_00170548_1705B0(void *, int) __asm__("func_00170548");
// MATCH func_001705B0
int roulette_001705b0(O_001705B0 *o) { int i; int *p = o->n; o->a = 1; o->x = D_004A30F0_1705B0[0]; for (i = 0; i < 12; i++, p++) { if (*p != 0 && func_00170548_1705B0(o, i) == 0) { int v = *p; if (v >= 2000) *p = v - 1000; else if (v >= 200) *p = v - 100; else if (v >= 20) *p = v - 10; else *p = v - 1; o->x = D_004A30C0_1705B0[0]; } } return 0; }
