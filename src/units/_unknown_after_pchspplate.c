/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char c[16]; } V16_00216EB8;
void func_00126830(int, int);
// MATCH func_00216EB8
void FUN_00216eb8(char *o) { char *t; ((int *)o)[545] = 0; ((int *)o)[544] = 0; ((int *)o)[543] = 0; ((int *)o)[542] = 0; func_00126830(0, 0); t = *(char **)(o + 1792); *(V16_00216EB8 *)(t + 112) = *(V16_00216EB8 *)(o + 2128); }
