#include "../src/common.h"
typedef struct { int cls; int sign; int exp; unsigned long long ll; } FP;
static inline int isnan_(FP *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf_(FP *x) { return x->cls == 4; }
static inline int iszero_(FP *x) { return x->cls == 2; }
void func_002D7580(void *, void *);
// 7 words differ
// WIP func_002D7FE8
unsigned FUN_002d7fe8(double arg) { FP a; unsigned long long tmp; int s; func_002D7580(&arg, &a); if (iszero_(&a)) return 0; if (isnan_(&a)) return 0; if (a.sign) return 0; if (isinf_(&a)) return 0xffffffff; if (a.exp < 0) return 0; if (a.exp > 31) return 0xffffffff; if (a.exp < 61) { s = 60 - a.exp; tmp = a.ll >> s; } else { s = a.exp - 60; tmp = a.ll << s; } return (unsigned)tmp; }
