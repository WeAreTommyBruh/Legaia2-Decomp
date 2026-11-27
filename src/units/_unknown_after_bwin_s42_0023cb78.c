#include "../common.h"
extern char D_004A54B0[];
int func_001118F8(char *fmt, ...);
void func_0018BBE0(int, int, void *, int, int, int, int, int);
// MATCH func_0023CB78
void FUN_0023cb78(int v) { int buf[8192]; int i; func_001118F8(D_004A54B0, buf); for (i = 8191; i >= 0; i--) buf[i] = v; for (i = 0; i < 128; i++) func_0018BBE0(i * 128, 4, buf, 0, 0, 0, 256, 32); }
