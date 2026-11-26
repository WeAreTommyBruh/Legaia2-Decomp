#include "../common.h"
extern int D_004A12A4, D_004A57F8;
typedef struct { char p[372]; unsigned short s[1200]; unsigned char c[1200]; } T; extern T D_003FEBA8;
// MATCH func_00254790
int FUN_00254790(void) { int i, r; if (D_004A12A4 == 11) return D_004A57F8; i = 0; r = 0; for (; i < 1200; i++) if (D_003FEBA8.s[i] != 0 && D_003FEBA8.c[i] != 0) r++; return r; }
