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

extern int D_004A2BE0_160490 __asm__("D_004A2BE0");
typedef struct { unsigned char *s; unsigned len; int tab[8]; } O_00160490;
int func_00160778_160490(O_00160490 *, char *) __asm__("func_00160778"); char *func_00160C70_160490(O_00160490 *, char *, int) __asm__("func_00160C70");
// MATCH func_00160490
void FUN_00160490(O_00160490 *o, unsigned char *s) { int n; int i; int total; char *p; int *t; unsigned char *q; unsigned v; o->s = s; q = s + 4; v = s[4]; v += q[1] << 8; v += q[2] << 16; v += q[3] << 24; o->len = v; n = func_00160778_160490(o, (char *)&D_004A2BE0_160490); n = n < 9 ? n : 8; if (n != 0) { total = 0; for (i = 0; i < n; i++) { *(int *)((char *)o + i * 4 + 8) = total; p = func_00160C70_160490(o, (char *)&D_004A2BE0_160490, i); if (p != 0) total += func_00160778_160490(o, p); } } }

