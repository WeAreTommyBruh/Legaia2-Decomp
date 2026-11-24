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


typedef struct B_00161D68 { struct B_00161D68 *next, *prev; int pad[3]; int f20, f24; } B_00161D68;
extern B_00161D68 *D_004A6F44_161D68 __asm__("D_004A6F44"), *D_004A6F48_161D68 __asm__("D_004A6F48");
extern char D_0043C3B8_161D68[] __asm__("D_0043C3B8"), D_0043C3C8_161D68[] __asm__("D_0043C3C8"), D_0043C3E8_161D68[] __asm__("D_0043C3E8");
void func_002395A0_161D68(void *, ...) __asm__("func_002395A0");
// MATCH func_00161D68
void FUN_00161d68(B_00161D68 *h, B_00161D68 *addr, B_00161D68 *ex, char *msg) { B_00161D68 *best, *p, *n, *lo, *hi; B_00161D68 *l0 = D_004A6F44_161D68, *h0 = D_004A6F48_161D68; lo = l0; hi = h0; best = 0; for (n = h->next; (p = n) != h; ) { n = p->next; if ((int)p < (int)addr && (int)best < (int)p) best = p; if (n < lo || hi < n || n->prev != p) break; } lo = l0; hi = h0; for (n = h->prev; (p = n) != h; ) { n = p->prev; if ((int)p < (int)addr && (int)best < (int)p) best = p; if (n < lo || hi < n || n->next != p) break; } if (best == 0) { func_002395A0_161D68(D_0043C3B8_161D68, msg, addr); return; } if (best->f24 != 0 && best != ex) { func_002395A0_161D68(D_0043C3C8_161D68, msg, addr, best, best->f24, best->f20); return; } func_002395A0_161D68(D_0043C3E8_161D68, msg, addr); }
