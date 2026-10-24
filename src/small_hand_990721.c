/* Small functions matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "common.h"

// MATCH func_00108C20
void FUN_00108c20(void *s)
{
    float b;
    float t;
    if (FIELD(float, s, 32) == 0.0f && FIELD(float, s, 36) == 0.0f) {
        FIELD(float, s, 0) = FIELD(float, s, 8);
        return;
    }
    b = FIELD(float, s, 36);
    t = FIELD(float, s, 20);
    FIELD(float, s, 0) = t * (FIELD(float, s, 32) * t + b) + FIELD(float, s, 4);
}
