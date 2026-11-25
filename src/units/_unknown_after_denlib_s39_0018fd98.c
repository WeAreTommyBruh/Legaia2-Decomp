// cflags: -fno-strict-aliasing
typedef struct { char p[8]; short adj; short pad; void (*fn)(void *, unsigned long *); } VT;
typedef struct { char p[0x18]; VT *vt; } O;
// MATCH func_0018FD98
void FUN_0018fd98(O *o, unsigned long *d, unsigned int a, long b, int c)
{
  unsigned long t = (unsigned long)a;
  d[1] = 0;
  d[0] = c | ((b << 32) | (t << 24));
  o->vt->fn((char *)o + o->vt->adj, d);
}
