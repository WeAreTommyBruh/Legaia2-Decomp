/* Functions of this report unit, matched by hand. */
#include "../common.h"
typedef char *va_list;

extern int D_004A6B90, D_004A6B94;
// MATCH func_001118A8
int FUN_001118a8(void) { return D_004A6B94 == D_004A6B90 - 1; }

extern volatile int D_004A6BB8;
// MATCH func_001118E8
int FUN_001118e8(void) { return D_004A6BB8; }

extern int D_004A1320;
// MATCH func_00110080
void FUN_00110080(int a) { if (a < 0) D_004A1320 = 6; else D_004A1320 = a; }

extern char D_0042E820[];
extern int D_004A1214;
int DbgPrintf(char *, ...);
// MATCH func_0010F1E0
void SetDrawNowLoading(void) { DbgPrintf(D_0042E820); D_004A1214 = 1; }

extern char D_0042E838[];
extern int D_004A1214;
int DbgPrintf(char *, ...);
// MATCH func_0010F208
void ReleaseDrawNowLoading(void) { DbgPrintf(D_0042E838); D_004A1214 = 0; }

extern int D_004A12B0; extern int D_004A13E0[2]; extern int D_00314C28[];
// MATCH func_001113D8
int FUN_001113d8(void) { return D_00314C28[0] - D_004A13E0[D_004A12B0 & 1]; }

extern int D_004A1214; extern char D_00315E00[], D_00342CD0[];
void func_00100420(void *,void *,int,int,int,int);
// MATCH func_0010F230
void FUN_0010f230(void) { if (D_004A1214 != 0) func_00100420(D_00315E00, D_00342CD0, 0, 0, 0, 128); }

extern int D_00343028[]; extern int D_004A3850; void func_0010ED80(void *);
// MATCH func_0010F000
void FUN_0010f000(void) { if (((D_00343028[0]) & 8) == 0 && D_004A3850 != 2) func_0010ED80(D_00343028); }

void func_0024AD58(int, int, int, int); void func_00111170(int);
// MATCH func_0010F3B8
void FUN_0010f3b8(int a, int b, int c) { func_0024AD58(a, b, c, 128); func_00111170(0); func_00111170(0); }

extern long long D_00319260[64];
// MATCH func_001100B8
void FUN_001100b8(void) { int i; for (i = 63; i >= 0; i--) D_00319260[i] = 0; }

typedef struct { float f0; float f4, f8; float f12; float f16; float f20, f24, f28, f32, f36; float f40; } F_10f050_0010F050;
void func_00108C80(void *); void func_00108C20(void *);
// MATCH func_0010F050
void FUN_0010f050(F_10f050_0010F050 *s, float a, float b, float c, float d, float e) {
s->f0 = 0.0f;
s->f4 = a;
s->f8 = b;
s->f16 = d;
s->f40 = 1.0f;
s->f12 = 0.0f;
s->f24 = 0.0f;
s->f28 = 0.0f;
s->f32 = 0.0f;
s->f36 = 0.0f;
s->f20 = 0.0f;
if (s->f0 <= c) s->f12 = c;
if (s->f0 <= e) { s->f24 = e; s->f28 = e; }
func_00108C80(s); func_00108C20(s);
}

int func_001114B0(void); int func_002E02F8(char *, va_list);
// MATCH func_001118F8
int DbgPrintf(char *fmt, ...) { va_list ap; if (func_001114B0() != 0) return 0; ap = (va_list)__builtin_next_arg(fmt) - 56; return func_002E02F8(fmt, ap); }

extern int D_00343028_0010EF68[] __asm__("D_00343028"); extern int D_004A3850_0010EF68 __asm__("D_004A3850"); int func_0010AF68(int, int, int, int);
// MATCH func_0010EF68
int FUN_0010ef68(int a, int b, int c) { if ((D_00343028_0010EF68[0] & 8) || D_004A3850_0010EF68 == 2) return 1; return func_0010AF68(a, 901, b, c); }

extern int D_00343028_0010EFB0[] __asm__("D_00343028"); extern int D_004A3850_0010EFB0 __asm__("D_004A3850"); int func_0010C2D0(int, int, int, int, int);
// MATCH func_0010EFB0
int FUN_0010efb0(int a, int b, int c, int d) { if ((D_00343028_0010EFB0[0] & 8) || D_004A3850_0010EFB0 == 2) return 0; return func_0010C2D0(a, 901, b, c, d); }

typedef struct { char p[8]; short adj; short pad; void (*fn)(void *, int *); } VT_0010F310;
typedef struct { char p0[8]; int *w8; char p1[12]; VT_0010F310 *vt; } O_0010F310;
// MATCH func_0010F310
void FUN_0010f310(O_0010F310 *o) { int *p = o->w8; p[0] = 0x10000000; p[3] = 0x13000000; p[1] = 0; p[2] = 0; o->w8 = p + 4; o->vt->fn((char *)o + o->vt->adj, p + 4); }

