/* Functions of this report unit, matched by hand. */
// cflags: -O1
#include "../common.h"


// MATCH func_002121A8
char *pchse_002121a8(int a, char **pp) { char *p = *pp; if (*p) { char *q; do { if (q) { q = p; p = q + 1; *pp = p; } else { q = p; p = q + 1; *pp = p; } } while (q[1] != 0); } return *pp; }

