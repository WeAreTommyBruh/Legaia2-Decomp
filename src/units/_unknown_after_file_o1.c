/* Functions of this report unit, matched by hand. */
// cflags: -O1
#include "../common.h"

void func_0018A658(char *, char *); char *func_002DD1DC(char *, int); char *func_0018A708(char *);
// MATCH func_0018B1F8
int FUN_0018b1f8(char *name) { char buf[256]; char *p, *e; if (name == 0) return -1; func_0018A658(name, buf); p = func_002DD1DC(buf, 58); if (p == 0) p = buf; else p++; e = func_0018A708(p); if (e == 0) return -1; return ((unsigned short *)e)[5] << 11; }

extern int D_004A14CC; extern char D_00440530[];
int func_0024C568(void *); unsigned long long func_001118F8(char *, ...);
// MATCH func_0018BB70
int FUN_0018bb70(int *a, int b, int c, int d, int e, int idx) { if ((unsigned)a & 0xf) D_004A14CC++; if (idx >= 0) { if ((unsigned)idx < (unsigned)a[0]) { if (func_0024C568((char *)a + (a[idx + 1] << 2)) < 0) func_001118F8(D_00440530); } } return -1; }
