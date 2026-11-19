/* Functions of this report unit, matched by hand. */
#include "../common.h"
#include "battle_load.h"

typedef struct {
    char bytes[16];
} BattleTransformBlock;

typedef struct {
    char pad[32];
    union {
        float position[4];
        BattleTransformBlock block;
    } transform;
    char gap[80];
    BattleTransformBlock originalTransform;
} BattleModel_11ADC0;

extern char D_004A1910[], D_00321AA0[];
extern int D_002F9804[];
int func_001118F8_11ADC0(char *, ...) __asm__("func_001118F8");
BattleModel_11ADC0 *func_00246D88(char *, int);
void func_00246188(BattleModel_11ADC0 *, int, int, int);

// MATCH func_0011ADC0
BattleModel_11ADC0 *battle_0011adc0(int id, const float *position)
{
    BattleModel_11ADC0 *model;

    func_001118F8_11ADC0(D_004A1910, id);
    model = func_00246D88(D_00321AA0, D_002F9804[0]);
    model->transform.position[0] = position[0];
    model->transform.position[1] = position[1];
    model->transform.position[2] = position[2];
    model->originalTransform = model->transform.block;
    if (id)
        func_00246188(model, id, 0, 0);
    return model;
}

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

typedef struct { char p[188]; short s188; } BO_0012C9B0_12C9B0;
extern BO_0012C9B0_12C9B0 *D_003279A0_12C9B0[] __asm__("D_003279A0"); extern int D_004A1A20_12C9B0 __asm__("D_004A1A20");
int func_00129E80_12C9B0(int) __asm__("func_00129E80"); void func_0011C068_12C9B0(int, int, float) __asm__("func_0011C068"); int func_0021A938_12C9B0(int) __asm__("func_0021A938");
// MATCH func_0012C9B0
int battle_0012c9b0(int a) { int r; int s; r = 0; if (func_00129E80_12C9B0(a) == 2) { D_003279A0_12C9B0[a]->s188 = 0; r = 1; func_0011C068_12C9B0(a, 0, 1.0f); } s = func_00129E80_12C9B0(a); if (s == 1) { if (func_0021A938_12C9B0(D_004A1A20_12C9B0 + a * 5472) != 0) { D_003279A0_12C9B0[a]->s188 = s; func_0011C068_12C9B0(a, 0, 1.0f); } else { D_003279A0_12C9B0[a]->s188 = 0; r = 1; func_0011C068_12C9B0(a, 0, 1.0f); } } return r; }

extern int D_004A1A20_00128248 __asm__("D_004A1A20");
int func_00291DC0_128248(int, int, int, int, int, int) __asm__("func_00291DC0");
void battle_001252a0(int param_1);
// MATCH func_00128248
void battle_00128248(int param_1)  { short sVar1; int iVar2;  sVar1 = *(short *)(param_1 + 0xae); func_00291DC0_128248(sVar1,1,0x40000008,0,0,2); func_00291DC0_128248(sVar1,2,0x40000009,0,0,2); iVar2 = (D_004A1A20_00128248); *(int *)(param_1 + 0xc0) = 0; *(int *)(sVar1 * 0x1560 + iVar2 + 0x1378) = 0; battle_001252a0(sVar1); return; }

extern int D_004A1A20_121918 __asm__("D_004A1A20");
extern int D_003279A0_121918[] __asm__("D_003279A0");
// MATCH func_00121918
int battle_00121918(int param_1) { int iVar1; int k = param_1 + 4; if (D_003279A0_121918[k] != 0) { iVar1 = param_1 * 0x1560 + D_004A1A20_121918 + 0x5580; if ((*(unsigned *)(iVar1 + 0x1474) & 0x200) != 0) { return 0; } if (*(int *)(*(int *)(iVar1 + 0x1444) + 0x38) != 0) { return 1; } } return 0; }


