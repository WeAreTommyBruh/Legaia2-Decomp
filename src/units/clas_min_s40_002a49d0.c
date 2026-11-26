#include "../common.h"
typedef struct { int a, b, c, d; } DD; typedef struct { char p[6372]; signed char a, b, c, d; } SS;
extern SS D_003FEBA8; extern DD D_00314D08; void func_002A45C8();
#define D D_00314D08
#define S D_003FEBA8
// MATCH func_002A49D0
void clas_min_002a49d0(void) { int t[4]; func_002A45C8(t); { D.a = S.a;   D.b = S.b;   D.c = S.c;   D.d = S.d; } }
