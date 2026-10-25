/* Small functions matched by hand. */
// cflags: -fno-gcse
#include "common.h"

extern int D_004A681C_002983B8 __asm__("D_004A681C"); void func_00269FC8(int);
// MATCH func_002983B8
void FUN_002983b8(void) { if (D_004A681C_002983B8 != 0) { D_004A681C_002983B8 = D_004A681C_002983B8 + 1; if (D_004A681C_002983B8 == 2) func_00269FC8(2); if (D_004A681C_002983B8 >= 10) D_004A681C_002983B8 = 0; } }

extern int D_004A681C_00298400 __asm__("D_004A681C"); void func_00269FC8(int);
// MATCH func_00298400
void FUN_00298400(void) { if (D_004A681C_00298400 != 0) { D_004A681C_00298400 = D_004A681C_00298400 + 1; if (D_004A681C_00298400 == 2) func_00269FC8(3); if (D_004A681C_00298400 >= 10) D_004A681C_00298400 = 0; } }

extern int D_004A681C_00298448 __asm__("D_004A681C"); void func_00269FC8(int);
// MATCH func_00298448
void FUN_00298448(void) { if (D_004A681C_00298448 != 0) { D_004A681C_00298448 = D_004A681C_00298448 + 1; if (D_004A681C_00298448 == 2) func_00269FC8(4); if (D_004A681C_00298448 >= 10) D_004A681C_00298448 = 0; } }

extern int D_003FEBA8_00294220[] __asm__("D_003FEBA8");
// MATCH func_00294220
int FUN_00294220(int a) { D_003FEBA8_00294220[1] += a; if (D_003FEBA8_00294220[1] < 0) D_003FEBA8_00294220[1] = 0; if (D_003FEBA8_00294220[1] > 999999) D_003FEBA8_00294220[1] = 999999; return D_003FEBA8_00294220[1]; }

typedef struct { char p[76]; int n; char p2[280]; char *q; } O_001AE438;
// MATCH func_001AE438
void nayuwin2_001ae438(O_001AE438 *o) { int i; for (i = 0; i < o->n; i++) { o->q[i * 256 + 254] = 0; *(int *)(o->q + i * 256 + 40) = -1; } }

typedef struct { int n; void (*fns[64])(int); int args[64]; } S_24ce40_0024CE40;
// MATCH func_0024CE40
void FUN_0024ce40(S_24ce40_0024CE40 *s) { int i; for (i = 0; i < s->n; i++) s->fns[i](s->args[i]); }

typedef struct { char pad[8]; short adj; short p; void (*fn)(void *, int); } VT_1645a0_001645A0;
typedef struct N_1645a0_001645A0 { char pad[92]; struct N_1645a0_001645A0 *next; char pad2[8]; VT_1645a0_001645A0 *vt; } N_1645a0_001645A0;
typedef struct { N_1645a0_001645A0 *head; } S_1645a0_001645A0;
// MATCH func_001645A0
void FUN_001645a0(S_1645a0_001645A0 *s) { N_1645a0_001645A0 *n = s->head->next; while (n != s->head) { N_1645a0_001645A0 *nx; nx = n->next; if (n != 0) n->vt->fn((char *)n + n->vt->adj, 3); n = nx; } }

typedef struct { int a0, a4, a8; } E_0021EAB0;
typedef struct { char pad[7240]; E_0021EAB0 e[32]; int n; } S_0021EAB0;
void func_0021EB20(void *, int, int, int);
// MATCH func_0021EAB0
void batread_0021eab0(S_0021EAB0 *s) { int i; for (i = 0; i < s->n; i++) func_0021EB20(s, s->e[i].a4, s->e[i].a8, s->e[i].a0); }

extern volatile int D_004A1444, D_004A140C; extern char D_00455020[], D_00455030[]; int func_00211A20(void); int func_00211A58(int); int func_001118F8(char *, ...);
// MATCH func_0020C920
void pchevent_0020c920(int on) { int i, n; if (on) { if (D_004A1444 == 0 && (D_004A140C & 8)) { if (func_00211A20() < 10) n = func_00211A20(); else n = 10; i = 0; func_001118F8(D_00455020, func_00211A20()); for (i = 0; i < n; i++) func_001118F8(D_00455030, i, func_00211A58(i)); } } }

typedef struct { char p[208]; float f208; } S_0020C430;
extern S_0020C430 D_0041EFB0; extern float D_004A6F74;
// MATCH func_0020C430
int pchevent_0020c430(void) { float d = (D_004A6F74 - D_0041EFB0.f208) * 0.5f; float q = d * d; if (d < 0) q = -q; D_004A6F74 = D_0041EFB0.f208 + q; if (D_004A6F74 < 0) D_004A6F74 = 0; D_0041EFB0.f208 = D_004A6F74; return 0; }

typedef struct { char p[4832]; int w4832; char p2[316]; char b5152[32]; } O_0021B018;
// MATCH func_0021B018
void FUN_0021b018(O_0021B018 *o) { int i; for (i = 0; i < o->w4832; i++) o->b5152[i] = 1; for (i = o->w4832; i < 32; i++) o->b5152[i] = 0; }

extern char D_0043CD28[]; int func_00165A40(char *, int); void func_001118F8_001686A0(char *, int, int, int) __asm__("func_001118F8");
// MATCH func_001686A0
void pachislot_001686a0(char *o) { int i; for (i = 7; i >= 0; i--) { int a = func_00165A40(o + 44, i); int b = func_00165A40(o + 124, i); int c = func_00165A40(o + 204, i); func_001118F8_001686A0(D_0043CD28, a, b, c); } }
