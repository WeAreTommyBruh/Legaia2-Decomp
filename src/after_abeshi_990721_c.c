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

/* the party's shared state, as in after_abeshi.c */
extern struct {
    char unk0[0x18e4];
    s8 order[10]; /* a list of ids, -1 for none */
} D_003FEBA8;

/* a list of up to 24 entries: five parallel arrays after a count */
typedef struct {
    char unk0[2836];
    int n;
    int a[24], b[24], c[24], d[24], e[24];
} List;
extern List *D_004A6578;
extern int D_003FEC3C[]; /* a bit set */
int FUN_00251e88(int);
void FUN_00254ce0(int, int);

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

/* sorts the list by entry a, with 10000/20000/30000 added to some of the
   values to rank them, and sets e from a bit set */
// MATCH func_00269240
void FUN_00269240(void)
{
    int t0[24], t1[24], t2[24], t3[24];
    int i, j, m, idx, v;
    for (i = 0; i < D_004A6578->n; i++) {
        t0[i] = D_004A6578->a[i];
        if (FUN_00251e88(t0[i]) == 0) {
            if (t0[i] >= 1050 && t0[i] < 1250)
                t0[i] += 10000;
            if (t0[i] < 301)
                t0[i] += 20000;
            if (t0[i] >= 301 && t0[i] < 696)
                t0[i] += 30000;
        }
        t1[i] = D_004A6578->b[i];
        t2[i] = D_004A6578->c[i];
        t3[i] = D_004A6578->d[i];
    }
    for (i = 0; i < D_004A6578->n; i++) {
        m = 60000;
        idx = -1;
        for (j = 0; j < D_004A6578->n; j++) {
            if (t0[j] < m) {
                m = t0[j];
                idx = j;
            }
        }
        if (idx >= 0) {
            if (t0[idx] > 30000)
                t0[idx] -= 30000;
            if (t0[idx] > 20000)
                t0[idx] -= 20000;
            if (t0[idx] > 10000)
                t0[idx] -= 10000;
            D_004A6578->a[i] = t0[idx];
            D_004A6578->b[i] = t1[idx];
            D_004A6578->c[i] = t2[idx];
            D_004A6578->d[i] = t3[idx];
            v = t0[idx];
            if (((D_003FEC3C[v / 32] >> (v & 31)) ^ 1) & 1)
                D_004A6578->e[i] = 1;
            else
                D_004A6578->e[i] = 0;
            t0[idx] = 60000;
        }
    }
    for (i = 0; i < D_004A6578->n; i++)
        FUN_00254ce0(D_004A6578->a[i], D_004A6578->d[i]);
}

/* tidies D_003FEBA8.order: drops the entries that are not ids (0-9), then
   the repeated ids, closing the gaps with -1 at the end */
// MATCH func_002650D0
void FUN_002650d0(void)
{
    int i, j, k, n;
    i = 0;
    n = 0;
    while (i < 9 && n < 32) {
        n++;
        if ((u8)D_003FEBA8.order[i] >= 10) {
            for (k = i; k < 9; k++) {
                u8 c = D_003FEBA8.order[k + 1];
                D_003FEBA8.order[k + 1] = -1;
                D_003FEBA8.order[k] = c;
            }
        } else {
            i++;
        }
    }
    for (i = 0; i < 9; i = j) {
        j = i + 1;
        if ((u8)D_003FEBA8.order[i] < 10) {
            for (k = j; k < 10; k++) {
                if (D_003FEBA8.order[i] == D_003FEBA8.order[k]) {
                    n = k;
                    if (n != 9) {
                        if (n < 9) {
                            for (; n < 9; n++) {
                                u8 c = D_003FEBA8.order[n + 1];
                                D_003FEBA8.order[n + 1] = -1;
                                D_003FEBA8.order[n] = c;
                            }
                        }
                    } else {
                        D_003FEBA8.order[9] = -1;
                    }
                    k--;
                }
            }
        }
    }
}
