/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern float D_00336760[];
// MATCH func_001E1C38
float FUN_001e1c38(float x) { float v = D_00336760[2] - x * D_00336760[3]; if (D_00336760[1] < v) v = D_00336760[1]; if (v < D_00336760[0]) v = D_00336760[0]; return v; }
