/* Functions of this report unit, matched by hand. */
#include "../common.h"

// MATCH func_00161200
int FUN_00161200(void *a, unsigned char *p) { int r = p[0]; r += p[1] << 8; r += p[2] << 16; r += p[3] << 24; return r; }

int func_00161200(int, unsigned char *);
// MATCH func_00161230
unsigned char *FUN_00161230(int a, unsigned char *p) { int fl = p[3] & 1; p += 8; if (fl) p += func_00161200(a, p) * 4 + 4; return p; }

extern int D_004A2BE0; int func_00160778(char *, char *); char *func_00160C70_00160568(char *, char *, int) __asm__("func_00160C70");
// MATCH func_00160568
int FUN_00160568(char *o, char *k) { int n; int i; n = func_00160778(o, (char *)&D_004A2BE0); if (n > 8) n = 8; for (i = 0; i < n; i++) { char *p = func_00160C70_00160568(o, (char *)&D_004A2BE0, i); if (p[0] == k[0] && p[1] == k[1] && p[2] == k[2]) break; } if (i == n) return 0; return *(int *)(o + (i << 2) + 8); }
