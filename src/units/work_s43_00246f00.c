// compiler: 990721-r5900
#include "../common.h"
extern int D_00318C20[]; extern char D_0045D4F0[]; void *func_00162130(int, char *, int); void func_0017FC20(void *, int); void func_002445F0(char *); void func_0023FE68(char *, int);
typedef struct { char p[64]; int b; unsigned short n; char q[90]; } E;
typedef struct { char p[3]; unsigned char n; char q[12]; E e[1]; } S;
// MATCH func_00246F00
void work_00246f00(char *o) { S *s; E *e; int i; *(short *)(o + 392) = 0; s = (S *)D_00318C20[*(unsigned short *)(*(char **)(o + 144) + 2312)]; e = s->e; for (i = 0; i < s->n; i++) { if (e[i].b == 0) { e[i].b = (int)func_00162130(e[i].n << 4, D_0045D4F0, 694); func_0017FC20(&e[i], 0); } } func_002445F0(o); func_0023FE68(o, 0); }
