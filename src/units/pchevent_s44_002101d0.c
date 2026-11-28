#include "../common.h"
extern int D_004A1444, D_004A140C; extern void *D_004A45E4;
extern char D_00454D80[], D_00455008[], D_00455488[];
extern char D_00455478[] __attribute__((aligned(8)));
extern int D_00329640[];
void *func_00162130(int, char *, int); void *func_0020B508(void *, int); void func_0020B660(void *); int func_0020B858(void *, char *); void func_0020BA70(void *, char *); int func_002DCE40(char *, char *, ...);
// MATCH func_002101D0
void pchevent_002101d0(int a) { char buf[1024]; int i; int *p; int v; if (a != 0 && D_004A1444 == 0 && (D_004A140C & 8) != 0) { if (*(void * volatile *)&D_004A45E4 == 0) { void *m = func_00162130(20, D_00454D80, 2549); D_004A45E4 = func_0020B508(m, 24); } func_0020B660(D_004A45E4); __builtin_memcpy(buf, D_00455478, 14); func_0020B858(D_004A45E4, buf); for (i = 0, p = D_00329640; i < 8; i++) { func_002DCE40(buf, D_00455488, *p++); func_0020B858(D_004A45E4, buf); } func_0020BA70(D_004A45E4, D_00455008); } }
