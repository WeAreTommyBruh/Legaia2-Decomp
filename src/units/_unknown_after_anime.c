/* Functions of this report unit, matched by hand. */
#include "../common.h"

float func_0022F5E0(float, float, float);
void func_0018EED8(void *, float);
// MATCH func_0021DAC8
float FUN_0021dac8(float *v, float m)
{
    float len = func_0022F5E0(v[0], v[1], v[2]);
    if (m < len) {
        func_0018EED8(v, m / len);
        return m;
    }
    return len;
}

float func_0022F5E0_21DA10(float, float, float) __asm__("func_0022F5E0"); void func_0018EED8_21DA10(float *, float) __asm__("func_0018EED8");
// MATCH func_0021DA10
int FUN_0021da10(float *v, float *out, float a, float b) { float d; d = func_0022F5E0_21DA10(v[0], v[1], v[2]); if (a < d) { func_0018EED8_21DA10(v, a / d); *out = a; return 1; } if (d < b) { func_0018EED8_21DA10(v, b / d); *out = b; return 1; } *out = d; return 0; }
