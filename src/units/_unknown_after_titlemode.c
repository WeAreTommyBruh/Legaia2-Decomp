/* Functions of this report unit, matched by hand. */
#include "../common.h"

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
