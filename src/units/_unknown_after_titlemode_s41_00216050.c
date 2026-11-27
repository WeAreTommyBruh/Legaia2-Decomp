#include "../common.h"
typedef struct { int a, b; } P;
extern P D_003C3018[]; extern int D_004A12A4, D_004A4ABC; extern int D_00425510[];
void clas_min_002a43e8(int, int);
// MATCH func_00216050
void FUN_00216050(void) { D_004A12A4 = 14; D_00425510[2] |= 0x80000; { int k = D_004A4ABC % 3; clas_min_002a43e8(D_003C3018[k].a, D_003C3018[k].b); } D_004A4ABC++; }
