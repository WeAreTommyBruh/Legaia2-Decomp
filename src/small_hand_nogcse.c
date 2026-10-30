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

extern int D_00343028_0010D570[] __asm__("D_00343028"); extern int D_004A3850_0010D570 __asm__("D_004A3850"), D_004A118C_0010D570 __asm__("D_004A118C"); extern char *D_004A12B0_0010D570 __asm__("D_004A12B0"); extern char D_0042DF10[], D_0042DF28[]; void func_001118F8_0010D570(char *, ...) __asm__("func_001118F8"); int func_002D3B28(int, int, int); int func_002D3DF0(int, int);
// MATCH func_0010D570
int FUN_0010d570(int a, int b, int c, int d, int e, int *p9, int *p10) { int r; if ((D_00343028_0010D570[0] & 8) || D_004A3850_0010D570 == 2) return 0; if (D_004A118C_0010D570 & 1) func_001118F8_0010D570(D_0042DF10, b, c, d, e); if (D_004A118C_0010D570 & 0x40) func_001118F8_0010D570(D_0042DF28, D_004A12B0_0010D570); r = func_002D3B28(b, c, e); *p9 = r; *p10 = func_002D3DF0(r, d); return 1; }

typedef struct { char p[40]; short h40, h42; char q[4]; } E_0015DE00;
typedef struct { char p[28]; E_0015DE00 *w28; int w32; } O_0015DE00;
int func_0015DAC8(E_0015DE00 *, int);
// MATCH func_0015DE00
E_0015DE00 *FUN_0015de00(O_0015DE00 *o, int k, int x) { int i; E_0015DE00 *e = o->w28; for (i = 0; i < o->w32; i++, e++) { if (e->h40 == k && func_0015DAC8(e, x) != 0) return e; } return 0; }

typedef struct { char p[16]; char q[24]; short h40, h42; char r[4]; } E_0015DBA8;
typedef struct { char p[28]; E_0015DBA8 *w28; int w32; } O_0015DBA8;
int func_0015DAC8_0015DBA8(E_0015DBA8 *, int) __asm__("func_0015DAC8");
// MATCH func_0015DBA8
char *FUN_0015dba8(O_0015DBA8 *o, int k, int x) { int i; int best = -1; char *res = 0; E_0015DBA8 *e = o->w28; for (i = 0; i < o->w32; i++, e++) { if (e->h40 == k && func_0015DAC8_0015DBA8(e, x) != 0 && e->h42 >= best) { best = e->h42; res = e->p + 16; } } return res; }

// MATCH func_0023C728
int FUN_0023c728(char *d, char *s) { while (*d++); d--; while (*s) *d++ = *s++; *d = 0; return 1; }

int func_001659A8(void *);
// MATCH func_00165A40
int pachislot_00165a40(int *o, int k) { int i; int *t; if (func_001659A8(o)) return 0; i = o[18] + k; t = (int *)o[0]; if (i < 0) i += t[5]; if (i >= t[5]) i -= t[5]; return ((char *)o[1])[i]; }

int func_002DD36C(void *, void *);
// MATCH func_002469A0
int work_002469a0(char *o, char *key) { int n, i; if (*(int *)(o + 152) == 0) return -1; if (key == 0) return -1; n = **(int **)(o + 152); for (i = 0; i < n; i++) { char *t = *(char **)(o + 152); if (func_002DD36C(key, t + ((int *)t)[i + 1] + 8) == 0) return i; } return -1; }

extern char *D_004A1A20; extern char D_00431C68[]; void func_001118F8_0012D248(char *, ...) __asm__("func_001118F8");
// MATCH func_0012D248
void FUN_0012d248(void) { int i, off = 0; for (i = 0; i < 20; i++) { char *e = (char *)(off + (int)D_004A1A20); int *p, *q; off += 5472; p = *(int **)(e + 5424); if (p) { *(int *)(e + 5364) = p[17]; func_001118F8_0012D248(D_00431C68, i, p[17]); } else { q = *(int **)(e + 5380); if (q) *(int *)(e + 5364) = q[17]; } } }

void func_00164A38(void *, int);
// MATCH func_00294560
void FUN_00294560(int *o, int a) { int i; a++; i = ((short *)o)[5] + a; if (i < 0) i += ((int *)o[0])[5]; if (i >= ((int *)o[0])[5]) i -= ((int *)o[0])[5]; func_00164A38(o, i); }

extern char D_0043E188[]; void func_002971C0(int, int); void func_001621F8(int, char *, int); void func_00164500(char *, int); void func_001775C0(char *, int); void func_00108B80(char *);
// MATCH func_00177B00
void shuffle_00177b00(char *o, int flag) { char *p; func_002971C0(18, 50); func_001621F8(*(int *)(o + 464), D_0043E188, 219); func_00164500(o + 456, 2); if (o != 0) { p = o + 384; if (o != p) { do { p -= 96; func_001775C0(p, 0); } while (o != p); } } if (flag & 1) func_00108B80(o); }