typedef struct { char p0[32]; float f32; char p36[4]; float f40; char p44[24]; float f68; } U_12A6E0;
typedef struct { char p0[5472]; } B_12A6E0;
extern U_12A6E0 *D_003279A0[]; extern B_12A6E0 *D_004A1A20_12A6E0 __asm__("D_004A1A20"); extern char D_004A1A08[];
void func_001118F8(char *, ...); float func_0015FB58(float, int); void func_0021B550(B_12A6E0 *);
// MATCH func_0012A6E0
void battle_0012a6e0(float a) {
  int i;
  func_001118F8(D_004A1A08, (double)a);
  for (i = 0; i < 20; i++) {
    if (D_003279A0[i] != 0) {
      float x = D_003279A0[i]->f32;
      float z = D_003279A0[i]->f40;
      D_003279A0[i]->f32 = x * func_0015FB58(a, 1) - z * func_0015FB58(a, 0);
      D_003279A0[i]->f40 = z * func_0015FB58(a, 1) + x * func_0015FB58(a, 0);
      func_0021B550(&D_004A1A20_12A6E0[i]);
      D_003279A0[i]->f68 -= a;
    }
  }
}

extern int D_004A1A20_129E10 __asm__("D_004A1A20");
int func_00127430(void);
int func_0012C448(int);

// MATCH func_00129E10
int battle_00129e10(void)
{
    int state;

    if (func_00127430())
        return 0;
    if (func_0012C448(D_004A6D94))
        return 0;

    state = *(int *)(D_004A6D94 * 5472 + D_004A1A20_129E10 + 4836);
    if (state == 1)
        return 0;
    if (state == 2)
        return 0;
    else
        return 1;
}

extern float D_0049FE54, D_004A167C;
extern volatile float D_0049FE58;
extern int D_004A6C2C;

// MATCH func_0012A7F8
void battle_0012a7f8(int mode, float scale)
{
    if (scale >= 0.0f)
        D_004A6DAC = scale;
    D_004A6C2C = mode;

    switch (mode) {
    case 0:
        D_004A167C = 0.0f;
        break;
    case 1:
        D_004A167C = D_0049FE54;
        break;
    case 2:
        D_004A167C = D_0049FE58;
        break;
    }
}

extern int D_004A12A4;
extern char D_00431B88[], D_00431B98[];
int func_00196FF8(void);
int func_0018B2A8(char *);
void func_0018B7C8(char *, char *);
void func_0018B668(char *, char *);

// MATCH func_0012CBE8
int battle_0012cbe8(BattleLoadList *list)
{
    int size;

    if (func_00196FF8())
        return 1;
    if (list->remaining != 0) {
        int current;
        BattleLoadEntry *entry;
        char *buffer;

        list->remaining--;
        size = func_0018B2A8(list->entries[list->current].name);
        if (size < 0) {
            func_001118F8(D_00431B88);
            return 0;
        }
        if (list->totalSize + size > 0x125000) {
            func_001118F8(D_00431B98);
            return 0;
        }
        if (D_004A12A4 == 10)
            func_0018B7C8(list->entries[list->current].name, list->buffer);
        else
            func_0018B668(list->entries[list->current].name, list->buffer);

        current = list->current;
        entry = &list->entries[current];
        buffer = list->buffer;
        list->entries[current].size = size;
        entry->data = buffer;
        list->totalSize += size;
        list->buffer += size;
        list->current++;
        return 1;
    }
    return 0;
}

extern int D_004A1AAC;
int func_00126058(void);

// MATCH func_00129B78
int battle_00129b78(void)
{
    int state = D_004A1AAC;

    if (state == 1)
        return 1;
    if (state == 2 || state == 0) {
        int ready = func_00126058();

        if (ready != 0)
            return 1;
    }
    return 0;
}

extern int D_004A1A20_127168 __asm__("D_004A1A20");
extern char D_004312B0[], D_004312C0[];
void func_0021A730(int, int);

// MATCH func_00127168
void battle_00127168(void)
{
    unsigned mask;
    int i, offset;

    if (D_004A6CA0 == 0) {
        func_001118F8(D_004312B0);
        return;
    }
    func_001118F8(D_004312C0);
    i = 0;
    mask = 0xfeffffff;
    offset = 0;
    do {
        func_0021A730(D_004A1A20_127168 + offset, i);
        i++;
        *(unsigned *)(offset + D_004A1A20_127168 + 4816) &= mask;
        offset += 5472;
    } while (i < 20);
}

