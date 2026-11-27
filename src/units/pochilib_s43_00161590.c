// compiler: 991111-01-as210
#include "../common.h"
typedef struct H_161590 { struct H_161590 *next; struct H_161590 *prev; unsigned size; int w12, w16, w20, w24; } H_161590;
extern int *D_004A6F44; extern int D_004A14EC; extern char D_0043C1E8[], D_0043C200[];
int func_001118F8(char *, ...); void func_001621F8(void *, char *, int);
// MATCH func_00161590
char *pochilib_00161590(unsigned a, char *blk, int sz) {
  H_161590 *hdr, *nb, *t; unsigned d; unsigned s2; int save;
  if (a >= (unsigned)D_004A6F44[1]) return 0;
  hdr = (H_161590 *)(blk - 128);
  s2 = (sz + 127) & 0xffffff80;
  if (hdr->size < s2) { func_001118F8(D_0043C1E8); return 0; }
  d = hdr->size - s2;
  if (d > 128) {
    nb = (H_161590 *)(blk + s2);
    nb->size = d - 128;
    t = hdr->next;
    hdr->size = s2;
    save = D_004A14EC;
    hdr->next = nb;
    t->prev = nb;
    nb->w16 = 0; nb->w24 = 0; nb->w20 = 0; nb->next = t; nb->prev = hdr;
    D_004A14EC = 0;
    func_001621F8((char *)nb + 128, D_0043C200, 333);
    D_004A14EC = save;
  }
  return blk;
}
