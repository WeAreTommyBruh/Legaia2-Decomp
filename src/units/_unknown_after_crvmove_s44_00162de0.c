// compiler: 990721-r5900
#include "../common.h"
typedef struct { float x, y, z, w; } V4_2DE0;
typedef struct N_2DE0 { float x, y, z; struct N_2DE0 *next; } N_2DE0;
typedef struct { char p[16]; V4_2DE0 a; V4_2DE0 b; char q[8]; N_2DE0 *list; } O_2DE0;
extern char D_004A2C68[], D_004A2C70[], D_004A2C78[], D_0043C658[], D_0043C670[];
void func_0018EED8(V4_2DE0 *, float); void func_002394D0(V4_2DE0 *, char *); void func_00239568(char *, ...);
// MATCH func_00162DE0
void FUN_00162de0(O_2DE0 *o, float t) { V4_2DE0 v; N_2DE0 *n;
  for (n = o->list; n; n = n->next) { v.x = n->x; v.y = n->y; v.z = n->z; func_0018EED8(&v, t); func_002394D0(&v, D_004A2C68); }
  v = o->a; func_0018EED8(&v, t); func_002394D0(&v, D_004A2C70);
  v = o->b; func_0018EED8(&v, t); func_002394D0(&v, D_004A2C78);
  func_00239568(D_0043C658, o->a.x, o->a.y, o->a.z);
  func_00239568(D_0043C670, o->b.x, o->b.y, o->b.z); }