extern int D_00343028_0010E368[] __asm__("D_00343028"); extern int D_004A3850_0010E368 __asm__("D_004A3850"), D_004A118C_0010E368 __asm__("D_004A118C"), D_004A12B0_0010E368 __asm__("D_004A12B0"), D_004A11DC, D_004A1188, D_004A11D4; extern int D_002F9598[]; extern char D_0042E490[], D_0042E4B0[]; void func_001118F8_0010E368(char *, ...) __asm__("func_001118F8"); void func_0010E2C0(int *, int); void func_002D5280(int);
// MATCH func_0010E368
void FUN_0010e368(int *o) { if (!(D_00343028_0010E368[0] & 8) && D_004A3850_0010E368 != 2) { if (D_004A118C_0010E368 & 1) func_001118F8_0010E368(D_0042E490, D_004A12B0_0010E368); if (D_004A118C_0010E368 & 0x40) func_001118F8_0010E368(D_0042E4B0, D_004A12B0_0010E368); func_0010E2C0(o, 0); func_002D5280(3); o[342] = 0; o[341] = 0; D_002F9598[0] = 0; D_002F9598[1] = 0; D_004A11DC = 0; D_004A1188 = 0; D_004A11D4 = 0;
o[337] = 0;
o[338] = 0;
o[336] = 0;
o[332] = 0; } }

extern int D_00343028_0010E1A0[] __asm__("D_00343028"); extern int D_004A3850_0010E1A0 __asm__("D_004A3850"), D_004A118C_0010E1A0 __asm__("D_004A118C"), D_004A11DC_0010E1A0 __asm__("D_004A11DC"); extern char *D_004A12B0_0010E1A0 __asm__("D_004A12B0"); extern int D_002F9598_0010E1A0[] __asm__("D_002F9598"); extern char D_0042E420[]; void func_001118F8_0010E1A0(char *, ...) __asm__("func_001118F8");
// MATCH func_0010E1A0
int FUN_0010e1a0(int *o, int x) { if ((D_00343028_0010E1A0[0] & 8) || D_004A3850_0010E1A0 == 2) return 0; if (D_002F9598_0010E1A0[0] == 0) return 0; if (o[332] != 0) return 0; if (D_004A118C_0010E1A0 & 1) func_001118F8_0010E1A0(D_0042E420, x, D_004A12B0_0010E1A0); if (D_00343028_0010E1A0[0] & 1) { D_004A11DC_0010E1A0 = 0; o[332] = 2; } return 1; }

extern char D_00454CB8[]; void func_0020B4B8(char *, int); void func_00131588(char *); void func_00108B80(char *);
// MATCH func_00205600
void pchjob0_00205600(char *o, int flag) { char *a; char *p; *(int *)(o + 32) = (int)D_00454CB8; a = *(char **)(o + 28); if (a != 0) { p = a + (((int *)a)[-4] << 3); if (a != p) { do { p -= 8; func_0020B4B8(p, 0); } while (*(char **)(o + 28) != p); } func_00131588(*(char **)(o + 28) - 16); } if (flag & 1) func_00108B80(o); }

int func_0015C398(int, void *, float);
// MATCH func_0015C7F0
int FUN_0015c7f0(int *o, float *q, float r, float s) { float v[4]; int i; int *p; v[0] = q[0]; v[1] = q[1] - s; v[2] = q[2]; v[3] = q[3]; if (func_0015C398(o[0], v, r)) return 1; p = (int *)o[3]; for (i = 0; i < o[4]; i++, p++) { char *e = (char *)*p; if (*(short *)(e + 284) != 0 && *(short *)(e + 286) != 0) if (func_0015C398((int)e, v, r)) return 1; } return 0; }

extern char D_004A2BD8[2]; extern char D_004A2BE8[3]; char *func_00161230(char *, char *);
// MATCH func_00160620
int FUN_00160620(char *o, char *k) { char *r; char *q; int bad; if (*(char **)o == 0 || (*(char **)o)[0] != D_004A2BD8[0] || (*(char **)o)[1] != D_004A2BD8[1]) bad = 1; else bad = 0; if (bad) r = 0; else { for (q = *(char **)o + 8; !(q[0] == D_004A2BE8[0] && q[1] == D_004A2BE8[1] && q[2] == D_004A2BE8[2]); q = func_00161230(o, q)) { if (q[0] == k[0] && q[1] == k[1] && q[2] == k[2]) { r = q; goto done; } } r = 0; } done: if (r == 0) return 0; return r[3]; }

