// compiler: 990721-r5900
#include "../common.h"
extern int D_004A3864, D_004A1274, D_004A1278; extern char D_0042F340[], D_0042F348[], D_0042F368[];
void func_002DC804(void *, int, int); int func_002DD5E0(char *); void func_001118F8(char *, ...); void func_0023C728(char *, char *); void func_00239568(char *, int, int, int);
// MATCH func_00114478
void FUN_00114478(char *s, int x, int y, int sx, int sy, int col) { char buf[256]; int i, n; char *p;
  __builtin_memcpy(buf, D_0042F340, 5); func_002DC804(buf + 5, 0, 251);
  if (D_004A3864 & 0x2000) { n = func_002DD5E0(s); for (i = 0; i < n - 1; i++) { p = s + i; if (*p == '%' && (p[1] == 's' || p[1] == 'd')) { func_001118F8(D_0042F348); func_001118F8(D_0042F368, x, y, sx, sy, col, s); break; } } }
  D_004A1274 = sx; D_004A1278 = sy;
  func_0023C728(buf, s); func_00239568(buf, col, x, y); }
