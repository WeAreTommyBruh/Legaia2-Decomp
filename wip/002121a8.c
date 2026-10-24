// cflags: -O1
#include "../src/common.h"
// 3 words differ
// WIP func_002121A8
char *pchse_002121a8(int a, char **pp) { char *p = *pp; if (*p != 0) { while (1) { char *q = p; p = q + 1; *pp = p; if (q[1] == 0) break; } } return *pp; }
