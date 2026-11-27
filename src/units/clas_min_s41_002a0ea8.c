// cflags: -fexceptions
#include "../common.h"
typedef struct { char p[20]; int w20; } A;
typedef struct { char p[184]; int w184; short s188; short s190; char p2[12]; short s204; short s206; char p3[168]; short s376; short s378; char p4[16]; int w396; int w400; int w404; int w408; } B;
extern int D_002F9804[]; extern char D_004213D0[]; extern int D_00424A08[]; extern char D_0049AC68[];
B *func_00246D88(char *, int); int func_001118F8(char *);
// MATCH func_002A0EA8
void clas_min_002a0ea8(A *a) {
  B *b;
  if (a->w20 != -1) {
    b = func_00246D88(D_004213D0, D_002F9804[0]);
    if (b != 0) {
      b->s376 = 0; b->s378 = 0;
      b->s204 = D_00424A08[0]; b->s206 = D_00424A08[1]; b->s188 = D_00424A08[2]; b->s190 = D_00424A08[3];
      b->w396 = 100; b->w400 = 100; b->w404 = 0; b->w408 = 0; b->w184 = -1;
    } else func_001118F8(D_0049AC68);
  }
}
