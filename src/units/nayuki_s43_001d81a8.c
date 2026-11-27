// compiler: 991111-01-as210
#include "../common.h"
typedef struct { int pad0, pad4; short off; short pad10; void (*fn)(void *, int); } VT_1D81A8;
extern int D_004A3864; extern char D_0044B358[], D_0044B368[];
void *func_00162130(int, char *, int); void *func_001D8250(void *); void func_001118F8(char *, ...); int func_001D9A50(void *, int, int);
// MATCH func_001D81A8
void *nayuki_001d81a8(int a, int b, int c) { char *p = func_001D8250(func_00162130(2576, D_0044B358, 499)); if (D_004A3864 & 0x40) func_001118F8(D_0044B368, p); if (p == 0) return 0; if (func_001D9A50(p, 0, c) == 0) { VT_1D81A8 *vt = *(VT_1D81A8 **)(p + 100); vt->fn(p + vt->off, 3); return 0; } return p; }
