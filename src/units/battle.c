/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A1660;
// MATCH func_00127EE8
void battle_00127ee8(int a) { if (a != 0) D_004A1660 = 0; else D_004A1660 = 1; }

extern float D_0049FCE8;
// MATCH func_0011BC60
int battle_0011bc60(float a, float b) { if (__builtin_fabsf(a - b) > D_0049FCE8) return 1; return 0; }

extern char D_004308F8[];
int DbgPrintf(char *, ...);
void func_0011D588(int, int);
// MATCH func_001230E0
void SetCard(int a) { DbgPrintf(D_004308F8); func_0011D588(a, -1); }

typedef struct { int pad; int a; char pad2[1180]; int b; } P_00127450;
extern P_00127450 *D_004A1A3C;
// MATCH func_00127450
int battle_00127450(void) { P_00127450 *p = D_004A1A3C; if (p == 0) return 0; if (p->b != 0) return 0; return !(p->a < 100); }

typedef struct { char pad[4816]; unsigned f; char p2[652]; } P_001296B0; extern P_001296B0 *D_004A1A20;
// MATCH func_001296B0
void battle_001296b0(void) { P_001296B0 *p = D_004A1A20; int i; for (i = 0; i < 20; i++) { p->f &= 0xfeffffff; p++; } }

// MATCH func_001296E8
void battle_001296e8(void) { char *p = (char *)D_004A1A20; int i; for (i = 0; i < 20; i++) { *(int *)(p+4816) &= -33; *(int*)(p+4984)=0; *(int*)(p+5408)=0; *(int*)(p+5396)=0; *(int*)(p+5392)=0; *(int*)(p+5388)=0; p += 5472; } }

typedef struct { float x, y, z, w; } V4_001262D0;
typedef struct { char p[64]; V4_001262D0 v1; V4_001262D0 v2; char p2[16]; int i; char pa[4]; int j, k; } O_001262D0;
static inline void set_001262D0(V4_001262D0 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; v->w = 1.0f; }
// MATCH func_001262D0
void battle_001262d0(O_001262D0 *o, float a, float b, float c, int i, int j, int k, float d, float e, float f) { o->i = i; o->j = j; o->k = k; set_001262D0(&o->v1, a, b, c); set_001262D0(&o->v2, d, e, f); }

typedef struct { float x, y, z, w; } V4_00126288;
typedef struct { char p[64]; V4_00126288 v1; V4_00126288 v2; char p2[16]; int i; char pa[4]; int j, k; char pb[4]; float g; int m; } O_00126288;
static inline void set_00126288(V4_00126288 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; v->w = 1.0f; }
// MATCH func_00126288
void battle_00126288(O_00126288 *o, float a, float b, float c, int i, int j, int k, float d, float e, float f, float g, int m) { set_00126288(&o->v1, a, b, c); set_00126288(&o->v2, d, e, f); o->i = i; o->j = j; o->k = k; o->m = m; o->g = g; }

// MATCH func_00126208
int battle_00126208(int x) { if (x & 0x11000) return 0; if (x & 0x24000) return 3; if (x & 0x48000) return 1; return (x & 0x82000) ? 2 : -1; }

extern int D_004A1AA8;
void func_0021E950(int, int, int);
// MATCH func_0012ACA0
void battle_0012aca0(int a, int b) { func_0021E950(D_004A1AA8, b, a); }

int func_001114B0(void);
extern int D_004A14F8;
// MATCH func_00128030
int battle_00128030(void) { if (func_001114B0()) return 1; return D_004A14F8; }

void func_00127000(int, int, int, int, int, int, int, int, int);
// MATCH func_00126FA8
void battle_00126fa8(int a, int b, int c, int d, int e, int f) { func_00127000(0, a, b, c, d, e, f, 0, 0x808080); }

extern float D_0049FE18; extern char D_0053FD00[]; int func_0012C1E8(void *); float func_0015A9A8(char *, float, void *);
// MATCH func_00127498
float battle_00127498(void *o) { float r = 0.0f; if (func_0012C1E8(o)) r = func_0015A9A8(D_0053FD00, D_0049FE18, o); return r; }

