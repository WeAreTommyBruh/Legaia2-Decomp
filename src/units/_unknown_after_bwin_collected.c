/* Matched functions from this unit. */
#include "../common.h"

extern int D_004A129C;
extern char D_0045C750[];
void FUN_00239568(void *, int, int, int, int);
// MATCH func_0023A300
void FUN_0023a300(int *p)
{
  int old = D_004A129C;
  int a = p[0], b = p[1], c = p[2], d = p[3];
  D_004A129C = 1;
  FUN_00239568(D_0045C750, a, b, c, d);
  D_004A129C = old;
}
