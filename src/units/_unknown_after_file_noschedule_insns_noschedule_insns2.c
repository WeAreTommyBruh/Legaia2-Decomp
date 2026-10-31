/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns -fno-schedule-insns2
#include "../common.h"

extern int D_004A6F54; void func_0018A658(char *, char *); char *func_002DD1DC(char *, int); int *func_0018A708(char *);
// MATCH func_0018B250
int FUN_0018b250(char *name) { char buf[256]; char *p; int *e; int w; func_0018A658(name, buf); p = func_002DD1DC(buf, 58); if (p == 0) p = buf; else p++; e = func_0018A708(p); if (e == 0) return -1; w = e[3]; return D_004A6F54 + w; }
