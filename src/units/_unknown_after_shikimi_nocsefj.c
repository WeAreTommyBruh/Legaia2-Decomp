/* Functions of this report unit, matched by hand. */
// cflags: -fno-cse-follow-jumps
#include "../common.h"
typedef struct mc { unsigned prev_size; unsigned size; struct mc *fd; struct mc *bk; } *mp;
extern mp D_004293F8[];
extern unsigned long D_00429800[];
extern unsigned long D_00429808[];
#define bin_at(i) ((mp)((char *)&D_004293F8[2*(i)+2] - 8))
#define binblocks (bin_at(0)->size)
#define top (bin_at(0)->fd)
#define last_remainder (bin_at(1))
#define smallbin_index(sz) (((unsigned long)(sz)) >> 3)
#define bin_index(sz) \
(((((unsigned long)(sz)) >> 9) ==    0) ?       (((unsigned long)(sz)) >>  3):\
 ((((unsigned long)(sz)) >> 9) <=    4) ?  56 + (((unsigned long)(sz)) >>  6): \
 ((((unsigned long)(sz)) >> 9) <=   20) ?  91 + (((unsigned long)(sz)) >>  9): \
 ((((unsigned long)(sz)) >> 9) <=   84) ? 110 + (((unsigned long)(sz)) >> 12): \
 ((((unsigned long)(sz)) >> 9) <=  340) ? 119 + (((unsigned long)(sz)) >> 15): \
 ((((unsigned long)(sz)) >> 9) <= 1364) ? 124 + (((unsigned long)(sz)) >> 18): 126)
#define idx2binblock(ix) (1L << ((ix) / 4))
#define mark_binblock(ii) (binblocks |= idx2binblock(ii))
#define chunksize(p) ((p)->size & ~3)
#define RSZ(a, b) ((a) < (b) ? -(long)((b) - (a)) : (long)((a) - (b)))
#define last(b) ((b)->bk)
#define first(b) ((b)->fd)
#define next_bin(b) ((mp)((char *)(b) + 8))
#define prev_bin(b) ((mp)((char *)(b) - 8))
#define set_inuse_bit_at_offset(p, s) (((mp)((char *)(p) + (s)))->size |= 1)
#define clear_last_remainder (last_remainder->fd = last_remainder->bk = last_remainder)
#define chunk_at_offset(p, s) ((mp)((char *)(p) + (s)))
#define inuse_bit_at_offset(p, s) (((mp)((char *)(p) + (s)))->size & 1)
#define unlink(P, BK, FD) { BK = P->bk; FD = P->fd; FD->bk = BK; BK->fd = FD; }
#define link_last_remainder(P) { last_remainder->fd = last_remainder->bk = P; P->fd = P->bk = last_remainder; }
#define frontlink(P, S, IDX, BK, FD) { \
  if (S < 512) { IDX = smallbin_index(S); mark_binblock(IDX); BK = bin_at(IDX); FD = BK->fd; P->bk = BK; P->fd = FD; FD->bk = BK->fd = P; } \
  else { IDX = bin_index(S); BK = bin_at(IDX); FD = BK->fd; \
    if (FD == BK) mark_binblock(IDX); \
    else { while (FD != BK && S < chunksize(FD)) FD = FD->fd; BK = FD->bk; } \
    P->bk = BK; P->fd = FD; FD->bk = BK->fd = P; } }
char *func_002DC9A8(void *, int);
void func_002E1B20(void *, void *);
extern char *D_00429810[];
extern int D_00429828[];
extern unsigned long D_00429818[];
extern unsigned long D_00429820[];
#define sbrk_base (D_00429810[0])
#define sbrked_mem (D_00429828[0])
#define max_sbrked_mem (D_00429818[0])
#define max_total_mem (D_00429820[0])
#define top_pad (D_00429808[0])
#define initial_top ((mp)D_004293F8)
#undef top
#define top (D_004293F8[2])
// MATCH func_002DBC80
void FUN_002dbc80(void *reent, unsigned nb)
{
  char *brk; unsigned front_misalign; unsigned correction; char *new_brk; unsigned top_size; int sm;
  mp old_top = top;
  unsigned old_top_size = chunksize(old_top);
  char *old_end = (char *)chunk_at_offset(old_top, old_top_size);
  unsigned sbrk_size = nb + top_pad + 16;
  unsigned long pagesz = 4096;
  if (sbrk_base != (char *)-1) sbrk_size = (sbrk_size + (pagesz - 1)) & ~(pagesz - 1);
  brk = func_002DC9A8(reent, sbrk_size);
  if (brk == (char *)-1 || (brk < old_end && old_top != initial_top)) return;
  sm = sbrked_mem + sbrk_size;
  sbrked_mem = sm;
  if (brk == old_end) {
    top_size = sbrk_size + old_top_size;
    top->size = top_size | 1;
  } else {
    if (sbrk_base == (char *)-1) sbrk_base = brk;
    else sbrked_mem = sm + (brk - old_end);
    front_misalign = (unsigned long)(brk + 8) & 15;
    if (front_misalign > 0) { correction = 16 - front_misalign; brk += correction; }
    else correction = 0;
    correction += pagesz - ((unsigned long)(brk + sbrk_size) & (pagesz - 1));
    new_brk = func_002DC9A8(reent, correction);
    if (new_brk == (char *)-1) return;
    sbrked_mem += correction;
    top = (mp)brk;
    top_size = new_brk - brk + correction;
    top->size = top_size | 1;
    if (old_top != initial_top) {
      if (old_top_size < 16) { top->size = 1; return; }
      old_top_size = (old_top_size - 12) & ~15;
      old_top->size = (old_top->size & 1) | old_top_size;
      chunk_at_offset(old_top, old_top_size)->size = 5;
      chunk_at_offset(old_top, old_top_size + 4)->size = 5;
      if (old_top_size >= 16) func_002E1B20(reent, (char *)old_top + 8);
    }
  }
  if ((unsigned long)sbrked_mem > max_sbrked_mem) max_sbrked_mem = sbrked_mem;
  if ((unsigned long)sbrked_mem > max_total_mem) max_total_mem = sbrked_mem;
}

