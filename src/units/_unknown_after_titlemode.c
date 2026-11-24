/* Functions of this report unit, matched by hand. */
#include "../common.h"
#include "../ghidra.h"

extern long long D_004A12D8; typedef struct { char p[8]; int w; } O_00215A28;
// MATCH func_00215A28
int FUN_00215a28(O_00215A28 *o) { if (D_004A12D8 & 0x200840) o->w = 0; return 1; }

extern long long D_004A12D8; typedef struct { char p[4]; int *a; int w; } O_00215A48; extern int D_003C2F80[];
// MATCH func_00215A48
int FUN_00215a48(O_00215A48 *o) { if (D_004A12D8 & 0x800) { int *p = D_003C2F80; o->a = p; o->w = p[1]; } return 1; }

extern int D_004A1510, D_004A12A4, D_004A4ABC; extern char D_004A4AD8[]; void func_002144F0(void); void func_002A43E8(void *, int);
// MATCH func_00216010
void FUN_00216010(void) { func_002144F0(); D_004A1510 = 1; D_004A12A4 = 14; D_004A4ABC = 0; func_002A43E8(D_004A4AD8, 0); }

extern char D_003C2E20[]; int func_001B4738_002159D8(int, int, int, int) __asm__("func_001B4738");
// MATCH func_002159D8
int FUN_002159d8(int *o) { if (func_001B4738_002159D8(6, 1, 1, 1) == 0) { int *t = (int *)D_003C2E20; int v = t[1]; o[1] = (int)t; o[2] = v; } return 1; }

extern int D_004A4AA4; extern char D_00455938[], D_00455928[]; void func_001118F8_00215DC0(char *, ...) __asm__("func_001118F8"); int func_001114C0(void); int func_001114B0(void); void func_001114B8(int); void func_00113EC8(char *);
// MATCH func_00215DC0
int FUN_00215dc0(int *o) { int r; o[7] = 0; func_001118F8_00215DC0(D_00455938, D_00455928); if (func_001114C0()) { r = func_001114B0(); func_001114B8(1); func_00113EC8(D_00455928); func_001114B8(r); } else func_00113EC8(D_00455928); o[2] = 0; D_004A4AA4 = 1; return 1; }

// MATCH func_00216428
void FUN_00216428(int *o, int a, int b, int c, int d, int e) { float *f = (float *)o; o[6] = e; o[7] = 0; if (e == 0) { o[7] = 1; o[6] = 1; } f[8] = f[10] = (float)a; f[9] = f[11] = (float)b; f[12] = (float)c; f[13] = (float)d; }

extern char D_003C2B60[], D_003C2B50[], D_003C2B10[], D_003C2B20[];
void func_00214A68(void *, int, int, int);
// MATCH func_002151D0
void FUN_002151d0(char *p) { int a, k, d; *(int *)(p + 12) = 0x80787878; func_00214A68(p, **(int **)(p + 4), 0, 0); func_00214A68(p, (int)D_003C2B60, 0, 0); func_00214A68(p, (int)D_003C2B50, 0, 0); func_00214A68(p, (int)D_003C2B10, 0, 0); a = (*(int *)(*(int *)(p + 4) + 4) << 1) / 3; if (*(int *)(p + 8) <= a) return; k = 0x20; if (*(int *)(p + 0x20) == 2) k = 0x78; *(int *)(p + 12) = k; d = *(int *)(*(int *)(p + 4) + 4) - a; *(unsigned *)(p + 12) = ((unsigned)(k * (*(int *)(p + 8) - a)) / (unsigned)d << 24) | 0x787878; func_00214A68(p, (int)D_003C2B20, 0, 0); }

extern char D_003C2B60_00215478[] __asm__("D_003C2B60"); extern char D_003C2B50_00215478[] __asm__("D_003C2B50"); void func_00214A68_00215478(int *, int, int, int) __asm__("func_00214A68");
// MATCH func_00215478
void FUN_00215478(int *o) { int d; int *p; int new_var; int u; p = (int *) o[1]; d = p[1]; new_var = (o[2] * 0x78) / d; u = p[0]; o[3] = ((0x78 - new_var) * 0x1000000) | 0x787878; func_00214A68_00215478(o, u, 0, 0); func_00214A68_00215478(o, (int) D_003C2B60_00215478, 0, 0); func_00214A68_00215478(o, (long) ((int) D_003C2B50_00215478), 0, 0); }

extern char D_003C2B60_00215510[] __asm__("D_003C2B60"); extern char D_003C2B50_00215510[] __asm__("D_003C2B50"); void func_00214A68_00215510(int *, int, int, int) __asm__("func_00214A68");
// MATCH func_00215510
void FUN_00215510(int *o) { int d; int *p; int nv; int u; p = (int *) o[1]; d = p[1]; nv = (o[2] * 0x78) / d; u = p[0]; o[3] = (nv << 24) | 0x787878; func_00214A68_00215510(o, u, 0, 0); func_00214A68_00215510(o, (int) D_003C2B60_00215510, 0, 0); func_00214A68_00215510(o, (long) ((int) D_003C2B50_00215510), 0, 0); }

