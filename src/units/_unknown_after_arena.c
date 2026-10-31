/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[1260]; int w; } O_00226B28; typedef struct { char p[124]; float f; char p2[84]; int w; } Q_00226B28; extern float D_004A1508;
// MATCH func_00226B28
void FUN_00226b28(O_00226B28 *o, Q_00226B28 *q) { if (o->w != 0) { q->w = 0; q->f = D_004A1508; } }

// MATCH func_00223500
int FUN_00223500(char *a, int b, unsigned c) { char *e; int x; e = a + b * 8; if (c >= *(unsigned *)(e + 4)) return 0; x = *(short *)(a + 2) * c; a = (char *)*(int *)(e + 8); return (int)a + x; }

int func_00163150(int, int);
int func_00163118(int, int);
// MATCH func_00223620
int FUN_00223620(int p, int idx) { int r; int q; int k; int m; int *e; if (*(int *)(p + 4) < 100) return 0; if (*(int *)(p + 0x4d0) != 0) return 0; e = (int *)(idx * 0x38 + *(int *)(p + 0x810)); r = e[7]; if (r > 0 && (q = *(int *)(p + 0x4c)) != 0 && (m = e[12]) != 0 && (k = func_00163150(q, m)) >= 0) { r = func_00163118(q, k) - 1; } return r; }
