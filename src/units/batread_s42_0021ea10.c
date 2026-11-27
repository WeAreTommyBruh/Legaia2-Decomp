#include "../common.h"
extern char D_00457118[]; extern char D_00457128[]; void func_001118F8(char *, ...);
typedef struct { int b; char *name; int a; } E12;
typedef struct { char pad[7240]; E12 e[32]; int n; } O;
// MATCH func_0021EA10
void batread_0021ea10(O *o, int name, int a, int b) {
  int j, i;
  if (o->n > 32) func_001118F8(D_00457118);
  func_001118F8(D_00457128, name);
  i = o->n;
  o->e[i].b = b;
  o->e[i].name = (char *)name;
  o->n = (j = o->n) + 1; o->e[j].a = a;
}
