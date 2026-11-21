/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

extern int D_004A6DA4, D_004A1A84; void func_0012AEA8(int); int func_00121918(int);
// MATCH func_00121980
void battle_00121980(int a, int step) { func_0012AEA8(8); do { if (D_004A6DA4 < 0) D_004A6DA4 = D_004A1A84 - 1; if (D_004A6DA4 >= D_004A1A84) D_004A6DA4 = 0; if (func_00121918(D_004A6DA4)) return; D_004A6DA4 += step; } while (1); }

typedef struct { char p[5216]; int a; int b; int c; int d; char q[240]; } E_00126798;
extern E_00126798 *D_004A1A20; extern int D_003279A0[];
// MATCH func_00126798
void battle_00126798(void) { int i; for (i = 0; i < 10; i++) { if (D_003279A0[i] != 0) { if (D_004A1A20[i].c <= D_004A1A20[i].a) D_004A1A20[i].c = D_004A1A20[i].a; if (D_004A1A20[i].b >= D_004A1A20[i].d) D_004A1A20[i].d = D_004A1A20[i].b; } } }

extern char D_0053FD00[]; extern int D_004A6DD0, D_004A6D00, D_004A6D04, D_004A6D08;
int func_0012C1E8(void); int func_0015ADE8(char *, int); int func_0015AE08(char *, int); int func_001565B0(int, int, int); int func_00156408(int, int, int); int func_00156D38(int, int, int); int func_00156B58(int, int);
// MATCH func_00118638
void battle_00118638(void) { int h; if (func_0012C1E8() == 0) return; h = func_0015ADE8(D_0053FD00, 0); if (h != 0) { if (D_004A6DD0 == 0) func_001565B0(h, 8768, 15760); if (D_004A6D00 != 0) func_00156408(h, D_004A6D04, D_004A6D08); } h = func_0015AE08(D_0053FD00, 0); if (h != 0) { if (D_004A6DD0 == 0) func_00156D38(h, 9792, 15768); if (D_004A6D00 != 0) func_00156B58(h, D_004A6D04); } D_004A6DD0 = 1; }

typedef struct 
{
  char p[209];
  char c209;
} U_11DFE0;
extern int D_004A6DAC;
extern int D_004A6DB0;
extern int D_004A1A44;
extern int D_004A1A60;
extern int D_004A6DA8;
extern int D_004A1A8C;
extern int D_004A6E70;
extern int D_004A6E90;
extern float D_0049FD54;
extern float D_0049FD58;
extern float D_0049FD5C;
extern U_11DFE0 *D_003279A0_11DFE0[] __asm__("D_003279A0");
extern char D_00326F90[];
void func_0012AEA8(int);
void func_00235130(int, int);
volatile unsigned long long func_0011BC88(float, float, float, float, float, float, float, int);
void func_001266F8(void);
int func_00127210(void);
void func_00221D60(char *, int, int);
// MATCH func_0011DFE0
void battle_0011dfe0(void)
{
  int i;
  U_11DFE0 **p;
  D_004A6DAC = 0;
  D_004A6DB0 = 0;
  D_004A1A44 = 0;
  func_0012AEA8(1);
  func_00235130(-1, D_004A1A60);
  D_004A6DA8 = 1;
  func_0011BC88(100.0f, D_0049FD54, D_0049FD58, 0.0f, D_0049FD5C, -11008.0f, -47104.0f, 3908);
  D_004A6E70 = 0;
  i = 0;
  if (D_004A1A8C > 0)
  {
    p = D_003279A0_11DFE0;
    do
    {
      if ((*p) != 0)
      {
        (*p)->c209 = 0;
      }
      i++;
      p++;
    }
    while (i < D_004A1A8C);
  }
  func_001266F8();
  if (func_00127210() != 0)
  {
    func_00221D60(D_00326F90, 0, 0);
  }
  D_004A6E90 = 0;
}

