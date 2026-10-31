/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

int func_002DD36C(void *, void *);
// MATCH func_002469A0
int work_002469a0(char *o, char *key) { int n, i; if (*(int *)(o + 152) == 0) return -1; if (key == 0) return -1; n = **(int **)(o + 152); for (i = 0; i < n; i++) { char *t = *(char **)(o + 152); if (func_002DD36C(key, t + ((int *)t)[i + 1] + 8) == 0) return i; } return -1; }
