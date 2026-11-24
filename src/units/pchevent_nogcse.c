/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern volatile int D_004A1444, D_004A140C; extern char D_00455020[], D_00455030[]; int func_00211A20(void); int func_00211A58(int); int func_001118F8(char *, ...);
// MATCH func_0020C920
void pchevent_0020c920(int on) { int i, n; if (on) { if (D_004A1444 == 0 && (D_004A140C & 8)) { if (func_00211A20() < 10) n = func_00211A20(); else n = 10; i = 0; func_001118F8(D_00455020, func_00211A20()); for (i = 0; i < n; i++) func_001118F8(D_00455030, i, func_00211A58(i)); } } }

typedef struct { char p[208]; float f208; } S_0020C430;
extern S_0020C430 D_0041EFB0; extern float D_004A6F74;
// MATCH func_0020C430
int pchevent_0020c430(void) { float d = (D_004A6F74 - D_0041EFB0.f208) * 0.5f; float q = d * d; if (d < 0) q = -q; D_004A6F74 = D_0041EFB0.f208 + q; if (D_004A6F74 < 0) D_004A6F74 = 0; D_0041EFB0.f208 = D_004A6F74; return 0; }

// MATCH func_0020B910
void pchevent_0020b910(char *o, int from, int to) { int b; int *d; int *q; int v; int s; int t; b = *(int *)(o + 12); d = (int *)(from * 4 + b); v = *d; s = 1; if (to < from) s = -1; if (from != to) { q = (int *)(from * 4 + (s * 4 + b)); do { t = *q; from += s; q += s; *d = t; d += s; } while (from != to); } (*(int **)(o + 12))[to] = v; }


typedef struct { int a; int type; char pad[20]; } Ev_20E6B0_0020E6B0;
extern Ev_20E6B0_0020E6B0 D_003C24A0_20E6B0[] __asm__("D_003C24A0");
extern float D_003C0F20_20E6B0[] __asm__("D_003C0F20"), D_003C0F30_20E6B0[] __asm__("D_003C0F30");
extern int D_004A4648_20E6B0 __asm__("D_004A4648"), D_004A461C_20E6B0 __asm__("D_004A461C"), D_004A4654_20E6B0 __asm__("D_004A4654"), D_004A4614_20E6B0 __asm__("D_004A4614"), D_004A4618_20E6B0 __asm__("D_004A4618");
extern float D_004A044C_20E6B0 __asm__("D_004A044C");
extern int D_004A1430_20E6B0 __asm__("D_004A1430"), D_004A1434_20E6B0 __asm__("D_004A1434");
extern int D_004A4958_20E6B0[2] __asm__("D_004A4958");
extern char D_004A4900_20E6B0[] __asm__("D_004A4900");
void func_0020E458_20E6B0(int, void *, int) __asm__("func_0020E458");
void func_001E48E0_20E6B0(int, ...) __asm__("func_001E48E0");
void func_00239568_20E6B0(void *, int, int, int) __asm__("func_00239568");
// MATCH func_0020E6B0
void pchevent_0020e6b0(int p) { func_0020E458_20E6B0(p, D_003C24A0_20E6B0, 4); if (D_004A4648_20E6B0 == 4) { D_004A4648_20E6B0 = 0; switch (D_003C24A0_20E6B0[D_004A4654_20E6B0].type) { case 1: D_004A461C_20E6B0 = 1 - D_004A461C_20E6B0; break; case 2: if (D_004A4614_20E6B0 > 0 && D_004A4618_20E6B0 >= 0) { float k = D_004A044C_20E6B0; func_001E48E0_20E6B0(2, D_004A4618_20E6B0, D_003C0F20_20E6B0[0], D_003C0F20_20E6B0[1], D_003C0F20_20E6B0[2]); func_001E48E0_20E6B0(3, D_004A4618_20E6B0, D_003C0F30_20E6B0[0] * k / 180.0f, D_003C0F30_20E6B0[1] * k / 180.0f, D_003C0F30_20E6B0[2] * k / 180.0f); func_001E48E0_20E6B0(1, D_004A4618_20E6B0); } break; case 3: if (D_004A4614_20E6B0 > 0 && D_004A4618_20E6B0 >= 0) func_001E48E0_20E6B0(13, D_004A4618_20E6B0); break; } } func_00239568_20E6B0(D_004A4900_20E6B0, D_004A1430_20E6B0 + 8, D_004A1434_20E6B0 + 3, D_004A4958_20E6B0[D_004A461C_20E6B0]); }
