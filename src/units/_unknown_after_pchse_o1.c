/* Functions of this report unit, matched by hand. */
// cflags: -O1
#include "../common.h"

typedef struct N__00212C18 { struct N__00212C18 *next; int w4, w8, w12; struct N__00212C18 *w16; } N__00212C18;
typedef struct { int w0; int w4; N__00212C18 *w8; } O__00212C18;
void func_0010E820(int, int);
// MATCH func_00212C18
int FUN_00212c18(O__00212C18 *o, int n, int m)
{
    N__00212C18 *p, *q;
    int i;
    p = o->w8;
    i = 0;
    if (p == 0) return 0;
    if (n != 0) {
        do {
            p = p->next;
            if (p == 0) break;
            i++;
        } while (i != n);
    }
    if (p == 0) return 0;
    q = p->w16;
    i = 0;
    if (q == 0) return 0;
    if (m != 0) {
        do {
            q = q->next;
            if (q == 0) break;
            i++;
        } while (i != m);
    }
    if (q == 0) return 0;
    func_0010E820(o->w0, 103);
    return 1;
}
