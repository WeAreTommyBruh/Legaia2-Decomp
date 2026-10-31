/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern char *D_004A1A20; extern char D_00431C68[]; void func_001118F8_0012D248(char *, ...) __asm__("func_001118F8");
// MATCH func_0012D248
void FUN_0012d248(void) { int i, off = 0; for (i = 0; i < 20; i++) { char *e = (char *)(off + (int)D_004A1A20); int *p, *q; off += 5472; p = *(int **)(e + 5424); if (p) { *(int *)(e + 5364) = p[17]; func_001118F8_0012D248(D_00431C68, i, p[17]); } else { q = *(int **)(e + 5380); if (q) *(int *)(e + 5364) = q[17]; } } }
