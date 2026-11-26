#include "../common.h"
typedef struct { int w0, w4, id; char p[68]; } E80; extern E80 D_003EC550[];
extern int D_005F7E70[];
// MATCH func_0025A3F0
int *FUN_0025a3f0(int id) { unsigned i; int n; int m = -1; for (i = 15; (int)i >= 0; i--) D_005F7E70[i] = m; n = 0; for (i = 0; i < 861; i++) if (D_003EC550[i].id == id) D_005F7E70[n++] = i; return D_005F7E70; }
