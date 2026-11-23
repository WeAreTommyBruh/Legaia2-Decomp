/* Matched functions from this unit. */
// compiler: 990721-r5900
#include "../ghidra.h"
#include "../common.h"

// MATCH func_00172908
int FUN_00172908(int x) { if (x < -96) return 0; if (x < -32) return 1; if (x < 32) return 2; if (x < 95) return 3; return 4; }

typedef struct { char p0[84]; int w84, w88, w92, w96; float f100, f104; char p108[16]; int w124; char p128[8]; int w136, w140, w144, w148; int a[13]; int b[13]; int c[13]; char p308x[0]; } O_172AA0;
int func_00172958(void); int func_00172978(void);
// MATCH func_00172AA0
void FUN_00172aa0(O_172AA0 *o)
{
  int i;
  o->w136 = func_00172958();
  o->w140 = func_00172978();
  o->w144 = 4;
  o->w148 = 4;
  for (i = 0; i < 13; i++) { o->a[i] = 0; o->b[i] = 0; o->c[i] = 0; }
o->w124 = 0; *(int *)((char *)o + 308) = 0; o->w84 = 0; o->w88 = 0; o->w92 = 0; o->w96 = 0; o->f100 = 1.0f; o->f104 = 1.0f;
}