extern char D_0042E448[]; extern int D_00343028_0010E250[] __asm__("D_00343028"); extern int D_004A3850_0010E250 __asm__("D_004A3850"), D_004A118C_0010E250 __asm__("D_004A118C"); extern char *D_004A12B0_0010E250 __asm__("D_004A12B0"); void func_001118F8_0010E250(char *, ...) __asm__("func_001118F8"); void func_002D51A8(int, int);
// MATCH func_0010E250
void FUN_0010e250(int a, int b) { if (!(D_00343028_0010E250[0] & 8) && D_004A3850_0010E250 != 2) { if (D_004A118C_0010E250 & 0x40) func_001118F8_0010E250(D_0042E448, D_004A12B0_0010E250); func_002D51A8(3, b); } }

extern char D_0042E4D0[]; extern int D_00343028_0010E428[] __asm__("D_00343028"); extern int D_004A3850_0010E428 __asm__("D_004A3850"), D_004A118C_0010E428 __asm__("D_004A118C"); extern char *D_004A12B0_0010E428 __asm__("D_004A12B0"); void func_001118F8_0010E428(char *, ...) __asm__("func_001118F8"); void func_0010E2C0(int, int); void func_002D5280(int); void func_002D50E0(int); void func_002D5038(void);
// MATCH func_0010E428
void FUN_0010e428(int a) { if (!(D_00343028_0010E428[0] & 8) && D_004A3850_0010E428 != 2) { if (D_004A118C_0010E428 & 0x40) func_001118F8_0010E428(D_0042E4D0, D_004A12B0_0010E428); func_0010E2C0(a, 0); func_002D5280(3); func_002D50E0(0); func_002D50E0(1); func_002D5038(); } }

extern int D_00343028_0010D7E8[] __asm__("D_00343028"), D_003436B4[]; extern int D_004A118C_0010D7E8 __asm__("D_004A118C"), D_004A11D8; extern char D_0042DFB8[]; void func_001118F8_0010D7E8(char *, ...) __asm__("func_001118F8"); int func_0010D8A0(int, int);
// MATCH func_0010D7E8
int FUN_0010d7e8(int a, int b, int c) { int r; if ((D_00343028_0010D7E8[0] ^ 1) & 1) return 0; if (D_004A118C_0010D7E8 & 1) func_001118F8_0010D7E8(D_0042DFB8, b); D_003436B4[0] = 100; r = func_0010D8A0(a, c); if (r < 0) return r; if ((unsigned)(b - 6) < 58) D_004A11D8 = b; else D_004A11D8 = -1; return r; }

extern int D_00343028_0010DCC8[] __asm__("D_00343028"), D_003436B4_0010DCC8[] __asm__("D_003436B4"); extern int D_004A118C_0010DCC8 __asm__("D_004A118C"), D_004A11D8_0010DCC8 __asm__("D_004A11D8"); extern char D_0042E278[]; void func_001118F8_0010DCC8(char *, ...) __asm__("func_001118F8"); int func_0010DD80(int, int);
// MATCH func_0010DCC8
int FUN_0010dcc8(int a, int b, int c) { int r; if ((D_00343028_0010DCC8[0] ^ 1) & 1) return 0; if (D_004A118C_0010DCC8 & 1) func_001118F8_0010DCC8(D_0042E278, b); D_003436B4_0010DCC8[0] = 100; r = func_0010DD80(a, c); if (r < 0) return r; if ((unsigned)(b - 6) < 58) D_004A11D8_0010DCC8 = b; else D_004A11D8_0010DCC8 = -1; return r; }

extern char D_0042EC08[], D_0042EC18[], D_004DDE00[]; extern int D_004A6BB0, D_004A6B9C; void func_001118F8_0010FE28(char *, ...) __asm__("func_001118F8"); int func_00196FF8_0010FE28(void) __asm__("func_00196FF8"); void func_002DD4CC_0010FE28(char *, char *) __asm__("func_002DD4CC");
// MATCH func_0010FE28
int FUN_0010fe28(char *name, int v) { func_001118F8_0010FE28(D_0042EC08, name); while (func_00196FF8_0010FE28() != 0) func_001118F8_0010FE28(D_0042EC18, D_004DDE00, name); func_002DD4CC_0010FE28(D_004DDE00, name); D_004A6BB0 = v; D_004A6B9C = 0; return 1; }

extern int D_004A6B9C_0010FDD8 __asm__("D_004A6B9C"), D_004A12A4_0010FDD8 __asm__("D_004A12A4"), D_004A6BCC; void func_002C02A0(int);
// MATCH func_0010FDD8
int FUN_0010fdd8(void) { if (D_004A6B9C_0010FDD8 < 0) { if ((D_004A12A4_0010FDD8 ^ 1) & 1) func_002C02A0(0); return 0; } if (D_004A6BCC != 0) D_004A6BCC = 0; return 1; }