extern int D_004A1A50, D_004A1A60, D_004A6D94, D_004A6C50;
extern unsigned D_00425510[];
void func_00127600(void);
void func_00124A48(int, float, float, float, float);
void func_0011E0B0(int, float, float);
void func_00235130(int, int);
void SetBattleEnd(int);
// MATCH func_00127890
void battle_00127890(int mode)
{
    if (mode == 0) {
        func_00127600();
        func_00124A48(8972, 0.0f, 0.0f, 0.0f, 0.0f);
        func_0011E0B0(300, 0.0f, 0.0f);
    }
    D_004A1A50 |= 0x10;
    D_00425510[1] |= 0x14000;
    func_00235130(-1, D_004A1A60);
    SetBattleEnd(-1);
    D_004A6D94 = -1;
    D_004A6C50 = 1;
}

extern int D_004A6C40, D_004A6EAC, D_004A6CA4;
extern char D_00431670[], D_00431680[];
extern int func_0027BDB8(void);
extern int func_00220B78(void);
extern void func_001298E8(int, int);

// MATCH func_00129A38
int battle_00129a38(int waitForMotion)
{
    int id;
    int ready;
    if (D_004A6C40 != 0)
        return 0;
    id = func_0027BDB8();
    if (func_00220B78())
        return 1;
    if (D_004A6CA4 == id)
        return 0;
    {
        register long test __asm__("$17") = 1;
        __asm__ volatile ("" : : "r"(test));
        ready = func_00126058();
        test = ready ? (waitForMotion ? 0 : test) : test;
        if (test == 0)
            return 1;
    }
    if (id >= 0) {
        func_001118F8(D_00431670, id);
        func_001298E8(id, waitForMotion);
        D_004A6EAC = id;
    } else {
        if (D_004A6EAC != id)
            func_001118F8(D_00431680, id);
        D_004A6EAC = id;
    }
    return 0;
}

extern int D_004A6E34, D_004A6C80, D_004A6C24, D_004A1460, D_004A6C28, D_004A6C30, D_004A6CA4;
extern void *D_004A1AA8_12ACB0 __asm__("D_004A1AA8");
extern char D_004318A0[], D_00343010[];
extern void func_001E3F88(char *, int);
extern void func_002206E0(void *, int);
extern void func_00239568(char *, int);
extern void func_0021F2A8(void *, int, int);
extern int func_00129A38(int);
extern int func_0012AE68(void);
// MATCH func_0012ACB0
int battle_0012acb0(int mode)
{
    int pending = 0;
    int retry = 0;
    if (D_004A6E34 > 0) {
        D_004A6E34--;
        return 7;
    }
    if (D_004A6C80 != 0 || mode != 0)
        pending = func_00129A38(1);
    if (mode == 1) {
        if (func_00126058())
            return 1;
        if (func_0012AE68())
            return 5;
    }
    if (D_004A6C24 == 0) {
        if (D_004A1460)
            func_00239568(D_004318A0, D_004A6C28);
        retry = ++D_004A6C28 >= 3;
    }
    if (!mode && !retry)
        return 0;
    func_001E3F88(D_00343010, 1);
    func_002206E0(D_004A1AA8_12ACB0, 0);
    if (D_004A6C30 != 0) {
        if (--D_004A6C30 != 0)
            return 4;
    }
    if (mode != 0)
        return 0;
    if (pending != 0)
        return 2;
    if (D_004A6CA4 >= 0)
        func_0021F2A8(D_004A1AA8_12ACB0, D_004A6CA4, 1);
    return 0;
}

void func_001265D8(int);

// MATCH func_001265D0
void battle_001265d0(int mode)
{
    func_001265D8(mode);
}

typedef struct {
    char prefix[4816];
    int flags;
    char gap[123];
    signed char state;
    char rest[260];
    float timer;
    char suffix[264];
} BattleActor_C808;

