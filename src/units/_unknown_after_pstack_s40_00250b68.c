#include "../common.h"
typedef struct { char p[372]; unsigned short s[1200]; unsigned char c[1200]; } T; extern T D_003FEBA8;
// MATCH func_00250B68
int FUN_00250b68(int id) { int i, r; if (id > 300) { i = 0; r = 0; for (; i < 1200; i++) if (D_003FEBA8.s[i] == id) return D_003FEBA8.c[i]; } else { i = 0; r = 0; for (; i < 1200; i++) if (D_003FEBA8.s[i] == id && D_003FEBA8.c[i] != 0) r++; } return r; }
