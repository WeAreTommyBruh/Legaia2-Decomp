/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

extern char D_00314C20[]; void func_00190328(char *); void func_00190420(char *);
// MATCH func_00164668
void FUN_00164668(int *o) { int *p; int *nx; func_00190328(D_00314C20); p = (int *)((int *)o[0])[23]; if (p != (int *)o[0]) do { int *vt = (int *)p[26]; nx = (int *)p[23]; ((void (*)(int))*(int *)((char *)vt + 28))((int)p + *(short *)((char *)vt + 24)); p = nx; } while (p != (int *)o[0]); func_00190420(D_00314C20); }
