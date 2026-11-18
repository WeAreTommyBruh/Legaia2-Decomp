/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

typedef struct H_161690 { struct H_161690 *next, *prev; int size, id, used; char p20[108]; } H_161690;
extern int D_004A14EC; extern char **D_004A6F44; extern char D_0043C210[], D_0043C228[];
void func_001118F8(char *, ...); void func_00161278(H_161690 *);
// MATCH func_00161690
void FUN_00161690(char *ptr) {
  H_161690 *h = (H_161690 *)(ptr - 128), *q, *n; int sz;
  if (h->used != 0) func_001118F8(D_0043C210, ptr);
  if (D_004A14EC != 0) func_001118F8(D_0043C228, h->id);
  sz = h->size;
  h->used = 1;
  func_00161278(h);
  q = (H_161690 *)(*D_004A6F44 + 128);
  while (q->next < h) q = q->next;
  n = q->next;
  q->next = h;
  n->prev = h;
  h->prev = q;
  h->next = n;
  h->size = sz;
  if ((char *)h + sz + 128 == (char *)n) { h->size = sz + (n->size + 128); func_00161278(n); }
  if ((char *)q + q->size + 128 == (char *)q->next) { q->size = q->size + (q->next->size + 128); func_00161278(q->next); }
}
