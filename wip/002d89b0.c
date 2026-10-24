#include "../src/common.h"
typedef struct { unsigned raw; } FU;
typedef struct { int cls; int sign; int exp; unsigned ll; } FP;
// 11 words differ
// WIP func_002D89B0
void __unpack_f(FU *src, FP *dst) { unsigned fraction; int exp; int sign; fraction = src->raw & 0x7fffff; exp = (src->raw >> 23) & 0xff; sign = src->raw >> 31; dst->sign = sign; if (exp == 0) { dst->cls = 2; } else if (exp == 0xff) { if (fraction == 0) { dst->cls = 4; } else { if (fraction & 0x100000) { dst->cls = 1; } else { dst->cls = 0; } dst->ll = fraction; } } else { dst->exp = exp - 127; dst->cls = 3; dst->ll = (fraction << 7) | 0x40000000; } }
