/* Functions of this report unit, matched by hand. */
#include "../common.h"

// MATCH func_00101148
void memo2_00101148(char *o) { int i; char *a = o; char *b = o + 2440; for (i = 0; i < 12; i++) { *(int *)(b - 4) = -2; *(int *)b = 0; *(unsigned short *)(a + 1364) |= 0x80; a += 64; b += 128; } o[1340] = 0; o[4502] = -1; o[4503] = -1; }

extern char D_004A1138[]; extern int D_004A10B0; extern char *D_002F8300[]; int func_002DCE40_00100D50(char *, char *, ...) __asm__("func_002DCE40"); int func_002DD4B0(char *, char *);
// MATCH func_00100D50
int memo2_00100d50(char *o, int idx) { char buf[32]; int i = 0; char *p; func_002DCE40_00100D50(buf, D_004A1138, D_004A10B0, D_002F8300[idx]); p = o + 1376; do { if (func_002DD4B0(p, buf) == 0) return i; i++; p += 64; } while (i < 12); return -1; }

extern char D_0042B138[]; extern char D_0042B150[]; extern char D_0042B118[]; extern char D_0042B0A0[];
int func_0018B508_00100DD8(char *, int *) __asm__("func_0018B508"); int func_002CD428_00100DD8(int, int, char *, int) __asm__("func_002CD428"); int func_002CD598(int);
int func_002CD8D8(int, int, int); int func_002CDAC8(int, int, int); int func_002CDFD8(int, int, int, int);
void func_00133528(int, void *, int);
// MATCH func_00100DD8
void memo2_00100dd8(char *o) { int i; int r; int t; int buf[4]; i = 0; r = func_0018B508_00100DD8(D_0042B138, buf); buf[0] = 0x13166; do { t = func_002CDFD8(i, 0, *(int *)(o + 4), 0); if (t == 0) { func_002CDAC8(0, 0, (int)(o + 0x508)); func_002CD428_00100DD8(i, 0, D_0042B150, 0x203); func_002CDAC8(0, 0, (int)(o + 0x530)); func_002CD8D8(*(int *)(o + 0x530), (int)(o + 0xc0), 0x3c4); func_002CDAC8(0, 0, 0); func_002CD598(*(int *)(o + 0x530)); func_002CDAC8(0, 0, 0); func_002CD428_00100DD8(i, 0, D_0042B118, 0x203); func_002CDAC8(0, 0, 0); func_002CD8D8(*(int *)(o + 0x530), r, buf[0]); func_002CDAC8(0, 0, 0); func_002CD598(*(int *)(o + 0x530)); func_002CDAC8(0, 0, 0); } i++; } while (i < 2); func_00133528(r, D_0042B0A0, 0xf3); }
