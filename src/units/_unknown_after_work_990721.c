/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

typedef struct { float m[4][4]; } M_2491D8;
extern int D_004A565C, D_004A5658, D_004A14B8; extern char D_0045D790[]; extern signed char D_003DC570[]; extern M_2491D8 D_003DA170[];
void func_001118F8(char *, ...); void func_0018EB98(int, M_2491D8 *);
// MATCH func_002491D8
void FUN_002491d8(void) {
  if (D_004A565C < 0) { func_001118F8(D_0045D790); D_004A565C = 0; D_004A5658 = 0; }
  if ((D_004A14B8 = D_003DC570[--D_004A5658]) != 0) func_0018EB98(0x70003d80, &D_003DA170[--D_004A565C]);
  func_0018EB98(0x70003c80, &D_003DA170[--D_004A565C]);
  func_0018EB98(0x70003f80, &D_003DA170[--D_004A565C]);
}

extern int D_004A7210_24A058 __asm__("D_004A7210"), D_004A720C_24A058 __asm__("D_004A720C"); extern char D_005F7700_24A058[] __asm__("D_005F7700"), D_005F7740_24A058[] __asm__("D_005F7740"); extern int D_005F77C0_24A058[] __asm__("D_005F77C0");
int func_002E8928_24A058(char *, int, int, char *, int, int *, int, int, int) __asm__("func_002E8928"); int func_002E8B18_24A058(char *) __asm__("func_002E8B18");
// MATCH func_0024A058
int FUN_0024a058(int *o) { int *p; int i; if (D_004A7210_24A058 == 0 || D_004A720C_24A058 == 0) return 0; func_002E8928_24A058(D_005F7700_24A058, 2, 1, D_005F7740_24A058, 128, D_005F77C0_24A058, 128, 0, 0); while (func_002E8B18_24A058(D_005F7700_24A058) != 0); p = D_005F77C0_24A058; o[0] = *p++; o[1] = *p++; o[2] = *p++; o[3] = *p++; o[4] = *p++; o[5] = *p; return 0; }

