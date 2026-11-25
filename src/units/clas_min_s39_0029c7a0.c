// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"
typedef struct { int key; char p[108]; } E_0029C7A0;
extern E_0029C7A0 D_0061F640[];
extern int D_004A697C;
// MATCH func_0029C7A0
E_0029C7A0 *clas_min_0029c7a0(int key) { int i; for (i = 0; i < D_004A697C; i++) if (key == D_0061F640[i].key) break; if (i < D_004A697C) return &D_0061F640[i]; return &D_0061F640[0]; }
