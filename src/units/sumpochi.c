/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char D_00455CE0_2174E0[] __asm__("D_00455CE0");
void *func_00162130_2174E0(int, char *, int) __asm__("func_00162130"); int *func_00216BC8_2174E0(void *, int, int, int, int) __asm__("func_00216BC8");
// MATCH func_002174E0
void sumpochi_002174e0(char *o, int a, int b, int c, int d) { int *n, *h, *prev; n = func_00216BC8_2174E0(func_00162130_2174E0(24, D_00455CE0_2174E0, 421), a, b, c, d); if (n != 0) { h = *(int **)(o + 2156); if (h == 0) { *(int **)(o + 2156) = n; } else { prev = 0; while (h != 0) { if (h[2] == n[2] && h[3] == n[3] && h[4] == n[4] && h[5] == n[5]) break; prev = h; h = (int *)h[1]; } if (h != 0) return; prev[1] = (int)n; n[0] = (int)prev; } } }

