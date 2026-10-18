// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../src/common.h"
typedef struct { char c[8]; } V8;
typedef struct { char pad[412]; V8 v; } O;
extern V8 D_00402450[];
// WIP func_25F778
void abeshi_0025f778(O *o, unsigned i)
{
  if (i >= 4) i = 0;
  o->v = D_00402450[i];
}
