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

// cflags: -fno-gcse
extern char D_004A2BD8_160DF8[2] __asm__("D_004A2BD8"); extern char D_004A2BE8_160DF8[3] __asm__("D_004A2BE8"); char *func_00161230_160DF8(char *, char *) __asm__("func_00161230"); int func_00161200_160DF8(char *, char *) __asm__("func_00161200");
// MATCH func_00160DF8
int FUN_00160df8(char *o, char *k) { int bad; char *r; char *q; if (*(char **)o == 0 || (*(char **)o)[0] != D_004A2BD8_160DF8[0] || (*(char **)o)[1] != D_004A2BD8_160DF8[1]) bad = 1; else bad = 0; if (bad) r = 0; else { for (q = *(char **)o + 8; !(q[0] == D_004A2BE8_160DF8[0] && q[1] == D_004A2BE8_160DF8[1] && q[2] == D_004A2BE8_160DF8[2]); q = func_00161230_160DF8(o, q)) { if (q[0] == k[0] && q[1] == k[1] && q[2] == k[2]) { r = q; goto done; } } r = 0; } done: if (r == 0) return 0; { char *p = r + 8; if (((unsigned char *)r)[3] & 1) { register char *a0 __asm__("$4") = o; __asm__ volatile ("" : "+r"(a0)); p += (func_00161200_160DF8(a0, p) << 2) + 4; } return p - r; } }
