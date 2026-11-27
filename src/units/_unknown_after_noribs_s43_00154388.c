#include "../common.h"
typedef struct { float x, y, z, w; } V4_154388;
void func_0018DF68(void *, void *); void func_0018F368(void *, void *, void *); void func_00153520(void *, void *, float); void func_001535B8(void *, void *, void *); void func_00154550(void *);
static inline void set_154388(V4_154388 *v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
// MATCH func_00154388
void FUN_00154388(char *o, float s) { V4_154388 q; V4_154388 v; char m[64]; set_154388(&v, 0, 1.0f, 0, 1.0f); func_0018DF68(m, o + 64); func_0018F368(&v, m, &v); func_00153520(&q, &v, s); func_001535B8(o + 192, o + 192, &q); func_00154550(o); }
