// cflags: -fno-strict-aliasing
typedef struct { char p[8]; unsigned short *end; unsigned short *hdr; char *cur; int mode; int pad; unsigned long *tag; } S;
// MATCH func_00190598
void FUN_00190598(S *s)
{
  unsigned long *t = s->tag;
  *t = (*t & ~0x7fffL) | (((s->cur - (char *)t) >> 4) - 1 & 0x7fff);
  *s->hdr = ((s->cur - (char *)s->hdr) >> 4) - 1;
  if (s->mode == 1) s->end = s->hdr + *s->hdr * 8 + 8;
}
