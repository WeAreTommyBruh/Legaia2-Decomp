/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { char p[76]; int n; char p2[280]; char *q; } O_001AE438;
// MATCH func_001AE438
void nayuwin2_001ae438(O_001AE438 *o) { int i; for (i = 0; i < o->n; i++) { o->q[i * 256 + 254] = 0; *(int *)(o->q + i * 256 + 40) = -1; } }


// MATCH func_001AEA58
void nayuwin2_001aea58(char *o, int idx) { int end, k; char *e, *q; int *r; int m; if (idx < 0) { idx = 0; end = *(int *)(o + 76); } else { end = idx + 1; if (*(int *)(o + 76) < idx) return; } while (idx < end) { e = (char *)(*(int *)(o + 360) + idx * 256); e[253] = 104; idx++; k = 177; do { q = e + 249; } while (0); *(int *)(e + 4) = 0; *(int *)(e + 8) = 0; *(int *)(e + 12) = -1; *(int *)(e + 16) = -1; e[254] = 127; do { *q = 0; k--; q--; } while (k >= 0); m = -1; k = 7; r = (int *)(e + 68); do { k--; *r = m; r--; } while (k >= 0); *(int *)(e + 20) = 0; *(int *)(e + 24) = 0; *(int *)(e + 28) = 0x10101; e[255] = 0; *(int *)e = 0; *(int *)(e + 32) = 0; *(short *)(e + 250) = 0; e[252] = 5; *(int *)(e + 36) = 0; } }


typedef struct N_1af268_001AF268 { char p[12]; struct N_1af268_001AF268 *prev; struct N_1af268_001AF268 *next; } N_1af268_001AF268;
extern N_1af268_001AF268 *D_0036CBB0_a[] __asm__("D_0036CBB0");
extern N_1af268_001AF268 *D_004A382C_1AF268 __asm__("D_004A382C");
// MATCH func_001AF268
void nayuwin2_001af268(N_1af268_001AF268 *a, N_1af268_001AF268 *b, int n) { int i; if (b == 0) b = D_0036CBB0_a[0]; if (n < 0) { n = -n; for (i = 0; i < n; i++) { b = b->prev; if (b == 0) return; } } else { for (i = 0; i < n; i++) { b = b->next; if (b == 0) return; } } if (b == a) return; { N_1af268_001AF268 *nx; if (a->prev == 0) nx = a->next; else { a->prev->next = a->next; nx = a->next; } if (nx) nx->prev = a->prev; if (a->prev == 0) D_004A382C_1AF268 = a->next; } { N_1af268_001AF268 *t = b->next; a->prev = b; a->next = t; } if (b->next) b->next->prev = a; b->next = a; }
