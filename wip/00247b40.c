#include "../src/common.h"
typedef struct { char p[16]; char *w16; } P; extern P *D_004A1524;
// 4 words differ
// WIP func_00247B40
void FUN_00247b40(unsigned long long a, unsigned long long b) { P *p = D_004A1524; char *q = p->w16; p->w16 = q + 16; *(unsigned long long *)q = a | (b << 16); *(unsigned long long *)(q + 8) = 3; }
