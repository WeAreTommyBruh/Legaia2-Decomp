/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { char p[4832]; int w4832; char p2[316]; char b5152[32]; } O_0021B018;
// MATCH func_0021B018
void FUN_0021b018(O_0021B018 *o) { int i; for (i = 0; i < o->w4832; i++) o->b5152[i] = 1; for (i = o->w4832; i < 32; i++) o->b5152[i] = 0; }