extern char D_004A2BD8_001610F8[2] __asm__("D_004A2BD8"); extern char D_004A2BE8_001610F8[3] __asm__("D_004A2BE8"); char *func_00161230(char *, char *); int func_00161200(char *, char *);
// MATCH func_001610F8
char *FUN_001610f8(char *o, char *k) { int bad; char *r; char *q; if (*(char **)o == 0 || (*(char **)o)[0] != D_004A2BD8_001610F8[0] || (*(char **)o)[1] != D_004A2BD8_001610F8[1]) bad = 1; else bad = 0; if (bad) r = 0; else { for (q = *(char **)o + 8; !(q[0] == D_004A2BE8_001610F8[0] && q[1] == D_004A2BE8_001610F8[1] && q[2] == D_004A2BE8_001610F8[2]); q = func_00161230(o, q)) { if (q[0] == k[0] && q[1] == k[1] && q[2] == k[2]) { r = q; goto done; } } r = 0; } done: if (r == 0) return 0; if ((((unsigned char *)r)[3] ^ 1) & 1) return 0; return r + 12; }

typedef struct { char c[8]; } V8_00173008;
extern V8_00173008 D_004A3170[3];
typedef struct { char p[32]; short adj32; short pad32; void (*fn36)(void *); char p2[16]; short adj56; short pad56; void (*fn60)(void *, int); } VT_173008_00173008;
typedef struct { char p[200]; float f200; } T2_173008_00173008;
typedef struct { char p0[88]; int w88; int w92; char p1[4]; float f100; float f104; int w108; T2_173008_00173008 *w112; char p2[8]; int w124; char p3[188]; V8_00173008 v316; char p4[8]; VT_173008_00173008 *vt; } O_173008_00173008;
void func_00172C00(void *, int); void func_00172E40(void *); void func_00172BE8(void *, int);
// MATCH func_00173008
int FUN_00173008(O_173008_00173008 *o) { o->vt->fn60((char *)o + o->vt->adj56, 1); func_00172C00(o, 4); o->w88 = 2; o->vt->fn36((char *)o + o->vt->adj32); o->w108 = 0; if (o->w92 == 0) { o->w112->f200 = 1.0f; if (o->w124 != 0) { func_00172E40(o); return 0; } } if (o->w92 > 0) { o->vt->fn60((char *)o + o->vt->adj56, 3); func_00172BE8(o, 516); o->f100 = o->f104; o->w112->f200 = o->f104; o->v316 = D_004A3170[0]; } return 0; }

typedef struct { char c[8]; } V8_001730F8;
extern V8_001730F8 D_004A3178[3];
typedef struct { char p[32]; short adj32; short pad32; void (*fn36)(void *); char p2[16]; short adj56; short pad56; void (*fn60)(void *, int); } VT_1730f8_001730F8;
typedef struct { char p[200]; float f200; } T2_1730f8_001730F8;
typedef struct { char p0[88]; int w88; int w92; char p1[4]; float f100; float f104; int w108; T2_1730f8_001730F8 *w112; char p2[8]; int w124; char p3[188]; V8_001730F8 v316; char p4[8]; VT_1730f8_001730F8 *vt; } O_1730f8_001730F8;
void func_00172C00(void *, int); void func_00172E40(void *); void func_00172BE8(void *, int);
// MATCH func_001730F8
int FUN_001730f8(O_1730f8_001730F8 *o) { o->vt->fn60((char *)o + o->vt->adj56, 1); func_00172C00(o, 4); o->w88 = 1; o->vt->fn36((char *)o + o->vt->adj32); o->w108 = 0; if (o->w92 == 0) { o->w112->f200 = 1.0f; if (o->w124 != 0) { func_00172E40(o); return 0; } } if (o->w92 > 0) { o->vt->fn60((char *)o + o->vt->adj56, 2); func_00172BE8(o, 516); o->f100 = o->f104; o->w112->f200 = o->f104; o->v316 = D_004A3178[0]; } return 0; }