extern int D_004A14D4;
// MATCH func_0010F2F0
int FUN_0010f2f0(int a) { D_004A14D4 = *(volatile int *)0x10000000; __asm__ volatile("sync"); __asm__ volatile(".word 0x42000038"); return a; }

extern volatile unsigned D_004A6BB8_0010F268 __asm__("D_004A6BB8"); extern int D_004A6BD8; extern volatile int D_004A6BCC_0010F268 __asm__("D_004A6BCC"); extern volatile int D_004A1210; extern volatile int D_004A1558; extern volatile int D_004A120C;
void func_002E58D0(int); void func_002E5840(int);
// MATCH func_0010F268
int FUN_0010f268(int a) { D_004A6BB8_0010F268 = D_004A6BB8_0010F268 + 1; if (D_004A6BB8_0010F268 > 0xfffffff) { D_004A6BD8 = 0; D_004A6BB8_0010F268 = 1; } D_004A6BCC_0010F268 = 1; if (D_004A1210 > 0) { func_002E58D0(D_004A1558); func_002E5840(D_004A1210); } (void)D_004A120C; __asm__ volatile("sync"); __asm__ volatile(".word 0x42000038"); return a; }

extern int D_004A13EC_10FF28 __asm__("D_004A13EC"); extern float D_0049FC80_10FF28 __asm__("D_0049FC80"), D_0049FC84_10FF28 __asm__("D_0049FC84");
void func_0018E438_10FF28(int,float,float,float,float,float,float,float,float,float) __asm__("func_0018E438");
// MATCH func_0010FF28
void FUN_0010ff28(int a) { D_004A13EC_10FF28 = a; func_0018E438_10FF28(0x70003bc0,(float)a,1.0f,D_0049FC84_10FF28,2048.0f,2048.0f,1.0f,D_0049FC80_10FF28,64.0f,D_0049FC80_10FF28); }

extern int D_004A13EC_0010FF88 __asm__("D_004A13EC"), D_004A6BE4_10FF88 __asm__("D_004A6BE4"), D_004A6BE8_10FF88 __asm__("D_004A6BE8"); extern float D_0049FC88_10FF88 __asm__("D_0049FC88"), D_0049FC8C_10FF88 __asm__("D_0049FC8C");
void func_0018E438_0010FF88(int, float, float, float, float, float, float, float, float, float) __asm__("func_0018E438");
// MATCH func_0010FF88
void FUN_0010ff88(int a, int b) { D_004A6BE4_10FF88 = a; D_004A6BE8_10FF88 = b; func_0018E438_0010FF88(0x70003bc0, (float)D_004A13EC_0010FF88, 1.0f, D_0049FC8C_10FF88, (float)a + 1728.0f, (float)b + 1936.0f, 1.0f, D_0049FC88_10FF88, 64.0f, D_0049FC88_10FF88); }

extern int D_004A13EC_00110008 __asm__("D_004A13EC"), D_004A6BE4_00110008 __asm__("D_004A6BE4"), D_004A6BE8_00110008 __asm__("D_004A6BE8"); extern float D_0049FC90_110008 __asm__("D_0049FC90"), D_0049FC94_110008 __asm__("D_0049FC94");
void func_0018E438_00110008(int, float, float, float, float, float, float, float, float, float) __asm__("func_0018E438");
// MATCH func_00110008
void FUN_00110008(void) { func_0018E438_00110008(0x70003bc0, (float)D_004A13EC_00110008, 1.0f, D_0049FC94_110008, (float)D_004A6BE4_00110008 + 1728.0f, (float)D_004A6BE8_00110008 + 1936.0f, 1.0f, D_0049FC90_110008, 64.0f, D_0049FC90_110008); }

extern char D_0042ED98_111400[] __asm__("D_0042ED98"), D_0042EDA8_111400[] __asm__("D_0042EDA8"), D_0042EDB8_111400[] __asm__("D_0042EDB8"); extern int D_004A6BFC_111400 __asm__("D_004A6BFC"), D_004A6BF8_111400 __asm__("D_004A6BF8"), D_004A6BB8_111400 __asm__("D_004A6BB8");
#define R(a) (*(volatile unsigned *)(a))
int func_001118F8_111400(void *, ...) __asm__("func_001118F8");
// MATCH func_00111400
int SyncCheck(int p) { int a, b; func_001118F8_111400(D_0042ED98_111400); a = R(0x10000000) - D_004A6BFC_111400; func_001118F8_111400(D_0042EDA8_111400); b = D_004A6BB8_111400 - D_004A6BF8_111400 - 1; func_001118F8_111400(D_0042EDB8_111400); if (p == 0) { R(0x10000010) = 0x9f; D_004A6BFC_111400 = R(0x10000000); D_004A6BF8_111400 = D_004A6BB8_111400; } return b * 1000 + a; }