extern int D_004A6CA0; extern char *D_004A1A20_00127100 __asm__("D_004A1A20"); extern char D_004312A0[]; int func_001118F8_00127100(char *) __asm__("func_001118F8"); void func_0021A650(char *, int);
// MATCH func_00127100
void battle_00127100(void) { int i; int off = 0; func_001118F8_00127100(D_004312A0); D_004A6CA0 = 1; for (i = 0; i < 20; i++) { func_0021A650(D_004A1A20_00127100 + off, i); off += 5472; } }

typedef struct { char p[32176]; unsigned w32176; } G_00127F70;
extern int D_003279A0_00127F70[] __asm__("D_003279A0"); extern G_00127F70 *D_004A1A20_00127F70 __asm__("D_004A1A20"); int func_00127FC8(int);
// MATCH func_00127F70
int battle_00127f70(void) { if (D_003279A0_00127F70[0] == 0) return 0; if (func_00127FC8(4) != 0) return 1; if (D_004A1A20_00127F70->w32176 & 0x800) return 0; return func_00127FC8(5) != 0; }

extern int D_004A12A4_00126058 __asm__("D_004A12A4"); extern char D_00343010_00126058[] __asm__("D_00343010"); extern int D_004A1AA8_00126058 __asm__("D_004A1AA8"); int func_001E4700(char *); int func_00196FF8_00126058(void) __asm__("func_00196FF8"); int func_0021F650(int);
// MATCH func_00126058
int battle_00126058(void) { if (D_004A12A4_00126058 != 11) return 0; if (func_001E4700(D_00343010_00126058) != 0) return 1; if (func_00196FF8_00126058() != 0) return 1; return func_0021F650(D_004A1AA8_00126058) != 0; }

extern int D_004A6D74, D_004A6D6C, D_004A6D70, D_004A6D68; extern char D_0042FDA0[]; void *func_00162130_00126AA0(int, char *, int) __asm__("func_00162130"); void func_002DC650_00126AA0(void *, int, int) __asm__("func_002DC650");
// MATCH func_00126AA0
void battle_00126aa0(void) { void *p = func_00162130_00126AA0(D_004A6D74, D_0042FDA0, 8534); func_002DC650_00126AA0(p, D_004A6D6C, D_004A6D74); D_004A6D6C = (int)p; p = func_00162130_00126AA0(D_004A6D70, D_0042FDA0, 8538); func_002DC650_00126AA0(p, D_004A6D68, D_004A6D70); D_004A6D68 = (int)p; }

extern int D_004A13D4, D_004A6E54, D_004A6D94; extern float D_004A6DAC; extern char D_00431B68[]; void func_001118F8_0012CAB8(char *, int) __asm__("func_001118F8"); void func_0011C068(int, int, float);
// MATCH func_0012CAB8
void ClearPlayerCamera(float a) { int old = D_004A13D4; D_004A13D4 = 12; D_004A6E54 = 0; if (a >= 0.0f) D_004A6DAC = a; func_001118F8_0012CAB8(D_00431B68, D_004A6D94); func_0011C068(D_004A6D94, 0, 0.0f); D_004A13D4 = old; }

typedef struct { int w0; char p[4]; short h8, h10, h12, h14; char q[10]; short h26, h28; char r[38]; int w68, w72; char s[22]; short h98; char t[28]; } X_00127080;
extern X_00127080 D_00327AA0[]; extern float D_0049FE14; void func_00235028(X_00127080 *, float);
// MATCH func_00127080
void battle_00127080(int i, int a, int b, int c) { if (i < 6) { X_00127080 *o = &D_00327AA0[i]; o->h8 = b; o->h10 = c; o->h12 = b; o->h14 = c; o->h26 = b; o->h28 = c; o->w0 = 11; o->h98 = a; o->w72 = 0; o->w68 = 1; func_00235028(o, D_0049FE14); } }