typedef struct { char c[8]; } V8_00172EB8;
extern V8_00172EB8 D_004A3160[3]; extern V8_00172EB8 D_004A3168[3];
typedef struct { char p[32]; short adj32; short pad32; void (*fn36)(void *); char p2[16]; short adj56; short pad56; void (*fn60)(void *, int); } VT_172eb8_00172EB8;
typedef struct { char p[200]; float f200; } T2_172eb8_00172EB8;
typedef struct { char p0[88]; int w88; int w92; char p1[4]; float f100; float f104; int w108; T2_172eb8_00172EB8 *w112; char p2[8]; int w124; char p3[188]; V8_00172EB8 v316; char p4[8]; VT_172eb8_00172EB8 *vt; } O_172eb8_00172EB8;
void func_00172C00(void *, int); void func_00172E40(void *); void func_00172BE8(void *, int);
// MATCH func_00172EB8
int FUN_00172eb8(O_172eb8_00172EB8 *o) { o->vt->fn60((char *)o + o->vt->adj56, 1); func_00172C00(o, 4); o->vt->fn36((char *)o + o->vt->adj32); o->w108 = 0; if (o->w92 == 0) { o->w112->f200 = 1.0f; if (o->w124 != 0) { func_00172E40(o); return 0; } } if (o->w92 > 0) { if (o->w88 == 1) { o->vt->fn60((char *)o + o->vt->adj56, 2); func_00172BE8(o, 516); o->f100 = o->f104; o->w112->f200 = o->f104; o->v316 = D_004A3160[0]; } else if (o->w88 == 2) { o->vt->fn60((char *)o + o->vt->adj56, 3); func_00172BE8(o, 516); o->f100 = o->f104; o->w112->f200 = o->f104; o->v316 = D_004A3168[0]; } } return 0; }

typedef struct { char p[56]; short adj56; short pad56; void (*fn60)(void *); char p2[16]; short adj80; short pad80; void (*fn84)(void *, int); } VT_1659b0_001659B0;
typedef struct { char p[20]; int w20; } B_1659b0_001659B0;
typedef struct { B_1659b0_001659B0 *base; char p0[6]; short h10; char p1[36]; VT_1659b0_001659B0 *vt; char p2[12]; int w64; char p3[4]; int w72; } O_1659b0_001659B0;
// MATCH func_001659B0
int pachislot_001659b0(O_1659b0_001659B0 *o, int a) { int v; a++; v = o->h10 + a; if (v < 0) v += o->base->w20; if (v >= o->base->w20) v -= o->base->w20; o->w72 = v; o->vt->fn84((char *)o + o->vt->adj80, v); o->vt->fn60((char *)o + o->vt->adj56); o->w64 = 0; return 1; }

typedef struct { char c[8]; } V8_00173E20;
extern V8_00173E20 D_004A3170_00173E20[3] __asm__("D_004A3170");
typedef struct { char p[32]; short adj32; short pad32; void (*fn36)(void *); char p2[16]; short adj56; short pad56; void (*fn60)(void *, int); } VT_173e20_00173E20;
typedef struct { char p[200]; float f200; } T2_173e20_00173E20;
typedef struct { char p0[88]; int w88; int w92; char p1[4]; float f100; float f104; int w108; T2_173e20_00173E20 *w112; char p2[8]; int w124; char p3[188]; V8_00173E20 v316; char p4[8]; VT_173e20_00173E20 *vt; char p5[8]; int w344; int w348; int w352; } O_173e20_00173E20;
void func_00172C00(void *, int); void func_00172E40(void *); void func_00172BE8(void *, int); void func_00173BE0(void *);
// MATCH func_00173E20
int FUN_00173e20(O_173e20_00173E20 *o) { o->vt->fn60((char *)o + o->vt->adj56, 1); func_00172C00(o, 4); o->w88 = 2; o->vt->fn36((char *)o + o->vt->adj32); o->w108 = 0; if (o->w92 == 0) { o->w112->f200 = 1.0f; if (o->w124 != 0) { func_00172E40(o); return 0; } } if (o->w92 > 0) { if (o->w344 != 0 && o->w352 != o->w348) { func_00173BE0(o); return 0; } o->vt->fn60((char *)o + o->vt->adj56, 3); func_00172BE8(o, 516); o->f100 = o->f104; o->w112->f200 = o->f104; o->v316 = D_004A3170_00173E20[0]; } return 0; }

typedef struct { char c[8]; } V8_00173F38;
extern V8_00173F38 D_004A3178_00173F38[3] __asm__("D_004A3178");
typedef struct { char p[32]; short adj32; short pad32; void (*fn36)(void *); char p2[16]; short adj56; short pad56; void (*fn60)(void *, int); } VT_173f38_00173F38;
typedef struct { char p[200]; float f200; } T2_173f38_00173F38;
typedef struct { char p0[88]; int w88; int w92; char p1[4]; float f100; float f104; int w108; T2_173f38_00173F38 *w112; char p2[8]; int w124; char p3[188]; V8_00173F38 v316; char p4[8]; VT_173f38_00173F38 *vt; char p5[8]; int w344; int w348; int w352; } O_173f38_00173F38;
void func_00172C00(void *, int); void func_00172E40(void *); void func_00172BE8(void *, int); void func_00173BE0(void *);
// MATCH func_00173F38
int FUN_00173f38(O_173f38_00173F38 *o) { o->vt->fn60((char *)o + o->vt->adj56, 1); func_00172C00(o, 4); o->w88 = 1; o->vt->fn36((char *)o + o->vt->adj32); o->w108 = 0; if (o->w92 == 0) { o->w112->f200 = 1.0f; if (o->w124 != 0) { func_00172E40(o); return 0; } } if (o->w92 > 0) { if (o->w344 != 0 && o->w352 != o->w348) { func_00173BE0(o); return 0; } o->vt->fn60((char *)o + o->vt->adj56, 2); func_00172BE8(o, 516); o->f100 = o->f104; o->w112->f200 = o->f104; o->v316 = D_004A3178_00173F38[0]; } return 0; }

