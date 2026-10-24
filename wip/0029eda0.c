#include "../src/common.h"
typedef struct { char p[144]; char *t; } Q29; typedef struct { char p[60]; int i; } P29; void func_002BD8F8(void);
// 6 words differ
// WIP func_0029EDA0
void clas_min_0029eda0(P29 *p, Q29 *q, int i) { p->i = i; *(void **)(q->t + i * 4 + 1024) = (void *)func_002BD8F8; }
