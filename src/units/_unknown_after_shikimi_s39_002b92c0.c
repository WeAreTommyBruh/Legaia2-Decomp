// compiler: 991111-01
#include "../common.h"
extern char D_0041EF80[], D_0041EF40[], D_004A6AB8[], D_005F98A0[];
int func_0029C738(void);
char *func_0015A908(char *, int, int);
int func_00160C70(char *, char *, int);
void func_002B3F10(int, char *, int *);
// MATCH func_002B92C0
void FUN_002b92c0(int *o) {
  char *t = D_0041EF80;
  char *e;
  int v;
  int buf[4];
  e = func_0015A908(t, 4, func_0029C738() + 32);
  if (e != 0) {
    v = *(short *)(e + 26);
    if (v != -1 && v != *o) {
      *o = v;
      buf[0] = 0;
      func_002B3F10(func_00160C70(D_0041EF40, D_004A6AB8, v), D_005F98A0, buf);
    }
  }
}