typedef struct { char c[8]; } V8_00173CA0;
extern V8_00173CA0 D_004A3160_00173CA0[3] __asm__("D_004A3160"); extern V8_00173CA0 D_004A3168_00173CA0[3] __asm__("D_004A3168");
typedef struct { char p[32]; short adj32; short pad32; void (*fn36)(void *); char p2[16]; short adj56; short pad56; void (*fn60)(void *, int); } VT_173ca0_00173CA0;
typedef struct { char p[200]; float f200; } T2_173ca0_00173CA0;
typedef struct { char p0[88]; int w88; int w92; char p1[4]; float f100; float f104; int w108; T2_173ca0_00173CA0 *w112; char p2[8]; int w124; char p3[188]; V8_00173CA0 v316; char p4[8]; VT_173ca0_00173CA0 *vt; char p5[8]; int w344; int w348; int w352; } O_173ca0_00173CA0;
void func_00172C00(void *, int); void func_00172E40(void *); void func_00172BE8(void *, int); void func_00173BE0(void *);
// MATCH func_00173CA0
int FUN_00173ca0(O_173ca0_00173CA0 *o) { o->vt->fn60((char *)o + o->vt->adj56, 1); func_00172C00(o, 4); o->vt->fn36((char *)o + o->vt->adj32); o->w108 = 0; if (o->w92 == 0) { o->w112->f200 = 1.0f; if (o->w124 != 0) { func_00172E40(o); return 0; } } if (o->w92 > 0) { if (o->w344 != 0 && o->w352 != o->w348) { func_00173BE0(o); return 0; } if (o->w88 == 1) { o->vt->fn60((char *)o + o->vt->adj56, 2); func_00172BE8(o, 516); o->f100 = o->f104; o->w112->f200 = o->f104; o->v316 = D_004A3160_00173CA0[0]; } else if (o->w88 == 2) { o->vt->fn60((char *)o + o->vt->adj56, 3); func_00172BE8(o, 516); o->f100 = o->f104; o->w112->f200 = o->f104; o->v316 = D_004A3168_00173CA0[0]; } } return 0; }

int func_0015CFB0(int, int);
// MATCH func_0015D530
int FUN_0015d530(int *o, int a) { int i; int **p; func_0015CFB0(o[0], a); p = (int **)o[3]; for (i = 0; i < o[4]; i++) { char *e = (char *)*p; if (*(short *)(e + 284) != 0) if (*(short *)(e + 286) != 0) func_0015CFB0((int)e, a); p++; } return 0; }

extern char D_004A380A; extern char D_00346780[]; extern char D_0035A780[];
int func_00202920(int); int func_002034A0(int, int, int); int func_00203378(int, int); int func_001E3D98(int, int, int);
// MATCH func_001E3600
int akari_001e3600(int a, int b) { int n; int i; int x; int y; if (D_004A380A == 0) return 0; n = func_00202920(b); if (n <= 0) return 0; for (i = 0; i < n; i++) { x = func_002034A0(b, i, 0); y = func_00203378(b, i); func_001E3D98(a, x, y); } { char *b = D_00346780; short *p = (short *)(b + 74322); for (i = 290; i >= 0; i--) { *p = 0; p = (short *)((char *)p - 256); } } { char *b = D_0035A780; short *p = (short *)(b + 19026); for (i = 74; i >= 0; i--) { *p = 0; p = (short *)((char *)p - 256); } } return n; }

typedef struct { int a, x, y; int pad[7]; int w40; char pad2[212]; } R__00204018;
typedef struct { char p[360]; R__00204018 *w360; } X__00204018;
typedef struct O__00204018 { X__00204018 *w0; int q[64]; int p[64]; int pad; int w520, w524, w528, w532, w536; unsigned short sh[64]; char b[64]; char t[64]; } O__00204018;
void func_001AF938(X__00204018 *, int, int, int); void func_001AF908(X__00204018 *, int, int); int func_0012D3D8(int);
// MATCH func_00204018
void FUN_00204018(O__00204018 *o, int a, int b, int c)
{
    int i;
    for (i = 0; i < o->w528; i++) {
        if (o->sh[i] == a) {
            if (o->w0 == 0) {
                o->t[i] = 104;
                o->b[i] = b;
                o->q[i] = c;
            } else {
                ((char *)o->w0->w360)[i * 256 + 253] = 104;
                func_001AF938(o->w0, c, i, 0);
                func_001AF908(o->w0, i, func_0012D3D8(b));
            }
            return;
        }
    }
}

