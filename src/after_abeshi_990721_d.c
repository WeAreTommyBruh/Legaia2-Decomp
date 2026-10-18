/* More of _unknown_after_abeshi built like after_abeshi_990721.c: these
   work on the battle units' hit points (the same mode/amount arguments as
   in FUN_002656b0 for magic points). Matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "common.h"

/* a 176-byte record of D_00419D18: the 4 party members, 6 enemies, ... */
typedef struct {
    char p0[4];
    int mx;  /* hit points, maximum */
    char p8[56 - 8];
    int cur; /* hit points, current */
    char p3c[163 - 60];
    u8 t;    /* multiplier for FUN_00265230's mode 1 */
    char pa4[176 - 164];
} Unit;
/* a 472-byte record of D_003FEBA8 and D_003FE270 */
typedef struct {
    char pad[168];
    float f;
    char pad2[472 - 172];
} Part;
/* a 72-byte record of D_003FDFA0 */
typedef struct {
    char pad[32];
    u16 mx, cur;
    char pad2[72 - 36];
} Slot;
typedef struct {
    char pad[4816];
    int flags;
    char pad2[5472 - 4820];
} Chr;
extern int D_004A12A4, D_004A5ADC, D_004A66CC;
extern Chr *D_004A1A20;
extern int D_00314D08[4], D_00314CC8[];
extern Unit D_00419D18[10];
extern struct {
    char pad[0x18f0];
    Part rec[5];
} D_003FEBA8;
extern Part D_003FE270[];
extern Slot D_003FDFA0[];

/* Adds c to the hit points of unit a (mode 1; times the record's t in
   battle) or c percent of its maximum (mode 0); in a battle (D_004A12A4
   is 11) it looks the unit up among those flagged 0x40000000 instead. */
// MATCH func_00265230
void FUN_00265230(int a, int mode, int c)
{
    int i, cnt, v;
    Part *q, *e, *e0;
    Slot *s, *s0;
    switch (mode) {
    case 1:
        if (D_004A12A4 == 11 && D_004A5ADC == 0) {
            cnt = 0;
            v = D_004A66CC;
            for (i = 0; i < 10; i++) {
                if (D_004A1A20[i].flags & 0x40000000) {
                    if (i < 4) {
                        if (D_00314D08[i] == a)
                            cnt++;
                    } else {
                        if (D_00314CC8[i - 4] == a)
                            cnt++;
                    }
                    if (v == 10)
                        cnt = 0;
                    if (cnt) {
                        D_00419D18[i].cur += c * D_00419D18[i].t;
                        if (D_00419D18[i].mx < D_00419D18[i].cur)
                            D_00419D18[i].cur = D_00419D18[i].mx;
                        if (D_00419D18[i].cur <= 0)
                            D_00419D18[i].cur = 1;
                        if (D_004A1A20[i].flags & 1)
                            D_004A1A20[i].flags &= ~1;
                        return;
                    }
                }
            }
        } else if ((u32)a < 10) {
            if (a < 5) {
                q = &D_003FEBA8.rec[a];
            } else {
                e = D_003FE270;
                e -= 5;
                q = e + a;
            }
            s = &D_003FDFA0[a];
            q->f += (float)c;
            if ((float)s->mx < q->f)
                q->f = s->mx;
            if (q->f <= 0)
                q->f = 1;
            if (c >= 0) {
                s->cur += c;
                if (s->mx < s->cur)
                    s->cur = s->mx;
            } else if (-c < s->cur) {
                s->cur += c;
            } else {
                s->cur = 1;
            }
        }
        break;
    case 0:
        if (D_004A12A4 == 11 && D_004A5ADC == 0) {
            cnt = 0;
            for (i = 0; i < 10; i++) {
                if (D_004A1A20[i].flags & 0x40000000) {
                    if (i < 4) {
                        if (D_00314D08[i] == a)
                            cnt++;
                    } else {
                        if (D_00314CC8[i - 4] == a)
                            cnt++;
                    }
                    if (D_004A66CC == 10)
                        cnt = 0;
                    if (cnt) {
                        D_00419D18[i].cur += D_00419D18[i].mx * c / 100 * D_00419D18[i].t;
                        if (D_00419D18[i].mx < D_00419D18[i].cur)
                            D_00419D18[i].cur = D_00419D18[i].mx;
                        if (D_00419D18[i].cur <= 0)
                            D_00419D18[i].cur = 1;
                        if (D_004A1A20[i].flags & 1)
                            D_004A1A20[i].flags &= ~1;
                        return;
                    }
                }
            }
        } else if ((u32)a < 10) {
            if (a < 5) {
                q = &D_003FEBA8.rec[a];
            } else {
                e0 = D_003FE270;
                e0 -= 5;
                q = e0 + a;
            }
            s0 = &D_003FDFA0[a];
            q->f += (float)(s0->mx * c / 100);
            if ((float)s0->mx < q->f)
                q->f = s0->mx;
            if (q->f <= 0)
                q->f = 1;
            if (c >= 0) {
                s0->cur += s0->mx * c / 100;
                if (s0->mx < s0->cur)
                    s0->cur = s0->mx;
            } else if (s0->cur > s0->mx * -c / 100) {
                s0->cur += s0->mx * c / 100;
            } else {
                s0->cur = 1;
            }
        }
        break;
    }
}
