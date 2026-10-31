/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char pad[8]; int a; char p2[4]; int b; char p3[4]; int c; } S_00164808;
// MATCH func_00164808
void FUN_00164808(S_00164808 *s, int x){ s->b = x; s->c = x; s->a = x << 4; }

typedef struct { char pad[4]; int a; char p2[4]; int b; char p3[4]; int c; } S_00164820;
// MATCH func_00164820
void FUN_00164820(S_00164820 *s, int x){ s->b = x; s->c = x; s->a = x << 4; }

typedef struct { char pad[4]; int a, b, c, d, e, f; } S_001647E0;
// MATCH func_001647E0
void FUN_001647e0(S_001647E0 *s, int x, int y){ s->a = x << 4; s->e = x; s->c = x; s->b = y << 4; s->f = y; s->d = y; }

typedef struct { char pad[8]; short adj; short p; void (*fn)(void *, int); } VT_164500_00164500;
typedef struct { char pad[104]; VT_164500_00164500 *vt; } O_164500_00164500;
typedef struct { O_164500_00164500 *o; void *vt; } S_164500_00164500;
extern char D_0043C7D8[];
void func_001645A0(void *); void func_00108B80_00164500(void *) __asm__("func_00108B80");
// MATCH func_00164500
void FUN_00164500(S_164500_00164500 *s, int fl) { O_164500_00164500 *p; s->vt = D_0043C7D8; func_001645A0(s); p = s->o; if (p != 0) p->vt->fn((char *)p + p->vt->adj, 3); if (fl & 1) func_00108B80_00164500(s); }

typedef struct { char pad[16]; short adj; short p; int (*fn)(void *); } VT_00164608;
typedef struct N_00164608 { char pad[92]; struct N_00164608 *next; char pad2[8]; VT_00164608 *vt; } N_00164608;
typedef struct { N_00164608 *head; } S_00164608;
// MATCH func_00164608
void FUN_00164608(S_00164608 *s) { N_00164608 *n = s->head->next; while (n != s->head) { N_00164608 *nx; nx = n->next; n->vt->fn((char *)n + n->vt->adj); n = nx; } }