typedef struct { int a, x, y; int pad[7]; int w40; char pad2[212]; } R__00204F60;
typedef struct { char p[360]; R__00204F60 *w360; } X__00204F60;
typedef struct O__00204F60 { X__00204F60 *w0; int q[64]; int p[64]; int pad; int w520, w524, w528, w532, w536; unsigned short sh[64]; char b[64]; char t[64]; } O__00204F60;
typedef struct { int n; O__00204F60 *it[1]; } L__00204F60;
extern X__00204F60 *D_004A3830;
void func_00204968(O__00204F60 *); void func_00203D38(O__00204F60 *, int);
// MATCH func_00204F60
void pchjob0_00204f60(L__00204F60 *l)
{
    if (l->n > 0) {
        l->n--;
        func_00204968(l->it[l->n]);
        if (l->it[l->n] != 0)
            func_00203D38(l->it[l->n], 3);
        if (l->n > 0)
            D_004A3830 = l->it[l->n - 1]->w0;
    }
}

typedef struct N__00205DD8 { struct N__00205DD8 *next; int p[3]; void (*fn)(void *); } N__00205DD8;
extern N__00205DD8 *D_002F9804[];
void func_00205C08(void *);
// MATCH func_00205DD8
void pchjob0_00205dd8(N__00205DD8 *p)
{
    N__00205DD8 *n;
    for (n = D_002F9804[0]; n != 0; n = n->next)
        if (n->fn == (void (*)(void *))func_00205C08) break;
    if (n == 0) {
        p->fn = (void (*)(void *))func_00205C08;
        func_00205C08(p);
    }
}

typedef struct N__0020B3A8 { struct N__0020B3A8 *next; int p[3]; void (*fn)(void *); } N__0020B3A8;
extern N__0020B3A8 *D_002F9804_0020B3A8[] __asm__("D_002F9804");
void func_00205F78(void *); void func_00207728(void *); void func_002077B8(void *); void func_00207848(void *);
// MATCH func_0020B3A8
void FUN_0020b3a8(void)
{
    N__0020B3A8 *n;
    for (n = D_002F9804_0020B3A8[0]; n != 0; n = n->next) {
        void (*f)(void *) = n->fn;
        if (f == func_00205F78 || f == func_00207728 || f == func_002077B8 || f == func_00207848)
            f(n);
    }
}

extern int D_003FEBB4[];
extern char D_003E9DF0[];
// MATCH func_0025A508
int FUN_0025a508(void)
{
    int buf[68];
    int i; unsigned k; int n;
    char *p, *q;
    for (i = 0; i < 64; i++) {
        if ((D_003FEBB4[i / 32] >> i) & 1) buf[i] = 0;
        else buf[i] = 1;
    }
    n = 0;
    q = D_003E9DF0;
    p = q + 8;
    for (k = 0; k < 60; k++) {
        int idx = *(int *)p;
        if (buf[idx] == 0) {
            buf[idx] = 1;
            n++;
        }
        p += 168;
    }
    return n;
}

extern int D_004A1A8C; extern char *D_004A1A20_00120B30 __asm__("D_004A1A20"); extern int D_00327820[]; extern int D_004A6D94;
void func_00122118(void);
// MATCH func_00120B30
void battle_00120b30(void) { int n = D_004A1A8C; int i; char *p = D_004A1A20_00120B30; for (i = 0; i < n; i++) { *(int *)(p + 4836 + i * 5472) = D_00327820[i] + 5; } D_004A6D94 = 0; func_00122118(); }

typedef struct { char p[20]; int w20; } P_00164C10;
typedef union { int w; struct { short a; short b; } s; } U;
typedef struct { P_00164C10 *p; int pad4; U u; int w12; int w16; int w20; int w24; char pad28[12]; short d40; short i42; short v44; short v46; } O_00164C10;
// MATCH func_00164C10
void pachislot_00164c10(O_00164C10 *o) { int idx; void (*fn)(void *); int d; int dl; long e; o->w12 = o->u.s.b; o->u.w += o->w24; if (o->u.s.b < 0) o->u.s.b = (unsigned short)o->u.s.b + *(unsigned short *)&o->p->w20; if (o->u.s.b >= o->p->w20) o->u.s.b = (unsigned short)o->u.s.b - *(unsigned short *)&o->p->w20; idx = o->i42; if (idx > 0) { long *vt = *(long **)((char *)o + o->v44); e = vt[idx - 1]; fn = (void (*)(void *))(e >> 32); } else fn = *(void (**)(void *))&o->v44; dl = o->d40; d = idx > 0 ? (short)e + dl : dl; fn((char *)o + d); }

