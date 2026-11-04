/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern char D_004A2BD8[2]; extern char D_004A2BE8[3]; char *func_00161230(char *, char *);
// MATCH func_00160620
int FUN_00160620(char *o, char *k) { char *r; char *q; int bad; if (*(char **)o == 0 || (*(char **)o)[0] != D_004A2BD8[0] || (*(char **)o)[1] != D_004A2BD8[1]) bad = 1; else bad = 0; if (bad) r = 0; else { for (q = *(char **)o + 8; !(q[0] == D_004A2BE8[0] && q[1] == D_004A2BE8[1] && q[2] == D_004A2BE8[2]); q = func_00161230(o, q)) { if (q[0] == k[0] && q[1] == k[1] && q[2] == k[2]) { r = q; goto done; } } r = 0; } done: if (r == 0) return 0; return r[3]; }

extern char D_004A2BD8_001610F8[2] __asm__("D_004A2BD8"); extern char D_004A2BE8_001610F8[3] __asm__("D_004A2BE8"); char *func_00161230(char *, char *); int func_00161200(char *, char *);
// MATCH func_001610F8
char *FUN_001610f8(char *o, char *k) { int bad; char *r; char *q; if (*(char **)o == 0 || (*(char **)o)[0] != D_004A2BD8_001610F8[0] || (*(char **)o)[1] != D_004A2BD8_001610F8[1]) bad = 1; else bad = 0; if (bad) r = 0; else { for (q = *(char **)o + 8; !(q[0] == D_004A2BE8_001610F8[0] && q[1] == D_004A2BE8_001610F8[1] && q[2] == D_004A2BE8_001610F8[2]); q = func_00161230(o, q)) { if (q[0] == k[0] && q[1] == k[1] && q[2] == k[2]) { r = q; goto done; } } r = 0; } done: if (r == 0) return 0; if ((((unsigned char *)r)[3] ^ 1) & 1) return 0; return r + 12; }
extern char D_004A2BD8_1608A8[2] __asm__("D_004A2BD8"); extern char D_004A2BE8_1608A8[3] __asm__("D_004A2BE8"); char *func_00161230_1608A8(char *, char *) __asm__("func_00161230"); int func_00161200_1608A8(char *, char *) __asm__("func_00161200");
// MATCH func_001608A8
int FUN_001608a8(char *o, char *k) { int bad; char *r; char *q; if (*(char **)o == 0 || (*(char **)o)[0] != D_004A2BD8_1608A8[0] || (*(char **)o)[1] != D_004A2BD8_1608A8[1]) bad = 1; else bad = 0; if (bad) r = 0; else { for (q = *(char **)o + 8; !(q[0] == D_004A2BE8_1608A8[0] && q[1] == D_004A2BE8_1608A8[1] && q[2] == D_004A2BE8_1608A8[2]); q = func_00161230_1608A8(o, q)) { if (q[0] == k[0] && q[1] == k[1] && q[2] == k[2]) { r = q; goto done; } } r = 0; } done: if (r == 0) return 0; { unsigned char *p = (unsigned char *)r + 4; return p[0] + (p[1] << 8) + (p[2] << 16) + ((unsigned)p[3] << 24); } }

static inline unsigned rd32_00160B48(unsigned char *p) { return p[0] + (p[1] << 8) + (p[2] << 16) + (p[3] << 24); }
extern char D_004A2BD8_160B48[2] __asm__("D_004A2BD8"); extern char D_004A2BE8_160B48[3] __asm__("D_004A2BE8"); char *func_00161230_160B48(char *, char *) __asm__("func_00161230"); int func_00161200_160B48(char *, char *) __asm__("func_00161200");
// MATCH func_00160B48
int FUN_00160b48(char *o, char *k) { int bad; char *r; char *q; if (*(char **)o == 0 || (*(char **)o)[0] != D_004A2BD8_160B48[0] || (*(char **)o)[1] != D_004A2BD8_160B48[1]) bad = 1; else bad = 0; if (bad) r = 0; else { for (q = *(char **)o + 8; !(q[0] == D_004A2BE8_160B48[0] && q[1] == D_004A2BE8_160B48[1] && q[2] == D_004A2BE8_160B48[2]); q = func_00161230_160B48(o, q)) { if (q[0] == k[0] && q[1] == k[1] && q[2] == k[2]) { r = q; goto done; } } r = 0; } done: if (r == 0) return 0; { unsigned char *p = (unsigned char *)r + 4; int b = *(int *)o; return b + (p[0] + (p[1] << 8) + (p[2] << 16) + ((unsigned)p[3] << 24)); } }

static inline unsigned rd32_001609C8(unsigned char *p) { return p[0] + (p[1] << 8) + (p[2] << 16) + ((unsigned)p[3] << 24); }
extern char D_004A2BD8_1609C8[2] __asm__("D_004A2BD8"); extern char D_004A2BE8_1609C8[3] __asm__("D_004A2BE8"); char *func_00161230_1609C8(char *, char *) __asm__("func_00161230"); int func_00161200_1609C8(char *, char *) __asm__("func_00161200");
// MATCH func_001609C8
int FUN_001609c8(char *o, char *k, int n) { int bad; char *r; char *q; if (*(char **)o == 0 || (*(char **)o)[0] != D_004A2BD8_1609C8[0] || (*(char **)o)[1] != D_004A2BD8_1609C8[1]) bad = 1; else bad = 0; if (bad) r = 0; else { for (q = *(char **)o + 8; !(q[0] == D_004A2BE8_1609C8[0] && q[1] == D_004A2BE8_1609C8[1] && q[2] == D_004A2BE8_1609C8[2]); q = func_00161230_1609C8(o, q)) { if (q[0] == k[0] && q[1] == k[1] && q[2] == k[2]) { r = q; goto done; } } r = 0; } done: if (r == 0) return 0; if ((((unsigned char *)r)[3] ^ 1) & 1) return 0; { int cnt = rd32_001609C8((unsigned char *)r + 8); if (n >= cnt) return 0; return rd32_001609C8((unsigned char *)r + n * 4 + 12); } }

static inline unsigned rd32_00160C70(unsigned char *p) { return p[0] + (p[1] << 8) + (p[2] << 16) + ((unsigned)p[3] << 24); }
extern char D_004A2BD8_160C70[2] __asm__("D_004A2BD8"); extern char D_004A2BE8_160C70[3] __asm__("D_004A2BE8"); char *func_00161230_160C70(char *, char *) __asm__("func_00161230"); int func_00161200_160C70(char *, char *) __asm__("func_00161200");
// MATCH func_00160C70
int FUN_00160c70(char *o, char *k, int n) { int bad; char *r; char *q; if (*(char **)o == 0 || (*(char **)o)[0] != D_004A2BD8_160C70[0] || (*(char **)o)[1] != D_004A2BD8_160C70[1]) bad = 1; else bad = 0; if (bad) r = 0; else { for (q = *(char **)o + 8; !(q[0] == D_004A2BE8_160C70[0] && q[1] == D_004A2BE8_160C70[1] && q[2] == D_004A2BE8_160C70[2]); q = func_00161230_160C70(o, q)) { if (q[0] == k[0] && q[1] == k[1] && q[2] == k[2]) { r = q; goto done; } } r = 0; } done: if (r == 0) return 0; if ((((unsigned char *)r)[3] ^ 1) & 1) return 0; { int cnt = rd32_00160C70((unsigned char *)r + 8); if (n >= cnt) return 0; return *(int *)o + rd32_00160C70((unsigned char *)r + n * 4 + 12); } }

