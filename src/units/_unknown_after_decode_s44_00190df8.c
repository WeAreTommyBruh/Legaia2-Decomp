#include "../common.h"
typedef struct { int a, b, c; } R_0DF8;
// MATCH func_00190DF8
int FUN_00190df8(char *p, int n) { R_0DF8 *r = (R_0DF8 *)(p + 0x50000); int c, b, a, room, m; c = r->c; b = r->b; a = r->a; m = n; room = c - b; if (room < m) m = room; a = (a + m) % c; r->b = b + m; r->a = a; return m; }