typedef struct 
{
  int w0;
  void *p4;
  short h8;
  short h10;
  short h12;
  short h14;
  char a[4];
  short h20;
  char b[4];
  short h26;
  short h28;
  char c[6];
  int w36;
  char d[12];
  int w52;
  char e[12];
  int w68;
  char f[56];
} BO_0011BB28;
extern BO_0011BB28 D_00327DA0_11BB28[] __asm__("D_00327DA0");
extern char *D_004A1A20_11BB28 __asm__("D_004A1A20");
extern float D_0049FCE4_11BB28 __asm__("D_0049FCE4");
unsigned short func_00235028_11BB28(BO_0011BB28 *, float) __asm__("func_00235028");
// MATCH func_0011BB28
void battle_0011bb28(int i, int x, int y, int fl, int n) { BO_0011BB28 *o = &D_00327DA0_11BB28[i]; D_00327DA0_11BB28[i].p4 = (D_004A1A20_11BB28 + (i * 5472)) + 4872; D_00327DA0_11BB28[i].w68 = n + 1; o->h8 = x; o->h10 = y; o->h12 = x; o->h26 = x; o->h14 = y; o->h28 = y; o->h20 = 9; switch (fl & 0x7f) { case 0: o->w0 = 4; break;  case 1: o->w0 = 7; break;  case 2: o->w0 = 10; break;  }  D_00327DA0_11BB28[i].w36 = i; func_00235028_11BB28(&D_00327DA0_11BB28[i], D_0049FCE4_11BB28); if (fl & 0x400) { D_00327DA0_11BB28[i].w52 |= 0x200; } else { D_00327DA0_11BB28[i].w52 &= ~0x200; } }

typedef struct { char p[68]; int w68; } S326_00127930;
extern S326_00127930 D_00326F90_127930 __asm__("D_00326F90"); extern int D_004A6CA4_127930 __asm__("D_004A6CA4"), D_004A6C34_127930 __asm__("D_004A6C34"), D_004A6C4C_127930 __asm__("D_004A6C4C"), D_004A1A60_127930 __asm__("D_004A1A60"), D_004A6DB4_127930 __asm__("D_004A6DB4"), D_004A6CA8_127930 __asm__("D_004A6CA8"), D_004A1A50_127930 __asm__("D_004A1A50"), D_004A1A54_127930 __asm__("D_004A1A54"), D_00425510_127930[] __asm__("D_00425510");
extern char D_004A1980_127930[] __asm__("D_004A1980"), D_004A1988_127930[] __asm__("D_004A1988"), D_00431340_127930[] __asm__("D_00431340");
int func_00290850_127930(void) __asm__("func_00290850"); int func_00221638_127930(S326_00127930 *) __asm__("func_00221638"); void func_00235130_127930(int, int) __asm__("func_00235130"); int func_001118F8_127930(char *, ...) __asm__("func_001118F8"); int func_0012AEA8_127930(int) __asm__("func_0012AEA8"); void func_0027C3E0_127930(void) __asm__("func_0027C3E0");
// MATCH func_00127930
int battle_00127930(void) { int flag = 0; int r = func_00290850_127930(); D_004A6CA4_127930 = -1; D_004A6C34_127930 = r; if ((func_00221638_127930(&D_00326F90_127930) == 33 || func_00221638_127930(&D_00326F90_127930) == 42) && D_00326F90_127930.w68 == 0) { D_004A6C4C_127930 = 4; flag = 1; func_00235130_127930(-2, D_004A1A60_127930); } if (func_00221638_127930(&D_00326F90_127930) == 34 && D_004A6DB4_127930 >= 5) { D_004A6C4C_127930 = 4; flag = 1; func_00235130_127930(-2, D_004A1A60_127930); } if (func_00221638_127930(&D_00326F90_127930) == 43 && r >= 0) { D_004A6C4C_127930 = 4; flag = 1; func_00235130_127930(-2, D_004A1A60_127930); } if (func_00221638_127930(&D_00326F90_127930) == 47) { if (D_004A6CA8_127930 != 0) { D_004A6C4C_127930 = 4; flag = 1; func_00235130_127930(-2, D_004A1A60_127930); } else if (D_004A6DB4_127930 >= 6) { func_001118F8_127930(D_004A1980_127930); D_004A1A50_127930 |= 8; D_00425510_127930[1] |= 0x12000; return -2; } } if (flag) { func_001118F8_127930(D_004A1988_127930); D_00425510_127930[1] = (D_00425510_127930[1] | 0x10000u) & ~0x2000u; func_0012AEA8_127930(14); return -1; } if (r < 0) { func_0027C3E0_127930(); func_001118F8_127930(D_00431340_127930, D_004A6DB4_127930); if (r == -2) { func_001118F8_127930(D_004A1980_127930); D_004A1A50_127930 |= 8; D_00425510_127930[1] |= 0x12000; } if (r == -3) { func_001118F8_127930(D_004A1988_127930); D_00425510_127930[1] = (D_00425510_127930[1] | 0x10000u) & ~0x2000u; } func_0012AEA8_127930(14); if (D_004A1A54_127930 != 0) func_0012AEA8_127930(15); } return r; }

