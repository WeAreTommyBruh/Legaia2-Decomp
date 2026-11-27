// compiler: 991111-01-as210
#include "../common.h"
typedef struct { int n0, n1; unsigned char *d0, *d1; unsigned char s0[64]; unsigned char s1[64]; } P_002CB340;
extern int D_00426394[];
void func_002CB108(int *);
// MATCH func_002CB340
void FUN_002cb340(unsigned p) { P_002CB340 *q = (P_002CB340 *)((unsigned)p | 0x20000000); int i; if (q->n0 > 0) { unsigned char *d = q->d0; for (i = 0; i < q->n0; i++) d[i] = q->s0[i]; } if (q->n1 > 0) { unsigned char *d = q->d1; for (i = 0; i < q->n1; i++) d[i] = q->s1[i]; } func_002CB108(D_00426394); }
