/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_003FEBA8_00294260[] __asm__("D_003FEBA8"); int func_00294220(int);
// MATCH func_00294260
int FUN_00294260(int x) { D_003FEBA8_00294260[1] = 0; func_00294220(x); return D_003FEBA8_00294260[1]; }

extern int D_00314D08_002786A0[] __asm__("D_00314D08"); extern char D_00419D18[];
// MATCH func_002786A0
int FUN_002786a0(int a) { char *b = D_00419D18; int *p = D_00314D08_002786A0; char *q; int i = 0; q = b + 56; do { i++; if (*p == a) return *(int *)q; q += 176; p++; } while (i < 3); return 1; }

extern int D_00314D08_00278600[] __asm__("D_00314D08"); extern int D_004A66D0;
// MATCH func_00278600
int FUN_00278600(int a) { int i = 0; int *p = D_00314D08_00278600; do { if (*p == a) { if (D_004A66D0 == i) return 1; return 0; } i++; p++; } while (i < 3); return -1; }

typedef struct { char p[168]; struct { char p[28]; unsigned w28; } *w168; } R; typedef struct { char p[4800]; R *w4800; char p2[12]; unsigned w4816; char p3[648]; } E_0027C3E0; extern E_0027C3E0 *D_004A1A20_0027C3E0 __asm__("D_004A1A20"); extern int D_004A6634;
// MATCH func_0027C3E0
void FUN_0027c3e0(void) { int i; E_0027C3E0 *e = D_004A1A20_0027C3E0; for (i = 0; i < 4; i++) { if (e->w4816 & 0x60000000) e->w4800->w168->w28 |= 0x100; e = (E_0027C3E0 *)((char *)e + 5472); } D_004A6634 = 1; }

extern float D_00419A70[][8];
// MATCH func_00285908
int FUN_00285908(char a, char b, int c) { return (int)(D_00419A70[(signed char)a][(signed char)b] * (float)c); }

extern float D_00419B70[][8];
// MATCH func_00285948
int FUN_00285948(char a, char b, int c) { return (int)(D_00419B70[(signed char)a][(signed char)b] * (float)c); }

typedef struct { char c[8]; } V8_00294A88;
typedef struct { char p[52]; int w52; int w56; char p2[4]; int w64; int w68; int w72; V8_00294A88 v; } O4_00294A88;
extern V8_00294A88 D_004A6770[3]; extern char D_0041EF08[], D_00499610[], D_00499628[];
int func_002944B8(void *, char *); int func_001644A0(void *); void func_002971C0(int, int); int func_0018B3A8(char *, int); void func_001118F8_00294A88(char *) __asm__("func_001118F8");
// MATCH func_00294A88
O4_00294A88 *FUN_00294a88(O4_00294A88 *o) { func_002944B8(o, D_0041EF08); o->w52 = 0x80808080; o->w56 = 0; func_001644A0((char *)o + 60); o->v = D_004A6770[0]; func_002971C0(0, 0); o->w72 = 0; o->w68 = func_0018B3A8(D_00499610, 0); if (o->w68 == 0) func_001118F8_00294A88(D_00499628); return o; }

extern char D_003E3D20_002785A0[] __asm__("D_003E3D20");
// MATCH func_002785A0
int FUN_002785a0(unsigned idx) { int n, k; char *q; short *p; short v; if (4 < idx) return -1; n = 0; k = 15; q = D_003E3D20_002785A0; q += 10; p = (short *)(q + (idx << 4) * 20); do { v = *p; p += 10; k--; if (v != 0) n++; } while (k >= 0); return n; }
