#include "../common.h"
typedef struct { float x, y, z, w; } V4_9470;
void func_0018EC90(V4_9470 *, void *, void *, void *); float func_0018ECB8(void *, V4_9470 *);
// MATCH func_00179470
int FUN_00179470(void *o, void *p, void *a, void *b, void *c, void *d) { V4_9470 v;
  func_0018EC90(&v, o, b, a); if (func_0018ECB8(p, &v) < 0) return 0;
  func_0018EC90(&v, o, c, b); if (func_0018ECB8(p, &v) < 0) return 0;
  func_0018EC90(&v, o, d, c); if (func_0018ECB8(p, &v) < 0) return 0;
  func_0018EC90(&v, o, a, d); if (func_0018ECB8(p, &v) < 0) return 0;
  return 1; }
