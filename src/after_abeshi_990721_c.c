/* More of _unknown_after_abeshi built like after_abeshi_990721.c. Matched
   by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "common.h"

/* a 176-byte record of D_00419D18 (20 of them: 4 party members, then enemies) */
typedef struct {
    char unk0[0x5c];
    int x5c, x60;
    char unk64[0x80 - 0x64];
    u32 flags;
    char unk84[0xb0 - 0x84];
} Unit;
extern Unit D_00419D18[20];
extern int D_00314D08[4];
extern int D_00314CC8[];
extern int D_004A66DC, D_004A6594, D_004A5A50;
int rand(void);

/* sets D_004A66DC (and returns it) from the party's and the enemies'
   x5c/x60 sums and a few flags */
// MATCH func_0026AC80
int FUN_0026ac80(void)
{
    int c[4];
    int p[2], q[2];
    int n1, n2, i, k;
    Unit *e;
    n1 = n2 = 0;
    D_004A66DC = 0;
    q[1] = 0;
    q[0] = 0;
    p[1] = 0;
    p[0] = 0;
    c[3] = 0;
    c[2] = 0;
    c[1] = 0;
    c[0] = 0;
    for (i = 0; i < 20; i++) {
        e = D_00419D18 + i;
        k = 0;
        if (i < 4) {
            if (D_00314D08[i] >= 0) {
                k = 1;
                n1++;
                if (e->flags & 0x2000000) c[0]++;
                if (e->flags & 0x4000000) c[1]++;
                if (e->flags & 0x10000000) c[2]++;
            }
        } else if (i < 10) {
            if (D_00314CC8[i - 4] >= 0) {
                k = 2;
                n2++;
                if (e->flags & 0x8000000) c[3]++;
            }
        }
        if (k) {
            p[k - 1] += e->x5c;
            q[k - 1] += e->x60;
        }
    }
    if (c[3] != 0)
        goto yes;
    if (c[1] != 0)
        goto no;
    if (D_004A6594 == 1 && D_004A5A50 == 0)
        goto no;
    p[0] = p[0] * 8 / n1;
    p[1] = p[1] * 8 / n2;
    q[0] = q[0] * 2 / n1;
    q[1] = q[1] * 2 / n2;
    if (c[0] != 0) {
        p[0] += p[0] * 3 / 5;
        q[0] += q[0] * 3 / 5;
    }
    if (rand() % (p[0] + q[0]) < rand() % (p[1] + q[1]))
        goto yes;
no:
    D_004A66DC = 0;
    return 0;
yes:
    D_004A66DC = 1;
    return 1;
}