typedef struct { short delta; short index; union { int (*fn)(void *, int **); short voff; } u_00163E68;
} PMF;
extern PMF D_00333A50[];
// MATCH func_00163E68
int FUN_00163e68(char *o, int **pp) { int op; int r; do { int idx; int (*fn)(void *, int **); long e; int dl; int d; op = *(*pp)++; idx = D_00333A50[op].index; if (idx > 0) { long *vt = *(long **)(o + D_00333A50[op].u_00163E68.voff); e = vt[idx - 1]; fn = (int (*)(void *, int **))(e >> 32); } else fn = D_00333A50[op].u_00163E68.fn; dl = D_00333A50[op].delta; d = idx > 0 ? (short)e + dl : dl; r = fn(o + d, pp); } while (r == 0); return op == 13; }

typedef struct { char c[608]; } T608_0029B908;
extern T608_0029B908 D_005F9640[]; extern int D_004A69A8; void func_002A0BA0(void *);
// MATCH func_0029B908
void FUN_0029b908(int *o, int b, int a) { int i; o[0] = a; o[1] = b; o[3] = 0; o[2] = 0; ((short *)o)[10] = 0; for (i = 3; i < D_004A69A8; i++) func_002A0BA0(&D_005F9640[i]); }

void func_00190328(int); void func_00190420(int *); void func_002A5470(int *, int, int, int);
typedef struct { char p[16]; long *q; } P_002A53B0;
// MATCH func_002A53B0
void clas_min_002a53b0(int *o, int a, int b, int c) { P_002A53B0 *p; long *q; if (o[28] != 0) func_00190328(o[30]); p = (P_002A53B0 *)o[30]; q = p->q; q[0] = 97; q[1] = 20; q[2] = 0x31001; q[3] = 71; q[4] = 0x790000006c00L; q[5] = 24; p->q = q + 6; if (o[28] != 0) func_00190420((int *)p); func_002A5470(o, a, b, c); }

extern char D_00440540[];
void *func_0018B508(int, void *);
void func_0018BBE0(int, int, void *, int, short, short, short, short);
void func_001621F8_0018C368(void *, void *, int) __asm__("func_001621F8");
// MATCH func_0018C368
void denlib_0018c368(int a, int b, int c, int d, int e) {
    unsigned cnt[4];
    char *ptr, *s, *t, *q;
    ptr = func_0018B508(a, cnt);
    t = ptr;
    s = ptr + 2;
    while (--cnt[0] != 0xffffffff) *t++ = *s++;
    q = ptr + 12;
    if (*(short *)(q + 14) == 24) func_0018BBE0(b, 2, ptr + 52, 1, d, e, *(short *)(q + 4), *(short *)(q + 8));
    func_001621F8_0018C368(ptr, D_00440540, 916);
}

typedef struct { char c[8]; } V8_001783A0;
extern unsigned long D_004A12D8, D_004A12E0;
extern V8_001783A0 D_004A3368[3];
extern char D_00343028_001783A0[] __asm__("D_00343028");
int func_0010C2B0(void *, int, int, int, int, int, int);
// MATCH func_001783A0
int shuffle_001783a0(char *o) {
    int v, w;
    if ((D_004A12D8 | D_004A12E0) & 0x48000) {
        func_0010C2B0(D_00343028_001783A0, 0, 2, 0, 0, 0, 0);
        v = *(int *)(o + 408) - 1;
        *(int *)(o + 408) = v;
        if (v < 0) *(int *)(o + 408) = 3;
    }
    if ((D_004A12D8 | D_004A12E0) & 0x82000) {
        func_0010C2B0(D_00343028_001783A0, 0, 2, 0, 0, 0, 0);
        v = *(int *)(o + 408) + 1;
        *(int *)(o + 408) = v;
        if (v > 3) *(int *)(o + 408) = 0;
    }
    w = *(int *)(o + 448) - 1;
    *(int *)(o + 448) = w;
    if (w == 0 || (D_004A12D8 & 0x200040)) {
        func_0010C2B0(D_00343028_001783A0, 162, 12, 0, 0, 0, 0);
        *(int *)(o + 416) = 0;
        *(V8_001783A0 *)(o + 476) = D_004A3368[0];
    }
    return 0;
}

