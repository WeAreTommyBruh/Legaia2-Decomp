// compiler: 990721-r5900
#include "../common.h"
typedef struct { char b[16]; } B16_DC70;
typedef struct N_DC70 { B16_DC70 b; char pad[32]; float t, u; struct N_DC70 *prev, *next; } N_DC70;
typedef struct { int n; float total; N_DC70 *head; N_DC70 *tail; } L_DC70;
extern char D_00431D70[]; void *func_00162130(int, char *, int); void func_0012DA28(L_DC70 *, N_DC70 *);
// MATCH func_0012DC70
void pchsysw_0012dc70(L_DC70 *l, B16_DC70 *src, float t, float u) { N_DC70 *n;
  if (l->n == 0) t = 0; else if (t <= 0) return;
  n = func_00162130(64, D_00431D70, 361);
  n->prev = 0; n->u = 1.0f; n->next = 0;
  n->b = *src; n->u = u; n->t = t;
  if (l->n == 0) { l->head = n; l->tail = n; func_0012DA28(l, n); }
  else { *(N_DC70 **)((char *)n + 56) = l->tail; *(N_DC70 **)((char *)l->tail + 60) = n; l->tail = n; func_0012DA28(l, n); func_0012DA28(l, n->prev); }
  l->total = l->total + t; l->n++; }
