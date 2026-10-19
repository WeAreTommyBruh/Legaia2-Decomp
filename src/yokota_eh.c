/* yokota.cpp functions built with exceptions on (no tail calls). Matched by hand. */
// cflags: -fexceptions
#include "common.h"

void FUN_002415e8(float, float, float, float);

// MATCH func_0023D038
void yokota_0023d038(float a, float b, float c)
{
    FUN_002415e8(a, b, c, 0.0f);
}
