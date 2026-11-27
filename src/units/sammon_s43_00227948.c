#include "../common.h"
extern void *D_004A7070;
int func_00163150(int, int);
#define X(o) *(int *)(*(int *)(o + 2092) * k + *(int *)(o + 2064) + 48)
// MATCH func_00227948
int sammon_00227948(char *o) { int k = 56; int r = -1; int m = *(int *)(o + 76); if (X(o) != 0 && m != 0) { D_004A7070 = (void *)func_00163150(m, X(o)); r = func_00163150(m, X(o)); } return r; }
