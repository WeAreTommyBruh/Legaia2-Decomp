/* Functions of shikimi.cpp, matched by hand. */
// compiler: 990721-r5900
#include "common.h"
typedef struct { char p0[0x20]; signed char f20; char p21[3]; int f24, f28; char p2c[0xc]; int f38, f3c, f40, f44, f48, f4c, f50; char p54[12]; } Win;
extern Win D_00620320[16];
typedef struct { char p0[0xd8]; void *fd8; } Wk;
extern int D_002F9804[];
extern int D_004A3830;
extern int D_004A72EC;
void FUN_001100b8(void);
int nayuwin2_001ad2d0(int);
void nayuwin2_001ad8f8(int, int);
void nayuwin2_001af490(int, int, int);
void nayuwin2_001af660(int, int);
Win *shikimi_002b1b98(int);
Wk *work_00246d88(char *, int);
extern char D_004213B0[];
extern char D_004213C0[];
int *shikimi_002b2650(void);
typedef struct { int f0; char p4[484]; int f1e8, f1ec, f1f0, f1f4; char p1f8[608 - 504]; } Ent608;
extern Ent608 D_005F9640[];
extern unsigned D_004A13CC;
extern int D_004A69A8, D_004A72F8;
extern char D_0041EF40[], D_004A6A78[], D_004A6A80[], D_004A6A88[];
long FUN_00160c70(char *, char *, int);
void FUN_002394d0(int, char *, long, int);

// MATCH func_002B1B30
int shikimi_002b1b30(void)
{
  int i;
  for (i = 0; i < 16; i++)
    if (D_00620320[i].f3c > 0 && D_00620320[i].f28 != 0)
      break;
  return i == 16;
}

// MATCH func_002B1B98
Win *shikimi_002b1b98(int idx)
{
  int i;
  if (idx >= 0) { if (idx < 16) return &D_00620320[idx]; return 0; }
  for (i = 15; i >= 0; i--) if (D_00620320[i].f3c == 0) break;
  if (i == -1) return 0;
  return &D_00620320[i];
}

// MATCH func_002B8DE0
void shikimi_002b8de0(char *dst, char *src)
{
  while (*src == '"') src++;
  while (*src != '"' && *src != 0) *dst++ = *src++;
  *dst = 0;
}

// MATCH func_002B11F8
int shikimi_002b11f8(int a, int idx)
{
  int i;
  Win *r;
  Wk *o;
  i = idx == -1 ? D_004A72EC : idx;
  r = shikimi_002b1b98(i);
  if (r == 0) return 0;
  if (r->f3c == 0) {
    o = work_00246d88(D_004213B0, D_002F9804[0]);
    if (o == 0) return 0;
    o->fd8 = r;
    r->f50 = nayuwin2_001ad2d0(1);
    nayuwin2_001af660(r->f50, 0);
    nayuwin2_001af490(r->f50, r->f24, 30);
    nayuwin2_001ad8f8(r->f50, r->f20);
    r->f40 = 0;
    r->f3c = 1;
  }
  r->f48 = a;
  D_004A3830 = r->f50;
  FUN_001100b8();
  return 1;
}

// MATCH func_002B1D88
int shikimi_002b1d88(int a, float *d)
{
  int *r; float *rf; int *di = (int *)d;
  Wk *o;
  r = shikimi_002b2650();
  if (r == 0) return 0;
  if (r[13] == 0) {
    o = work_00246d88(D_004213C0, D_002F9804[0]);
    if (o == 0) return 0;
    rf = (float *)r;
    rf[0] = d[3];
    r[6] = 0;
    rf[1] = d[4];
    r[8] = 0;
    r[7] = 0;
    rf[2] = d[5];
    o->fd8 = r;
    rf[3] = d[6];
    r[10] = 0;
    r[9] = 0;
    r[11] = di[2];
    r[12] = di[1];
    rf[4] = d[7];
    rf[5] = d[8];
    r[13] = 1;
    r[14] = a;
  }
  return 1;
}

// MATCH func_002B0BC8
void shikimi_002b0bc8(void)
{
  int i;
  if ((D_004A13CC & 3) != 0) {
    for (i = 0; i < D_004A69A8; i++) {
      Ent608 *e = &D_005F9640[i];
      if ((D_004A13CC & 1) != 0 && e->f1f4 == D_004A72F8 && (e->f1f0 & 3) != 0) {
        int t = e->f0;
        FUN_002394d0(t + 0x20, D_004A6A78, FUN_00160c70(D_0041EF40, D_004A6A80, e->f1e8), e->f1e8);
      }
      if ((D_004A13CC & 2) != 0 && e->f1f4 == D_004A72F8 && (e->f1f0 & 4) != 0) {
        int t = e->f0;
        FUN_002394d0(t + 0x20, D_004A6A78, FUN_00160c70(D_0041EF40, D_004A6A88, e->f1e8), e->f1e8);
      }
    }
  }
}