extern int D_004A1A20_00129730 __asm__("D_004A1A20"); void func_0021B018(int);
// MATCH func_00129730
void battle_00129730(void) { int i, off = 0; unsigned mask = 0xfeffffff; i = 19; do { func_0021B018(D_004A1A20_00129730 + off); *(unsigned *)(off + D_004A1A20_00129730 + 4816) &= mask; off += 5472; } while (--i >= 0); }

extern int D_004303B8[], D_004A1A8C; void func_0011BB28(int, int, int, int, int);
typedef struct { int w[3]; } T3_0011B868;
// MATCH func_0011B868
void battle_0011b868(int a, int b, int c) { T3_0011B868 t = *(T3_0011B868 *)D_004303B8; int i; for (i = 0; i < D_004A1A8C; i++) func_0011BB28(i, t.w[i], a, b, c); }

extern int D_004A1A84; extern short D_00324478[];
void battle_0011b868(int, int, int); void battle_0011bb28(int, int, int, int, int);
// MATCH func_001274E8
void battle_001274e8(int a, int b) { int k; short *p; if (a == 0) battle_0011b868(0xb4, 1, b); if (a == 1 && (a = 0, 0 < D_004A1A84)) { p = D_00324478; do { k = a + 4; a = a + 1; battle_0011bb28(k, p[0], p[1], 1, b); p = p + 2; } while (a < D_004A1A84); } }

extern int D_004A1A20_00125340 __asm__("D_004A1A20"); extern char D_00430D80[]; unsigned long long func_001118F8_00125340(char *, ...) __asm__("func_001118F8");
// MATCH func_00125340
void NextTargetMotion(int a) { char *e; func_001118F8_00125340(D_00430D80); e = (char *)(a * 5472 + D_004A1A20_00125340); *(unsigned *)(e + 4816) = *(unsigned *)(e + 4816) | 0x20; }

extern int D_004A1A20_001227B8 __asm__("D_004A1A20"); extern int D_004A6D94_001227B8 __asm__("D_004A6D94"); int func_00290818(void);
// MATCH func_001227B8
int battle_001227b8(void) { if (func_00290818() != 0) return 1; return *(int *)(D_004A6D94_001227B8 * 5472 + D_004A1A20_001227B8 + 4836) == 13; }

extern float D_0049FE4C;
// MATCH func_0012A140
int battle_0012a140(int o) { float f; float g; int r; f = *(float *)(o + 0x58); if (f < 4000.0f) { g = f; if (g < 0.0f) { g = 0.0f; } g = g * 128.0f * D_0049FE4C; r = (int)g; } else { r = 0x80; } if (r < 0) { r = 0; } if (0x80 < r) { r = 0x80; } return r & 0xf0; }

extern int D_004A6DFC_12AC10 __asm__("D_004A6DFC"), D_004A6C50_12AC10 __asm__("D_004A6C50"), D_004A6D98_12AC10 __asm__("D_004A6D98");
void func_00124A48_12AC10(int, float, float, float, float) __asm__("func_00124A48"); void func_0011E0B0_12AC10(int, float, float) __asm__("func_0011E0B0"); void func_0012A7F8_12AC10(int, float) __asm__("func_0012A7F8");
// MATCH func_0012AC10
void battle_0012ac10(void) { D_004A6C50_12AC10 = 1; D_004A6DFC_12AC10 = 1; func_00124A48_12AC10(10844, 10.0f, 0.0f, 0.0f, 0.0f); if (D_004A6D98_12AC10 < 0) func_0011E0B0_12AC10(300, 0.0f, 10.0f); else func_0011E0B0_12AC10(300, 0.0f, 10.0f); func_0012A7F8_12AC10(1, -1.0f); }

extern int D_004A1A20_11D840 __asm__("D_004A1A20"); extern char D_004305B0_11D840[] __asm__("D_004305B0"); int func_001118F8_11D840(char *, ...) __asm__("func_001118F8");
// MATCH func_0011D840
int battle_0011d840(int a) { int i = 0; unsigned *p = *(unsigned **)(a * 0x1560 + D_004A1A20_11D840 + 0x1550); do { if ((*p & 0x102) != 0) return 1; if ((*p & 1) != 0) return 0; i = i + 1; p = p + 39; } while (i < 256); func_001118F8_11D840(D_004305B0_11D840); return 0; }

