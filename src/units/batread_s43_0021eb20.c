#include "../common.h"
typedef struct { void *a[128]; char s[64][64]; char t[64]; int b[64]; char pad[2048]; int n; int i; } B_EB20;
extern int D_004A1688; extern char D_004570A8[]; void func_001118F8(char *, ...); void func_002DD4CC(char *, char *); void func_00220B48(void *);
// MATCH func_0021EB20
void batread_0021eb20(B_EB20 *o, char *s, int a, int b) { if (D_004A1688 == 0) return; if (o->n >= 64) { func_001118F8(D_004570A8); return; } func_002DD4CC(o->s[o->i], s); { int i = o->i; o->b[i] = b; o->a[i] = (void *)a; } o->t[o->i] = 3; func_00220B48(o); }