extern char D_003C2B60_002152F8[] __asm__("D_003C2B60"); extern char D_003C2B50_002152F8[] __asm__("D_003C2B50"); extern char D_003C2B10_002152F8[] __asm__("D_003C2B10"); void func_00214A68_002152F8(int *, int, int, int) __asm__("func_00214A68");
// MATCH func_002152F8
void FUN_002152f8(int *o) { int d; int *p; int nv; int u; p = (int *) o[1]; d = p[1]; nv = (o[2] * 0x78) / d; u = p[0]; o[3] = (nv << 24) | 0x787878; func_00214A68_002152F8(o, u, 0, 0); func_00214A68_002152F8(o, (int) D_003C2B60_002152F8, 0, 0); func_00214A68_002152F8(o, (int) D_003C2B50_002152F8, 0, 0); func_00214A68_002152F8(o, (long) ((int) D_003C2B10_002152F8), 0, 0); }

extern char D_003C2B60_002156B8[] __asm__("D_003C2B60"); extern char D_003C2B50_002156B8[] __asm__("D_003C2B50"); extern char D_003C2B20_002156B8[] __asm__("D_003C2B20"); void func_00214A68_002156B8(int *, int, int, int) __asm__("func_00214A68");
// MATCH func_002156B8
void FUN_002156b8(int *o) { int d; int *p; int nv; int u; p = (int *) o[1]; d = p[1]; nv = (o[2] * 0x78) / d; u = p[0]; o[3] = (nv << 24) | 0x787878; func_00214A68_002156B8(o, u, 0, 0); func_00214A68_002156B8(o, (int) D_003C2B60_002156B8, 0, 0); func_00214A68_002156B8(o, (int) D_003C2B50_002156B8, 0, 0); func_00214A68_002156B8(o, (long) ((int) D_003C2B20_002156B8), 0, 0); }

void func_00214A68_00215768(int *, int, int, int) __asm__("func_00214A68"); void func_00214680(int *);
// MATCH func_00215768
void FUN_00215768(int *o) { int d; int *p; int nv; int u; unsigned w; p = (int *) o[1]; d = p[1]; nv = (o[2] * 0x78) / d; u = p[0]; w = 0x78 - nv; o[3] = w | (w * 0x100) | (w * 0x10000) | 0x80000000; func_00214A68_00215768(o, u, 0, 0); func_00214680(o); }

extern char D_003C2B60_002155A8[] __asm__("D_003C2B60"); extern char D_003C2B50_002155A8[] __asm__("D_003C2B50"); extern char D_003C2B20_002155A8[] __asm__("D_003C2B20"); extern char D_003C2B10_002155A8[] __asm__("D_003C2B10"); void func_00214A68_002155A8(int *, int, int, int) __asm__("func_00214A68");
// MATCH func_002155A8
void FUN_002155a8(int *o) { int i1; int i2; int nv; int new_var; o[3] = 0x80787878; func_00214A68_002155A8(o, *((int *) o[1]), 0, 0); func_00214A68_002155A8(o, (int) D_003C2B60_002155A8, 0, 0); func_00214A68_002155A8(o, (int) D_003C2B50_002155A8, 0, 0); func_00214A68_002155A8(o, (long) ((int) D_003C2B20_002155A8), 0, 0); new_var = ((int *) o[1])[1]; i2 = new_var; i1 = (i2 << 1) / 3; if (o[2] <= i1) { return; } i2 = i2 - i1; nv = ((o[2] - i1) * 0x78) / i2; o[3] = (nv << 24) | 0x787878; func_00214A68_002155A8(o, (long) ((int) D_003C2B10_002155A8), 0, 0); }

void func_002148F0(void *);
// MATCH func_00215858
void FUN_00215858(int *o) { int p; int n; p = (int)o; n = *(int *)(*(int *)(p + 4) + 4); *(int *)(p + 0xc) = 0x20 - (*(int *)(p + 8) << 5) / n; func_002148F0(o); }

void func_00214A68(void *, int, int, int);
// MATCH func_002153C8
void FUN_002153c8(int *o) { int p; int n; int a; unsigned v; p = (int)o; n = (*(int **)(p + 4))[1]; v = 0x78 - (*(int *)(p + 8) * 0x78) / n; a = **(int **)(p + 4); *(unsigned *)(p + 0xc) = v | (v << 16 | v << 8) | 0x80000000; func_00214A68(o, a, 0, 0); }

void func_00214A68(void *, int, int, int);
// MATCH func_00215420
void FUN_00215420(int *o) { int p; int n; int a; unsigned v; p = (int)o; n = (*(int **)(p + 4))[1]; v = ((*(int *)(p + 8) - 1) * 0x78) / n; a = **(int **)(p + 4); *(unsigned *)(p + 0xc) = v | (v << 16 | v << 8) | 0x80000000; func_00214A68(o, a, 0, 0); }