extern int D_004A6E24_122710 __asm__("D_004A6E24"), D_004A6DC8_122710 __asm__("D_004A6DC8"), D_004A6DCC_122710 __asm__("D_004A6DCC"), D_004A6D94_122710 __asm__("D_004A6D94"), D_004A6D9C_122710 __asm__("D_004A6D9C"), D_004A1A20_122710 __asm__("D_004A1A20"), D_004A6CF0_122710 __asm__("D_004A6CF0"); extern char D_004307E8_122710[] __asm__("D_004307E8"), D_004307F8_122710[] __asm__("D_004307F8"), D_00430818_122710[] __asm__("D_00430818");
void func_00239568_122710(char *, int, int) __asm__("func_00239568"); int func_0011DB78_122710(int) __asm__("func_0011DB78"); int func_001118F8_122710(char *, ...) __asm__("func_001118F8"); void func_0012AEA8_122710(int) __asm__("func_0012AEA8"); int func_0012ACB0_122710(int) __asm__("func_0012ACB0");
// MATCH func_00122710
void battle_00122710(void) { int a, q; if (D_004A6E24_122710 != 0) { func_00239568_122710(D_004307E8_122710, D_004A6DC8_122710, D_004A6DCC_122710); func_00239568_122710(D_004307F8_122710, D_004A6D94_122710, D_004A6D9C_122710); } a = D_004A6D94_122710; q = a * 0x1560 + D_004A1A20_122710; if (*(int *)(q + 0x12e4) != 13) *(unsigned *)(q + 0x12d0) = *(unsigned *)(q + 0x12d0) | 2; if (func_0011DB78_122710(a) == 0) { func_001118F8_122710(D_00430818_122710); func_0012AEA8_122710(12); } func_0012ACB0_122710(0); D_004A6CF0_122710 = D_004A6CF0_122710 + 1; }

typedef struct { char c[16]; } B16_0012AFB0;
extern char D_00327A40_12AFB0[] __asm__("D_00327A40"), D_004318B8_12AFB0[] __asm__("D_004318B8"); void func_001118F8_12AFB0(char *) __asm__("func_001118F8");
// MATCH func_0012AFB0
void battle_0012afb0(char *o, B16_0012AFB0 *a, B16_0012AFB0 *b, int c) { *(B16_0012AFB0 *)(o + 64) = *a; *(B16_0012AFB0 *)(o + 80) = *b; if (*(int *)(o + 96) == 0) { *(int *)(o + 96) = c; *(int *)(o + 100) = c; *(B16_0012AFB0 *)o = *(B16_0012AFB0 *)D_00327A40_12AFB0; *(B16_0012AFB0 *)(o + 16) = *(B16_0012AFB0 *)(D_00327A40_12AFB0 + 16); *(B16_0012AFB0 *)(o + 32) = *(B16_0012AFB0 *)(D_00327A40_12AFB0 + 32); func_001118F8_12AFB0(D_004318B8_12AFB0); } }

extern char *D_004A1A20_1269A0 __asm__("D_004A1A20"); extern float D_0049FE10_1269A0 __asm__("D_0049FE10");
// MATCH func_001269A0
float battle_001269a0(int a, int b) { char *g = D_004A1A20_1269A0; return (*(float *)(g + a * 5472 + 4900) + *(float *)(g + b * 5472 + 4900)) * 5120.0f * D_0049FE10_1269A0; }

extern int D_004A6D0C_127000 __asm__("D_004A6D0C"); extern char *D_004A6CFC_127000 __asm__("D_004A6CFC");
// MATCH func_00127000
void battle_00127000(int a, int b, int c, int d, int e, int f, int g, int h, int i, float x) { int *p; int n; n = D_004A6D0C_127000; if (n < 64) { p = (int *)(n * 40 + (int)D_004A6CFC_127000); p[9] = i; p[3] = a; p[0] = e; p[1] = f; p[2] = g; p[4] = d; p[6] = c; p[5] = b; p[8] = h; ((float *)p)[7] = x; D_004A6D0C_127000 = n + 1; } }

