/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

extern char D_00341288[];
extern char D_003412F8[];
extern char D_0043F6E8[];
extern int D_002F9804[];
void func_00187028(void *);
void func_00186F40(void *, void *, int, int);
char *func_00246CE0(int, void (*)(void), void (*)(void), int);
void func_00189078(void);
void func_001890A0(void);
// MATCH func_00189128
void srivus_00189128(char *o)
{
  char *r;
  int f;
  func_00187028(o);
  func_00186F40(o, D_00341288, 40, 43);
  if ((*((int *) (o + 1780))) == 42)
  {
    f = D_002F9804[0];
    *((char **) (o + 1224)) = D_0043F6E8;
    r = func_00246CE0(f, func_00189078, func_001890A0, 0);
    f = *((int *) (r + 192));
    *((char **) (o + 1036)) = r;
    *((char **) (o + 1040)) = D_003412F8;
    *((char **) (r + 412)) = (0, D_003412F8);
    *((int *) (r + 192)) = f | 2;
  }
}

