#include "../common.h"
typedef char *va_list;
extern int D_004A1298, D_004A7138; extern char D_005F6A40[], D_005F6A00[];
int func_002396B8(char *, va_list); int func_001114B0(void); int func_002E02F8(char *, va_list); char *func_002DD4CC(char *, char *);
// MATCH func_002395A0
int FUN_002395a0(char *fmt, ...) { va_list ap; int old = D_004A1298; int r; D_004A1298 = 1; ap = (va_list)__builtin_next_arg(fmt) - 56; r = func_002396B8(fmt, ap); if (func_001114B0() == 0) func_002E02F8(fmt, ap); if (D_004A7138 < 24) { func_002DD4CC(D_005F6A40 + D_004A7138++ * 64, D_005F6A00); } D_004A1298 = old; return r; }
