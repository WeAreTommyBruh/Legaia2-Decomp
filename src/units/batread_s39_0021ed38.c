#include "../common.h"
extern char D_004570A8[]; void func_001118F8(char *, ...); typedef struct { int b[64]; int a[64]; char p[4096]; char c[2368]; int n; int i; } O; void func_00220B48(void *);
// MATCH func_0021ED38
void batread_0021ed38(O *o, int a, int b) { int i; if (o->n >= 64) { func_001118F8(D_004570A8); return; } i = o->i; o->a[i] = a; o->b[i] = b; o->c[i] = 5; func_00220B48(o); }
