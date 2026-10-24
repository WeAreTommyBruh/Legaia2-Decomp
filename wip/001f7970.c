#include "../src/common.h"
typedef struct { int a0, a4, a8, a12, a16, a20, a24, a28, a32; } E_1f7970;
typedef struct { char pad[32]; E_1f7970 e[4]; } S_1f7970;
// WIP func_001F7970
void ikumin_001f7970(S_1f7970 *s) { E_1f7970 *e0 = &s->e[0], *e1 = &s->e[1], *e2 = &s->e[2], *e3 = &s->e[3];
e2->a32 = 1;
e2->a12 = 0;
e2->a0 = e2->a4;
e1->a32 = 1;
e1->a12 = 0;
e1->a0 = e1->a4;
e0->a32 = 1;
e0->a12 = 0;
e0->a0 = e0->a4;
e3->a12 = 0;
e3->a32 = 1;
e3->a0 = e3->a4;
}
