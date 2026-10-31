/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A140C, D_004A253C;
// MATCH func_0013D5D8
void FUN_0013d5d8(int a) { if (a != 0 && (D_004A140C & 0x200) != 0) D_004A253C++; }

extern int D_004A140C_0013D320 __asm__("D_004A140C"), D_004A2534; extern int D_00419D18_0013D320[] __asm__("D_00419D18");
// MATCH func_0013D320
int FUN_0013d320(int a) { if (a != 0 && (D_004A140C_0013D320 & 0x200)) {
D_00419D18_0013D320[26] = 255;
D_00419D18_0013D320[70] = 255;
D_00419D18_0013D320[114] = 255;
D_004A2534 = D_004A2534 + 1;
} }

extern int D_004A2A38, D_004A2A3C, D_004A2A40, D_004A3860; extern char D_00343010_0013F2E8[] __asm__("D_00343010"); extern int D_003323B0[]; int func_001E3A00(char *, int *, int, int);
// MATCH func_0013F2E8
int FUN_0013f2e8(void) { int loc; loc = 0; if (D_004A2A38 >= 0) { int r; D_004A3860 = D_004A2A3C; r = func_001E3A00(D_00343010_0013F2E8, &loc, D_004A2A40, 0); D_004A3860 = 1; D_003323B0[D_004A2A38] = r; } else loc = 1; return loc; }

typedef struct { char p[34]; short h; } T36_0013C220;
extern T36_0013C220 D_0041C600[]; extern int D_004A66E0, D_004A66E4, D_004A66E8;
extern float D_0041C540[], D_0041C550[], D_0041C5A0[], D_0041C5B0[], D_004028D0[], D_004028E0[];
// MATCH func_0013C220
void FUN_0013c220(void) { int i; for (i = 0; i < 32; i++) D_0041C600[i].h = 0; if (D_004A66E0 != 0) { D_0041C5A0[0] = D_004028D0[0] = D_0041C540[0]; D_0041C5A0[1] = D_004028D0[1] = D_0041C540[1]; D_0041C5A0[2] = D_004028D0[2] = D_0041C540[2]; D_0041C5B0[0] = D_004028E0[0] = D_0041C550[0]; D_0041C5B0[1] = D_004028E0[1] = D_0041C550[1]; D_0041C5B0[2] = D_004028E0[2] = D_0041C550[2]; } D_004A66E4 = 0; D_004A66E8 = 0; D_004A66E0 = 0; }
