/* Functions of this report unit, matched by hand. */
#include "../common.h"

int func_002CEA48(void *);
// MATCH func_00100680
void FUN_00100680(int *a, void *b) { *a = func_002CEA48(b); }

void func_00108B80(void);
// MATCH func_001006F0
void FUN_001006f0(int a, int b) { if (b & 1) func_00108B80(); }
