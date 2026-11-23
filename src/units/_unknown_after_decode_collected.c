/* Matched functions from this unit. */
#include "../ghidra.h"

typedef struct { int a, b, c; int busy; } T;
extern volatile T D_00321300;
void func_00191EF0(char *); void func_001948F0(volatile T *); void func_00192730(char *); void func_00192950(char *, int);
// MATCH func_00192B10
void FUN_00192b10(char *o) { func_00191EF0(o + 72); func_001948F0(&D_00321300); func_00192730(o); while (D_00321300.busy != 0); func_00192950(o, 3); }
