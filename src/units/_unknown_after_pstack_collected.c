/* Matched functions from this unit. */
#include "../ghidra.h"

typedef struct { char p[372]; unsigned short h[1200]; unsigned char b[1]; } SS;
extern SS D_003FEBA8; extern unsigned short D_00401028[];
#define S D_003FEBA8
// MATCH func_00250C60
int FUN_00250c60(int i) { unsigned short k = D_00401028[i]; int v = S.h[k]; if (v > 300) return S.b[k]; if (v != 0 && S.b[k] != 0) return 1; return 0; }
