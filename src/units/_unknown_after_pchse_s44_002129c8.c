#include "../common.h"
typedef struct N_2129C8 { struct N_2129C8 *next; int w4, w8, w12; struct N_2129C8 *w16; } N_2129C8;
typedef struct { int w0; int w4; N_2129C8 *w8; } O_2129C8;
// MATCH func_002129C8
int FUN_002129c8(O_2129C8 *o, int *pa, int *pb, int n, int m) {
    N_2129C8 *p, *q;
    int i;
    p = o->w8;
    i = 0;
    if (p != 0 && n != 0) { do { p = p->next; if (p == 0) break; i++; } while (i != n); }
    if (p == 0) return 0;
    q = p->w16;
    i = 0;
    if (q != 0 && m != 0) { do { q = q->next; if (q == 0) break; i++; } while (i != m); }
    if (q == 0) return 0;
    *pa = (int)((char *)q + 20); *pb = (int)((char *)q + 84);
    return 1;
}
