// compiler: 990721-r5900
#include "../common.h"
extern int D_004A2AB0;
float func_0018ECB8(void *, void *);
void func_0018EFA0(void *, void *, void *);
int func_001793C0(void *, void *, void *, void *, void *);
int FUN_0015c170(void *, float, void *, void *);
// MATCH func_0015C258
int FUN_0015c258(float e, void *A, void *B, void *C, void *D, float *E)
{
    char s[16];
    register float d __asm__("$f12"); int r;
    { float t = func_0018ECB8(A, E); register float u __asm__("$f1") = E[3]; d = t - u; }
    if (d < 0.0f) return 0;
    if (e < d) return 0;
    func_0018EFA0(s, A, E);
    if (func_001793C0(s, E, B, C, D) == 1) return 1;
    if (D_004A2AB0 < 18) {
        r = FUN_0015c170(A, e, B, C) != 0; if (r == 1) return 2;
        r = FUN_0015c170(A, e, C, D) != 0; if (r == 1) return 2;
        r = FUN_0015c170(A, e, D, B) != 0; if (r == 1) return 2;
    }
    return 0;
}
