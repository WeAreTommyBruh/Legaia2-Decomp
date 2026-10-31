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
