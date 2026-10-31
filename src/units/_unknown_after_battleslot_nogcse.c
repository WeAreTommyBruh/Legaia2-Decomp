/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern int D_004A681C_002983B8 __asm__("D_004A681C"); void func_00269FC8(int);
// MATCH func_002983B8
void FUN_002983b8(void) { if (D_004A681C_002983B8 != 0) { D_004A681C_002983B8 = D_004A681C_002983B8 + 1; if (D_004A681C_002983B8 == 2) func_00269FC8(2); if (D_004A681C_002983B8 >= 10) D_004A681C_002983B8 = 0; } }

extern int D_004A681C_00298400 __asm__("D_004A681C"); void func_00269FC8(int);
// MATCH func_00298400
void FUN_00298400(void) { if (D_004A681C_00298400 != 0) { D_004A681C_00298400 = D_004A681C_00298400 + 1; if (D_004A681C_00298400 == 2) func_00269FC8(3); if (D_004A681C_00298400 >= 10) D_004A681C_00298400 = 0; } }

extern int D_004A681C_00298448 __asm__("D_004A681C"); void func_00269FC8(int);
// MATCH func_00298448
void FUN_00298448(void) { if (D_004A681C_00298448 != 0) { D_004A681C_00298448 = D_004A681C_00298448 + 1; if (D_004A681C_00298448 == 2) func_00269FC8(4); if (D_004A681C_00298448 >= 10) D_004A681C_00298448 = 0; } }

typedef struct { char c[608]; } T608_0029B908;
extern T608_0029B908 D_005F9640[]; extern int D_004A69A8; void func_002A0BA0(void *);
// MATCH func_0029B908
void FUN_0029b908(int *o, int b, int a) { int i; o[0] = a; o[1] = b; o[3] = 0; o[2] = 0; ((short *)o)[10] = 0; for (i = 3; i < D_004A69A8; i++) func_002A0BA0(&D_005F9640[i]); }
