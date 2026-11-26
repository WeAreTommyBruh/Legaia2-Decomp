#include "../common.h"
extern unsigned short D_004A598E; extern unsigned short D_00401028[];
typedef struct { char p[372]; unsigned short s[1200]; unsigned char c[1200]; unsigned char d[2400]; } T; extern T D_003FEBA8;
// MATCH func_00255098
int FUN_00255098(unsigned a, int b) { int k, v, j; unsigned char *p;
  if (a >= D_004A598E) return -1;
  k = D_00401028[a]; v = D_003FEBA8.s[k];
  if (v == 0) return -1;
  if (v < 301) { D_003FEBA8.c[k] = 0; for (j = 1; j >= 0; j--) D_003FEBA8.d[k * 2 + j] = 0; return 0; }
  p = &D_003FEBA8.c[k];
  if (*p == 0) return -1;
  if (*p < b) *p = 0; else *p = *p - b;
  return 0; }