typedef struct {
    char prefix[24];
    unsigned flags;
} BattlePart_C808;

extern BattleActor_C808 *D_004A1A20_12C808 __asm__("D_004A1A20");
extern BattlePart_C808 *D_003279A0_12C808[] __asm__("D_003279A0");
extern const float D_0049FE70;
extern char D_00431AE8[], D_00431B00[], D_00431B18[], D_00431B30[];
extern void func_002395A0(char *);

// MATCH func_0012C808
int battle_0012c808(unsigned actor)
{
    BattlePart_C808 **entry;
    BattleActor_C808 *slot;
    int offset;
    if (actor >= 20) {
        func_002395A0(D_00431AE8);
        return -1;
    }
    entry = &D_003279A0_12C808[(int)actor];
    if (*entry == 0) {
        func_001118F8(D_00431B00);
        return -2;
    }
    offset = (int)actor * 5472;
    slot = (BattleActor_C808 *)(offset + (int)D_004A1A20_12C808);
    if (slot->timer != 0.0f) {
        func_001118F8(D_00431B18);
        return -3;
    }
    if (slot->flags & 0x40000000)
        return -4;
    if (slot->state != 0)
        return -5;
    func_001118F8(D_00431B30);
    {
        BattlePart_C808 *part = *entry;
        BattleActor_C808 *current = (BattleActor_C808 *)(offset + (int)D_004A1A20_12C808);
        int flags = current->flags;
        float timer = D_0049FE70;
        current->timer = timer;
        current->flags = (flags | 0x800) & -2;
        part->flags |= 0x20000000;
    }
    return 0;
}

typedef struct {
    unsigned char prefix[174];
    short id;
    unsigned char gap[16];
    int field192;
} BattleMotion_1282D0;

extern int D_004A1A20_1282D0 __asm__("D_004A1A20");
extern char D_004313D0[], D_004313E8[], D_00431400[], D_00431418[];
extern int func_00291C20(BattleMotion_1282D0 *, int, int);
extern int func_00291DC0(int, int, int, int, int, int);
extern void func_001252A0(int);

// MATCH func_001282D0
int battle_001282d0(BattleMotion_1282D0 *motion)
{
    short id = motion->id;
    int actors;
    if (func_00291C20(motion, 3, 2) < 0)
        goto fail;
    func_00291DC0(id, 0, 0, 0, 0, 2);
    func_00291DC0(id, 1, 8, 3, 2, 2);
    if (func_00291C20(motion, 3, 3) >= 0) {
        func_00291DC0(id, 2, 0x40000009, 3, 3, 2);
        func_001118F8_11ADC0(D_004313D0, id);
    } else {
        func_001118F8_11ADC0(D_004313E8, id);
    }
    actors = D_004A1A20_1282D0;
    motion->field192 = 0;
    *(int *)(id * 5472 + actors + 4984) = 0;
    func_001252A0(id);
    func_001118F8_11ADC0(D_00431400, id);
    return 0;

fail:
    func_001118F8_11ADC0(D_00431418, id);
    return -1;
}

extern int D_004A6C44, D_004A6E88;
extern char D_004317C0[];
int func_0021F2A8_12A860(void *, int, int) __asm__("func_0021F2A8");

// MATCH func_0012A860
int battle_0012a860(int actor)
{
    if (D_004A1AAC != 0) {
stop:
        func_0012ABF0(4);
        return 0;
    }
    if (D_004A6C44 != 0 && D_004A6E88 != 0) {
        --D_004A6E88;
        return 1;
    }
    if (func_00126058())
        return 2;
    if (actor < 0)
        goto stop;
    if (D_004A6CA4 == actor) {
        if (func_0021F2A8_12A860(D_004A1AA8_12ACB0, actor, 1))
            return 3;
        if (D_004A6CA4 == actor)
            goto unchanged;
    }
    func_001118F8(D_004317C0, D_004A6CA4, actor);
    func_001298E8(actor, 0);
    D_004A6C44 = 1;
    D_004A6E88 = 120;
    return 4;
unchanged:
    return 0;
}

