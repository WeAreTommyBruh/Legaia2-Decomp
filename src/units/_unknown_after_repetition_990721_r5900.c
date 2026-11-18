/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

typedef struct { char c[8]; } V8_1779C8;
typedef struct { char p0[384]; int w384; char p388[12]; float f400, f404; char p408[40]; int w448; char p452[4]; char m456[8]; int w464, w468, w472; char v476[8]; } O_1779C8;
extern float D_004A00C8; extern V8_1779C8 D_004A3330[3]; extern char D_0043E150[], D_0043E168[];
void func_00177568(char *); int func_001644A0(char *); void func_002971C0(int, int); int func_0018B3A8(char *, int); void func_001118F8(char *, ...); void func_00177CA8(O_1779C8 *, int, int, int, int);
// MATCH func_001779C8
O_1779C8 *FUN_001779c8(O_1779C8 *o, int a, int b, int c, int d, int e, int f) {
  int k; char *p = (char *)o;
  for (k = 3; k != -1; k--) { func_00177568(p); p += 96; }
  o->w384 = e;
  o->w448 = 0;
  o->f400 = (float)f;
  o->f404 = D_004A00C8 / (float)f;
  func_001644A0(o->m456);
  *(V8_1779C8 *)o->v476 = D_004A3330[0];
  func_002971C0(0, 0);
  o->w468 = 0;
  o->w472 = 0;
  if ((o->w464 = func_0018B3A8(D_0043E150, 0)) == 0) func_001118F8(D_0043E168);
  func_00177CA8(o, a, b, c, d);
  return o;
}
