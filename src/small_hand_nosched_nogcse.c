/* Small functions matched by hand. */
// cflags: -fno-schedule-insns -fno-gcse
#include "common.h"

void func_00245F98(void *, int); void func_00108B80(void *);
// MATCH func_00111C00
void FUN_00111c00(char *s, int fl) { char *arr = s + 1056; if (arr != 0) { char *p = s + 111648; if (arr != p) { char *e = arr; do { p -= 432; func_00245F98(p, 0); } while (e != p); } } if (fl & 1) func_00108B80(s); }
