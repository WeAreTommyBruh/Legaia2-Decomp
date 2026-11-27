#include "../common.h"
// MATCH func_00212968
int FUN_00212968(int o, int **a, int **b, int *c, int n) { int *p = *(int **)(o + 8); int i = 0; *c = -1; if (p == 0) goto fail; if (n != 0) { do { p = (int *)*p; if (p == 0) goto fail; i++; } while (i != n); } if (p == 0) { fail: return 0; } *a = p + 5; *b = p + 37; *c = p[3]; return 1; }
