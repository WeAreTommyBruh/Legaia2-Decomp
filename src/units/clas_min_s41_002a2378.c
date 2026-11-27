#include "../common.h"
extern char D_0041EF40[], D_004A6850[], D_0049AE58[]; void *func_00160C70(char *, char *, int); void func_002A2170(char *, void *); void func_002A2CD0(char *, int); void func_002A3268(char *, int); int func_002A3278(char *); void func_002A3908(char *); void func_0024ABE0(char *);
// MATCH func_002A2378
void clas_min_002a2378(char *o, int a, void *b) { if (b) func_002A2170(o, b); else func_002A2170(o, func_00160C70(D_0041EF40, D_004A6850, *(int *)(o + 12))); func_002A2CD0(o, a); func_002A3268(o, *(int *)(o + 8)); while (func_002A3278(o) == 0) ; func_002A3908(o); func_0024ABE0(D_0049AE58); }
