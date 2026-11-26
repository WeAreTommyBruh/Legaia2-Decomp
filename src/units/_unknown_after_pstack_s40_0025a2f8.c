// compiler: 990721-r5900
#include "../common.h"
typedef struct { int w0, w4, v; char p[68]; } E80; extern E80 D_003EC550[];
// MATCH func_0025A2F8
void FUN_0025a2f8(void) { unsigned i, k; int j; for (i = 0; i < 861; i++) for (j = 0; j < 15; j++) __asm__ volatile("" : : "r"(j)); for (i = 0; i < 861; i++) { if (D_003EC550[i].v < 700) { for (k = i + 1; k < 861; k++) for (j = 0; j < 16; j++) ; } } }
