/* Functions of this report unit, matched by hand. */
#include "../common.h"

// MATCH func_0022D750
int FUN_0022d750(int *b, int i) { unsigned char *e = (unsigned char *)b + b[i + 1]; int v = *(unsigned short *)(e + 2); if (((e[1] ^ 1) & 1) != 0) return v; return (v >> 1) + 1; }
