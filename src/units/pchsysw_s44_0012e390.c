// compiler: 990721-r5900
#include "../common.h"
typedef struct N_E390 { char b[48]; float t, u; struct N_E390 *prev, *next; } N_E390;
typedef struct { int n; float total; N_E390 *head, *tail; } L_E390;
extern char D_00431D70[]; void *func_00162130(int, char *, int); void func_0012DA28(L_E390 *, N_E390 *); int func_0012E4F0(L_E390 *); float func_0018EAF8(N_E390 *, N_E390 *); void func_00131588(void *);
// MATCH func_0012E390
void pchsysw_0012e390(L_E390 *l) { float *w, *p; float sum, acc, v; N_E390 *n; int i;
  if (func_0012E4F0(l) < 3) return;
  sum = 0;
  w = func_00162130(func_0012E4F0(l) << 2, D_00431D70, 522);
  for (i = 1, n = l->head->next, p = w + 1; i < func_0012E4F0(l); i++, p++) { v = func_0018EAF8(n, n->prev); sum += v; *p = v; n = n->next; }
  acc = 0;
  for (i = 1, n = l->head->next, p = w + 1; i < func_0012E4F0(l) - 1; i++, p++) { { register float r __asm__("$f1") = *p; v = l->total * (r / sum); } n->t = v; acc += v; n = n->next; }
  n->t = l->total - acc;
  if (w) func_00131588(w);
  for (n = l->head; n; n = n->next) func_0012DA28(l, n); }
