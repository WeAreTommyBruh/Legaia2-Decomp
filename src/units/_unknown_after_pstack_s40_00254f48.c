#include "../common.h"
extern unsigned short D_004A598E; extern unsigned short D_00401028[];
typedef struct { char p[372]; unsigned short s[1200]; unsigned char c[1200]; unsigned char d[2400]; } T; extern T D_003FEBA8;
void func_002552B8(void);
// MATCH func_00254F48
int FUN_00254f48(unsigned a) { int k, v, j; unsigned char *p;
  if (a >= D_004A598E) return -1;
  k = D_00401028[a]; v = D_003FEBA8.s[k];
  if (v == 0) return -1;
  if (v < 301) { D_003FEBA8.c[k] = 0; for (j = 1; j >= 0; j--) D_003FEBA8.d[k * 2 + j] = 0; }
  else { p = &D_003FEBA8.c[k]; if (*p == 0) return -1; *p = *p - 1; }
  func_002552B8();
  return 0; }