extern int D_004A6E4C;
extern int D_004A1A20_12C448 __asm__("D_004A1A20");

// MATCH func_0012C448
int battle_0012c448(int actor)
{
    register int actorIndex __asm__("$3") = actor;
    int expected = D_004A6D94;
    int stride = 5472;
    if (actorIndex != expected)
        return 0;
    {
        int base = D_004A1A20_12C448;
        register int offset __asm__("$4");
        int flags;
        register int result __asm__("$2") = 0;
        offset = actorIndex * stride;
        flags = *(int *)(offset + base + 4816);
        if (flags & 0x20000000)
            result = D_004A6E4C == 30;
        return result;
    }
}

extern int D_004A1AA8,D_004A1A50,D_004A1A20_1260B0 __asm__("D_004A1A20"),D_004A6E80,D_004A3860,D_004A12A4,D_004A6E48;
extern unsigned char D_004A1A70;
extern int D_00314CC8[];
extern char D_00343028[],D_00430F70[],D_003210E0[];
void func_002206E0_1260B0(int, int) __asm__("func_002206E0");
void func_00265C30(int), func_0021AAF8(int), func_002224A8(int, int, int, int);
int func_00127210(void);
void func_0010E368(char *),func_0010ED80(char *),func_0010E820(char *,int),func_002A1958(void);
void func_001118F8(char *,...);
// MATCH func_001260B0
void battle_001260b0(void)
{
    int i,offset;
    func_002206E0_1260B0(D_004A1AA8,0);
    func_002206E0_1260B0(D_004A1AA8,1);
    if (D_004A1A50 & 16) func_00265C30(0);
    if (func_00127210()) func_00265C30(0);
    offset = 0;
    for (i = 19; i >= 0; --i, offset += 5472)
        func_0021AAF8(D_004A1A20_1260B0 + offset);
    if (D_00314CC8[0] == 239)
        D_00425510[1] |= 0x08000000;
    D_004A3860 = D_004A6E80;
    if (!(D_004A1A50 & 8)) func_002224A8(0,0,0,0);
    if (D_004A12A4 != 14) {
        if (!D_004A6E48) {
        func_0010E368(D_00343028);
        func_0010ED80(D_00343028);
        func_0010E820(D_00343028,102);
        }
    } else {
        func_0010E368(D_00343028);
        func_002A1958();
    }
    func_001118F8(D_00430F70);
    D_003210E0[40] = D_004A1A70;
}

typedef struct { char pad[12]; unsigned flags; char rest[12]; } BattleConfig_1241F0;
extern BattleConfig_1241F0 D_00323B40[];
extern int D_004A13D4, D_004A1A50, D_004A6D94;
extern char *D_004A1A20_1241F0 __asm__("D_004A1A20");


// MATCH func_001241F0
int battle_001241f0(int actor)
{
    int expected;
    register int result __asm__("$2");
    if (!(D_00323B40[D_004A13D4].flags & 8))
        return 0;
    if (D_004A1A50 & 16)
        return 0;
    expected = D_004A6D94;
    result = 0;
    if (expected == actor)
        result = *(signed char *)(5472 * actor + D_004A1A20_1241F0 + 5305) != 0;
    return result;
}

typedef struct { char pad[1188]; int state; } Substate;
typedef struct { char pad[1240]; Substate *substate; } Context;
typedef struct { char pad[56]; int count; } ActorAction;
extern Context *D_004A1A3C_1269E0 __asm__("D_004A1A3C");
extern int D_004A1A20_1269E0 __asm__("D_004A1A20");
int func_001227B8(void);
// MATCH func_001269E0
int battle_001269e0(int actor)
{
    Substate *state;
    register int result __asm__("$2");
    int busy;

    if (func_00127430() && (state = D_004A1A3C_1269E0->substate) && !state->state) {
        result = 0;
    } else {
        busy = func_001227B8();
        result = 0;
        if (!busy)
            result = (*(ActorAction **)(actor * 5472 + D_004A1A20_1269E0 + 5188))->count <= busy;
    }
    return result;
}
