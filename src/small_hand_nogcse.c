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

typedef struct { char p[360]; int w360, w364; } O_00168B58;
void func_00168AC0(O_00168B58 *);
// MATCH func_00168B58
int pachislot_00168b58(O_00168B58 *o) { if (o->w360 == 1) return 1; while (o->w360 > 0) { o->w360--; o->w364++; } func_00168AC0(o); return 1; }

typedef struct { char p[32]; char b32; } O_00202C30;
extern int D_004A3864; extern char D_00454260[]; int func_00196FF8(void); void func_001118F8_00202C30(char *, int) __asm__("func_001118F8"); void func_00202F88(O_00202C30 *);
// MATCH func_00202C30
int eftpack_00202c30(O_00202C30 *o) { if (o->b32 == 0) { int r = func_00196FF8(); o->b32 = 1 - r; if (D_004A3864 & 0x400) func_001118F8_00202C30(D_00454260, o->b32); if (o->b32 != 0) func_00202F88(o); } return o->b32; }

typedef struct N_0029D3D0 { char p[60]; struct N_0029D3D0 *w60; } N_0029D3D0;
void func_002BF250(N_0029D3D0 *, int);
// MATCH func_0029D3D0
void clas_min_0029d3d0(N_0029D3D0 *o) { if (o->w60 != 0) { N_0029D3D0 *p; do { p = o->w60; o->w60 = p->w60; if (p != 0) func_002BF250(p, 3); } while (o->w60 != 0); } }

typedef struct { int w0, w4; int *w8; } S_0024CF68;
extern char D_0045E028[]; void func_001118F8_0024CF68(char *) __asm__("func_001118F8");
// MATCH func_0024CF68
int FUN_0024cf68(S_0024CF68 *s) { if (s->w4 <= 0) func_001118F8_0024CF68(D_0045E028); s->w4--; return s->w8[s->w4]; }

extern int D_004A7138; extern char D_005F6A40[]; void func_00239568(char *);
// MATCH func_00239660
void FUN_00239660(void) { int i; for (i = 0; i < D_004A7138; i++) func_00239568(D_005F6A40 + i * 64); }

typedef struct { int w0; int w4; int *w8; } O_0024CEE8;
extern char D_0045E018[]; void func_001118F8_0024CEE8(char *) __asm__("func_001118F8");
// MATCH func_0024CEE8
int FUN_0024cee8(O_0024CEE8 *o, int v) { if (o->w4 < 0) func_001118F8_0024CEE8(D_0045E018); if (o->w4 >= o->w0) func_001118F8_0024CEE8(D_0045E018); return o->w8[o->w4++] = v, o->w4 - 1; }

extern int D_00343028[]; extern int D_004A3850, D_004A118C; extern char *D_004A12B0; extern char D_0042D8A0[], D_0042D8C0[]; extern int D_002F95F0[], D_002F96B0[]; void func_001118F8_0010C4C0(char *, ...) __asm__("func_001118F8"); void func_002D4B20(int);
// MATCH func_0010C4C0
void rsound_0010c4c0(int a, unsigned i) { if (!(D_00343028[0] & 8) && D_004A3850 != 2 && i < 48) { if (D_004A118C & 0x40) func_001118F8_0010C4C0(D_0042D8A0, D_004A12B0); if (D_004A118C & 1) func_001118F8_0010C4C0(D_0042D8C0, i); func_002D4B20(i); D_002F95F0[i] = -1; D_002F96B0[i] = -1; } }
