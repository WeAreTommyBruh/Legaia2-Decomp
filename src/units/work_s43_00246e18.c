// compiler: 991111-01
#include "../common.h"
typedef struct { char p[64]; void *m; char q[92]; } E_246E18;
typedef struct { char p[3]; unsigned char n; char q[12]; E_246E18 e[1]; } T_246E18;
extern T_246E18 *D_00318C20[]; extern char D_0045D4F0[];
void func_001621F8(void *, char *, int); void object_002444c0(char *); void work_00245fe8(int);
// MATCH func_00246E18
void work_00246e18(char *o) {
  int i; T_246E18 *t;
  if (o[394] != 0 && *(int *)(o + 144) != 0) {
    t = D_00318C20[*(unsigned short *)(*(int *)(o + 144) + 2312)];
    { E_246E18 *e = t->e; for (i = 0; i < t->n; i++) { if (e[i].m != 0) func_001621F8(e[i].m, D_0045D4F0, 668); e[i].m = 0; } }
    object_002444c0(o);
    if (*(int *)(o + 412) != 0) work_00245fe8(*(int *)(o + 412));
    *(int *)(o + 412) = 0; *(short *)(o + 392) = 0;
  }
}
