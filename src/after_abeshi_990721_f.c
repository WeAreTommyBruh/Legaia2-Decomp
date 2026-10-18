/* More of _unknown_after_abeshi built like after_abeshi_990721.c: appends the
   non-zero entries of three tables whose value lies in a range to a list. Matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "common.h"

typedef struct 
{
  u8 a;
  u8 b;
} Pair;
typedef struct 
{
  char unk0[0x128];
  u16 h[10];
  char unk13c[0x148 - 0x13c];
  u8 g[16];
  char unk158[0x158 - 0x158];
  Pair p[8];
  char unk168[472 - 0x168];
} Rec;
extern struct 
{
  char pad[0x18f0];
  Rec rec[5];
} D_003FEBA8;
typedef struct 
{
  char p0[2];
  u8 y;
  char p3[25];
} T2;
extern u8 D_003DC5B8[][20];
extern T2 D_003E2010[];
typedef struct 
{
  char pad[866];
  u8 list[70];
} Chr;
typedef struct 
{
  Chr c[1];
} Party;
extern char *D_004A6578;
inline int inline_fn(int arg0)
{
  return arg0 * 936;
}

// MATCH func_002682E0
int FUN_002682e0(int a, int b, int c, int d, int cnt)
{
  int j;
  int v;
  int hi;
  int lo;
  T2 *p;
  u8 x;
  u8 *py;
  u8 *px;
  T2 *p3;
  int nvv;
  int nv3;
  v = D_003FEBA8.rec[a].h[c];
  hi = D_003FEBA8.rec[a].g[c] - 1;
  lo = hi;
  hi += d;
  px = D_003DC5B8[v];
  py = D_003DC5B8[v] + 4;
  for (j = 0; j < 4; j++)
  {
    x = px[j];
    if ((x && (lo < py[j])) && (py[j] <= hi))
    {
      *(D_004A6578 + (cnt + inline_fn(b)) + 866) = x;
      cnt++;
    }
  }
  x = D_003FEBA8.rec[a].p[c].a;
  p = &D_003E2010[x];
  nvv = p->y;
  if (x && lo < nvv && nvv <= hi)
  {
    *(D_004A6578 + (cnt + inline_fn(b)) + 866) = x;
    cnt++;
  }
  x = D_003FEBA8.rec[a].p[c].b;
  p3 = &D_003E2010[x];
  nv3 = p3->y;
  if (x && lo < nv3 && nv3 <= hi)
  {
    *(D_004A6578 + (cnt + inline_fn(b)) + 866) = x;
    cnt++;
  }
  return cnt;
}