typedef struct { char c[8]; } V8_00175CF8;
typedef struct { char p[372]; int w372; char p2[32]; V8_00175CF8 v; V8_00175CF8 v2; } O_00175CF8;
extern V8_00175CF8 D_004A3200[3], D_004A31D8[3], D_004A31E8[3];
extern unsigned long D_004A12D8_00175CF8 __asm__("D_004A12D8"), D_004A12E0_00175CF8 __asm__("D_004A12E0");
extern char D_00336528[], D_00343028_00175CF8[] __asm__("D_00343028");
void func_001749D8(void *, void *);
int func_0010C2B0(void *, int, int, int, int, int, int);
void func_00172C30(void *);
void func_00172CB0(void *);
void func_00174AB8(void *);
void func_00172CB8(void *);
// MATCH func_00175CF8
int repetition_00175cf8(O_00175CF8 *o) {
    func_001749D8(o, D_00336528);
    if ((D_004A12D8_00175CF8 | D_004A12E0_00175CF8) & 0x11000) {
        func_0010C2B0(D_00343028_00175CF8, 0, 2, 0, 0, 0, 0);
        o->w372 = o->w372 - 1;
    }
    if ((D_004A12D8_00175CF8 | D_004A12E0_00175CF8) & 0x24000) {
        func_0010C2B0(D_00343028_00175CF8, 0, 2, 0, 0, 0, 0);
        o->w372 = o->w372 + 1;
    }
    o->w372 = o->w372 & 1;
    if (D_004A12D8_00175CF8 & 0x200040) {
        func_0010C2B0(D_00343028_00175CF8, 0, 2, 0, 1, 0, 0);
        if (o->w372 == 0) {
            func_00172C30(o);
            func_00172CB0(o);
            func_00174AB8(o);
            o->v = D_004A3200[0];
        } else {
            func_00172CB8(o);
            o->v = D_004A31D8[0];
            o->v2 = D_004A31E8[0];
        }
    }
    return 0;
}

typedef struct { char c[8]; } V8_00175AF8;
typedef struct { char p[372]; int w372; char p2[32]; V8_00175AF8 v; V8_00175AF8 v2; } O_00175AF8;
extern V8_00175AF8 D_004A3200_00175AF8[3] __asm__("D_004A3200"), D_004A32D0[3];
extern unsigned long D_004A12D8_00175AF8 __asm__("D_004A12D8"), D_004A12E0_00175AF8 __asm__("D_004A12E0");
extern char D_00336518[], D_00343028_00175AF8[] __asm__("D_00343028");
void func_001749D8(void *, void *);
int func_0010C2B0(void *, int, int, int, int, int, int);
// MATCH func_00175AF8
int repetition_00175af8(O_00175AF8 *o) {
    func_001749D8(o, D_00336518);
    if ((D_004A12D8_00175AF8 | D_004A12E0_00175AF8) & 0x11000) {
        func_0010C2B0(D_00343028_00175AF8, 0, 2, 0, 0, 0, 0);
        o->w372 = o->w372 - 1;
    }
    if ((D_004A12D8_00175AF8 | D_004A12E0_00175AF8) & 0x24000) {
        func_0010C2B0(D_00343028_00175AF8, 0, 2, 0, 0, 0, 0);
        o->w372 = o->w372 + 1;
    }
    o->w372 = o->w372 & 1;
    if (D_004A12D8_00175AF8 & 0x200040) {
        func_0010C2B0(D_00343028_00175AF8, 0, 2, 0, 1, 0, 0);
        if (o->w372 == 0) o->v = D_004A3200_00175AF8[0];
        else o->v = D_004A32D0[0];
    }
    return 0;
}

extern unsigned long D_004A12C8;
extern unsigned long D_004A12D8_0018D6C0 __asm__("D_004A12D8");
extern unsigned *D_004A36AC;
extern int D_004A36B0;
volatile short func_002C0338(int, int);
void func_0018D160(void *);
void func_0018D0A8(void *);
// MATCH func_0018D6C0
void FUN_0018d6c0(void)
{
  int i;
  int off;
  func_002C0338(0, 0);
  if ((D_004A12C8 & 0x100) && (((unsigned *) 0x11008000) < D_004A36AC))
  {
    D_004A36AC = D_004A36AC - 8;
  }
  if ((D_004A12C8 & 0x800) && (D_004A36AC < ((unsigned *) 0x1100fe00)))
  {
    D_004A36AC = D_004A36AC + 8;
  }
  if (D_004A12D8_0018D6C0 & 0x400)
  {
    D_004A36B0 ^= 1;
  }
  i = 0;
  do
  {
    if (D_004A36B0 == 0)
    {
      func_0018D160((unsigned *) (((char *) D_004A36AC) + (i * 16)));
    }
    else
    {
      func_0018D0A8((unsigned *) (((char *) D_004A36AC) + (i * 16)));
    }
    i++;
  }
  while (i < 32);
}
