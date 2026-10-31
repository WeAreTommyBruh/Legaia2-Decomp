/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char pad[224]; char a[1]; char pad1[19]; char b[1]; char pad2[19]; char c[1]; } S_0022BF30;
void func_0029D010_0022BF30(void *, int, int, float) __asm__("func_0029D010");
// MATCH func_0022BF30
void FUN_0022bf30(S_0022BF30 *s, float *v) { func_0029D010_0022BF30(s->a, 0, 0, v[0]); func_0029D010_0022BF30(s->b, 0, 0, v[1]); func_0029D010_0022BF30(s->c, 0, 0, v[2]); }