void func_002147B8_002157E0(int *) __asm__("func_002147B8"); void func_00214A68_002157E0(int *, int, int, int) __asm__("func_00214A68");
// MATCH func_002157E0
void FUN_002157e0(int *o) { int d; int *p; int nv; register int u __asm__("$5"); unsigned w; p = (int *) o[1]; d = p[1]; nv = (o[2] * 0x78) / d; u = p[0]; w = nv; o[3] = w | (w * 0x100) | (w * 0x10000) | 0x80000000; func_00214A68_002157E0(o, u, 0, 0); func_002147B8_002157E0(o); }

typedef struct { char p[0x2c]; float a; float b; } S;
// MATCH func_00215F38
void FUN_00215f38(S *s, int n)
{
  float t;
  if (n == 0) { *(int *)&s->b = 0; return; }
 t = 0.0f; if (n > 0) t = 1.0f; n = n >= 0 ? n : -n; s->b = (t - s->a) / (float)n;
}

typedef struct { int a0; void ***a4; int a8; int a12; } S_2153a8_002153A8;
void func_00214A68_2153A8() __asm__("func_00214A68");
// MATCH func_002153A8
void FUN_002153a8(S_2153a8_002153A8 *s) { void ***t = s->a4; s->a12 = 0x80787878; func_00214A68_2153A8(s, *t, 0, 0); }


typedef struct { char p[16]; unsigned long *w16; } S_002148F0;
typedef struct { int w[32]; } B_002148F0;
typedef struct { char p[12]; unsigned w12; } O_002148F0;
extern S_002148F0 D_00342CD0_2148F0 __asm__("D_00342CD0"); extern int D_004A12B0_2148F0 __asm__("D_004A12B0");
void func_002A4F30_2148F0(B_002148F0 *) __asm__("func_002A4F30"); void func_001808B8_2148F0(B_002148F0 *) __asm__("func_001808B8"); void func_002A58F8_2148F0(B_002148F0 *, int, int, int, int, int, int) __asm__("func_002A58F8"); void func_002A53B0_2148F0(B_002148F0 *, int, int, int) __asm__("func_002A53B0"); void func_001808B0_2148F0(B_002148F0 *) __asm__("func_001808B0");
// MATCH func_002148F0
void FUN_002148f0(O_002148F0 *o) { B_002148F0 s; unsigned long *p; int one = 1; int x, y; unsigned long h; func_002A4F30_2148F0(&s); s.w[28] = 0; func_001808B8_2148F0(&s); { int b = D_004A12B0_2148F0 & 1; s.w[29] = one; y = b ? 0 : 2240; x = b ? 2240 : 0; } s.w[21] = x; s.w[22] = y; func_002A58F8_2148F0(&s, 0, 0, 0, 0, 640, 224); s.w[25] = 48; s.w[17] = 0x27f0; s.w[18] = 0xdf0; s.w[10] = 0x6bc0; s.w[11] = 0x78c0; s.w[12] = 0x2870; s.w[13] = 0xe70; s.w[15] = 0; s.w[16] = 0; func_002A53B0_2148F0(&s, 128, 128, 128); h = (unsigned long)o->w12 << 32 | 100; p = D_00342CD0_2148F0.w16; D_00342CD0_2148F0.w16 = p + 10; p[0] = h; p[1] = 66; p[2] = 70; p[4] = 0x3f80000080000000UL; p[5] = 1; p[6] = 0xffffff00000000UL; p[7] = 5; p[8] = 0xfffffffff0fff0UL; p[9] = 5; p[3] = 0; func_001808B0_2148F0(&s); s.w[28] = one; }



extern int D_004A4AB8_215FB0 __asm__("D_004A4AB8"), D_004A6F7C_215FB0 __asm__("D_004A6F7C"); extern char D_00455948_215FB0[] __asm__("D_00455948"); int func_002143F0_215FB0() __asm__("func_002143F0"); void func_001118F8_215FB0(char *, ...) __asm__("func_001118F8"); void func_001897C8_215FB0(void) __asm__("func_001897C8"); void func_002141B0_215FB0(int, int) __asm__("func_002141B0");
// MATCH func_00215FB0
int FUN_00215fb0(void) { int r; int p; if (func_002143F0_215FB0(D_004A4AB8_215FB0) != 0) return 0; func_001118F8_215FB0(D_00455948_215FB0); func_001897C8_215FB0(); p = D_004A4AB8_215FB0; D_004A6F7C_215FB0 = 0; r = ((int *)p)[7]; if (p != 0) func_002141B0_215FB0(p, 3); { register int v asm("$2") = r; __asm__ volatile("" :: "r"(v)); D_004A4AB8_215FB0 = 0; return v; } }
