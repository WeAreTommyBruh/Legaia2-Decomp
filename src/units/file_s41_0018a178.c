#include "../common.h"
// MATCH func_0018A178
unsigned file_0018a178(char *s) { unsigned r; int sh; if (s == 0) return 0; r = 0; for (sh = 24; sh >= 0 && *s != 0; sh -= 8) r |= *s++ << sh; return r; }
