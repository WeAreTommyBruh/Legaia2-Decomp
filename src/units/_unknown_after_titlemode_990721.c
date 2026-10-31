/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

extern char D_002F7140[];
void func_00101330(char *); int func_001015E0(char *);
// MATCH func_00215B98
int FUN_00215b98(int *o) { if (o[2] > 200) func_00101330(D_002F7140); o[2] = 100; if (func_001015E0(D_002F7140) == 0) o[2] = 0; return 1; }

