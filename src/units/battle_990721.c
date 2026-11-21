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

typedef struct { char p0[24]; unsigned w24; char p1[52]; float f80, f84, f88; char p2[117]; unsigned char b209; } O_0012A1B8;
typedef struct { char p0[4816]; unsigned fl; char p1[422]; short h5242; char p2[190]; short h5434; char p3[36]; } E_0012A1B8;
typedef struct { int p[3]; unsigned f12; int q[3]; } T_0012A1B8;
typedef struct { char p[8]; float f8; } Cm_0012A1B8;
extern O_0012A1B8 *D_003279A0_12A1B8[] __asm__("D_003279A0");
extern E_0012A1B8 *D_004A1A20_12A1B8 __asm__("D_004A1A20");
extern T_0012A1B8 D_00323B40_12A1B8[] __asm__("D_00323B40");
extern Cm_0012A1B8 *D_00327974_12A1B8[] __asm__("D_00327974");
extern int D_004A6D94_12A1B8 __asm__("D_004A6D94"), D_004A6D9C_12A1B8 __asm__("D_004A6D9C"), D_004A6DA4_12A1B8 __asm__("D_004A6DA4"), D_004A6E50_12A1B8 __asm__("D_004A6E50"), D_004A1A6C_12A1B8 __asm__("D_004A1A6C"), D_004A13D4_12A1B8 __asm__("D_004A13D4"), D_004A1A2C_12A1B8 __asm__("D_004A1A2C"), D_004A1A50_12A1B8 __asm__("D_004A1A50"), D_004A6DFC_12A1B8 __asm__("D_004A6DFC"), D_004A6C58_12A1B8 __asm__("D_004A6C58"), D_004A6E04_12A1B8 __asm__("D_004A6E04");
extern float D_0049FE50_12A1B8 __asm__("D_0049FE50");
extern char D_004317A8_12A1B8[] __asm__("D_004317A8");
extern int battle_00127430(void), battle_0012c448(int);
extern int func_00127210_12A1B8(void) __asm__("func_00127210");
extern int func_0021A938_12A1B8(void *) __asm__("func_0021A938");
extern int func_002D9340_12A1B8(float) __asm__("func_002D9340");
extern int battle_0012a140(O_0012A1B8 *);
extern float func_0022F5E0_12A1B8(float, float, float) __asm__("func_0022F5E0");
extern void func_001227B8_12A1B8(void) __asm__("func_001227B8");
extern void func_0022D470_12A1B8(float *, int, void *) __asm__("func_0022D470");
extern void func_00239568_12A1B8(char *, int, int, unsigned, int) __asm__("func_00239568");
// MATCH func_0012A1B8
void battle_0012a1b8(int a) { O_0012A1B8 *o; int v, b, cur; unsigned fl; float buf[4]; if (battle_00127430() != 0) { if (D_004A6D94_12A1B8 == a) D_003279A0_12A1B8[a]->b209 = 128; return; } v = 128; if (D_004A6E50_12A1B8 != 0 && D_004A6D94_12A1B8 != a && D_004A6D9C_12A1B8 != a) { int t = D_003279A0_12A1B8[a]->b209 - 16; if (t < 0) t = 0; D_003279A0_12A1B8[a]->b209 = t; return; } fl = 0; o = D_003279A0_12A1B8[a]; b = 0; if ((D_004A1A20_12A1B8[a].fl & 0x10) && D_004A1A6C_12A1B8 == 0) { b = 1; fl = 1; } if (battle_0012c448(D_004A6D94_12A1B8) != 0) { fl |= 0x10; b = D_004A6D94_12A1B8 != a; } if (D_00323B40_12A1B8[D_004A13D4_12A1B8].f12 & 2) { if ((D_004A6D94_12A1B8 == a || D_004A1A2C_12A1B8 != 0) && (D_004A1A20_12A1B8[a].fl & 0x40000000)) { v = battle_0012a140(o); o->b209 = v; } else if (o->f88 < -D_00327974_12A1B8[0]->f8) v = 0; b = 0; fl |= 0x100; } if (D_00323B40_12A1B8[D_004A13D4_12A1B8].f12 & 0x20) { func_0022D470_12A1B8(buf, 0x70003c00, (char *)o + 128); if (D_004A6DA4_12A1B8 != a) { if (buf[2] < -D_00327974_12A1B8[0]->f8) v = 0; } else { v = battle_0012a140(o); o->b209 = v; } b = 0; fl |= 0x200; } if (D_00323B40_12A1B8[D_004A13D4_12A1B8].f12 & 4) { if (D_004A6DA4_12A1B8 + 4 != a) { if (o->f88 < -D_00327974_12A1B8[0]->f8) v = 0; } else { o->b209 = 128; v = 128; } b = 0; fl |= 0x400; } if (b != 0) { if (a < 1000) { if (func_0022F5E0_12A1B8(o->f80, o->f84, o->f88) < __builtin_fabsf(D_00327974_12A1B8[0]->f8)) { if (a == D_004A6D94_12A1B8 || a == D_004A6D9C_12A1B8) v = 32; else v = 0; } else { o->b209 = 128; v = 128; } } fl |= 0x1000; } if (a != D_004A6D94_12A1B8 && a != D_004A6D9C_12A1B8) func_001227B8_12A1B8(); if (D_00323B40_12A1B8[D_004A13D4_12A1B8].f12 & 0x10) { v = battle_0012a140(o); o->b209 = v; fl |= 0x400000; } if (D_004A1A50_12A1B8 & 0x10) { if (func_00127210_12A1B8() != 0 && (D_004A1A20_12A1B8[a].fl & 0x40000000) && func_0021A938_12A1B8(&D_004A1A20_12A1B8[a]) != 0) { float f; D_004A1A20_12A1B8[a].h5434 = D_004A1A20_12A1B8[a].h5434 + 1; f = (float)(D_004A1A20_12A1B8[a].h5434 - 60); if (f < 0.0f) f = 0.0f; if (f > 60.0f) f = 60.0f; v = func_002D9340_12A1B8((60.0f - f) * D_0049FE50_12A1B8); o->b209 = v; } else { o->b209 = 128; v = 128; } } if (D_004A6DFC_12A1B8 != 0 || D_004A6C58_12A1B8 != 0) { v = battle_0012a140(o); o->b209 = v; } cur = o->b209; if (cur != v) { if (v < cur) { cur -= 8; if (cur < v) cur = v; } else { cur += 8; if (v < cur) cur = v; } } if (cur < 0) cur = 0; if (cur > 128) cur = 128; o->b209 = cur; if (D_004A1A20_12A1B8[a].fl & 0x200000) { if (o->w24 & 0x4000000) { if (D_004A1A20_12A1B8[a].h5242 != 128) { D_004A1A20_12A1B8[a].h5242 = D_004A1A20_12A1B8[a].h5242 + 8; o->b209 = *(unsigned char *)&D_004A1A20_12A1B8[a].h5242; } } else o->b209 = 0; } if (D_004A6E04_12A1B8 != 0) func_00239568_12A1B8(D_004317A8_12A1B8, a, o->b209, fl, v); }


typedef struct { char p0[4816]; unsigned int fl; char p1[652]; } E5472_122138;
typedef struct { char d[128]; } S128_122138;
typedef struct { int w0, w4, w8; } B_122138;
extern E5472_122138 *D_004A1A20_122138 __asm__("D_004A1A20");
extern void *D_00327A40_122138[] __asm__("D_00327A40");
extern S128_122138 D_00322630_122138[] __asm__("D_00322630");
extern B_122138 D_003279F0_122138 __asm__("D_003279F0");
extern void *D_00327A40_122138[] __asm__("D_00327A40");
extern S128_122138 D_00322630_122138[] __asm__("D_00322630");
extern int D_004A6E58_122138 __asm__("D_004A6E58");
extern int D_004A6CF8_122138 __asm__("D_004A6CF8");
extern int D_004A6CF4_122138 __asm__("D_004A6CF4");
extern int D_004A1A60_122138 __asm__("D_004A1A60");
extern int D_004A1A48_122138 __asm__("D_004A1A48");
extern int D_004A1A2C_122138 __asm__("D_004A1A2C");
extern int D_004A6C54_122138 __asm__("D_004A6C54");
extern int D_004A6E98_122138 __asm__("D_004A6E98");
extern int D_004A6EA0_122138 __asm__("D_004A6EA0");
extern int D_004A1A34_122138 __asm__("D_004A1A34");
extern int D_004A1A8C_122138 __asm__("D_004A1A8C");
extern int D_004A1A50_122138 __asm__("D_004A1A50");
extern int D_004A6D98_122138 __asm__("D_004A6D98");
extern int D_004A1AAC_122138 __asm__("D_004A1AAC");
extern int D_004A6D94_122138 __asm__("D_004A6D94");
extern int D_004A6C3C_122138 __asm__("D_004A6C3C");
extern int D_004A6CF0_122138 __asm__("D_004A6CF0");
extern int D_004A6D80_122138 __asm__("D_004A6D80");
extern int D_004A6D8C_122138 __asm__("D_004A6D8C");
extern int D_004A6C1C_122138 __asm__("D_004A6C1C");
extern int D_004A6DBC_122138 __asm__("D_004A6DBC");
extern int D_004A1A54_122138 __asm__("D_004A1A54");
extern unsigned int D_004A6E74_122138 __asm__("D_004A6E74");
extern void *D_004A6DC0_122138 __asm__("D_004A6DC0");
extern int D_004A18E0_122138 __asm__("D_004A18E0");
extern float D_0049FDB0_122138 __asm__("D_0049FDB0");
extern char D_00430798_122138[] __asm__("D_00430798");
extern char D_004307B8_122138[] __asm__("D_004307B8");
extern char D_004307D8_122138[] __asm__("D_004307D8");
void  func_00237938_122138(int, int, int, int, int, int, int, int, int, char *) __asm__("func_00237938");
void  func_001297A0_122138(int, int, int, int, int, int) __asm__("func_001297A0");
int  func_0024CF68_122138(int) __asm__("func_0024CF68");
void  func_0012AEA8_122138(int) __asm__("func_0012AEA8");
void  func_00235130_122138(int, int) __asm__("func_00235130");
int  func_00126058_122138(void) __asm__("func_00126058");
int  func_0012AE68_122138(void) __asm__("func_0012AE68");
void  func_0021AE58_122138(E5472_122138 *) __asm__("func_0021AE58");
int  func_00127210_122138(void) __asm__("func_00127210");
void  func_00127890_122138(int) __asm__("func_00127890");
int  func_0012AA18_122138(void) __asm__("func_0012AA18");
int  func_0012A860_122138(int) __asm__("func_0012A860");
void  func_00129BE8_122138(int) __asm__("func_00129BE8");
void  func_0012A948_122138(void) __asm__("func_0012A948");
int  func_001118F8_122138(char *, ...) __asm__("func_001118F8");
void  func_00127930_122138(int) __asm__("func_00127930");
void  func_001234C8_122138(void) __asm__("func_001234C8");
int  func_00235028_122138(S128_122138 *, float) __asm__("func_00235028");
void  func_00247468_122138(B_122138 *, int, S128_122138 *) __asm__("func_00247468");
void  func_00247490_122138(B_122138 *, int) __asm__("func_00247490");
void  func_00247580_122138(B_122138 *, int) __asm__("func_00247580");
int  func_0021A938_122138(E5472_122138 *) __asm__("func_0021A938");
void  func_0024CFC0_122138(int) __asm__("func_0024CFC0");
void  func_0021A8F8_122138(E5472_122138 *) __asm__("func_0021A8F8");
// MATCH func_00122138
void battle_00122138(void)
{
    int ok, i, n;
    float k;
    D_00327A40_122138[0] = 0;
    D_00327A40_122138[2] = 0;
    if (D_004A6E58_122138 != 0) {
        if (D_004A6E58_122138 == 1) func_00237938_122138(0, 0, 120, 255, 255, 160, 160, 0, 0, D_00430798_122138);
        if (D_004A6E58_122138 == 2) func_00237938_122138(0, 0, 120, 255, 255, 160, 160, 0, 0, D_004307B8_122138);
        if (D_004A6E74_122138 & 0x300050) {
            D_004A6E58_122138 = 0;
            D_004A6CF8_122138 = 0;
            func_001297A0_122138(0, 2, 0, 2, 0, 0);
            func_0012AEA8_122138(func_0024CF68_122138(D_004A6CF4_122138));
            func_00235130_122138(-1, D_004A1A60_122138);
            D_004A6DC0_122138 = &D_004A18E0_122138;
        }
        return;
    }
    if (D_004A1A48_122138 != 0) {
        ok = 0;
        D_004A1A2C_122138 = 5;
        D_004A6C54_122138 = 0;
        if (func_00126058_122138() == 0) ok = func_0012AE68_122138() == 0;
        if (D_004A6E98_122138 >= 0) { D_004A6E98_122138--; ok = 0; }
        if (!ok) return;
        if (D_004A6EA0_122138 == 0) {
            D_004A6EA0_122138 = 1;
            for (i = 0; i < 20; i++) {
                if (D_004A1A34_122138 == 1 && (D_004A1A20_122138[i].fl & 0x20000000)) D_004A1A20_122138[i].fl |= 0x20000;
                if (D_004A1A34_122138 == 2 && (D_004A1A20_122138[i].fl & 0x40000000)) D_004A1A20_122138[i].fl |= 0x20000;
            }
            for (i = 0; i < D_004A1A8C_122138; i++) func_0021AE58_122138(&D_004A1A20_122138[i]);
            for (i = 0; i < 20; i++)
                if (D_004A1A20_122138[i].fl & 0x20000) D_004A1A20_122138[i].fl |= 2;
        }
        if (func_00127210_122138() != 0 && (D_004A6CF8_122138 & 0xc)) {
            D_004A1A50_122138 |= 0x10;
            func_00127890_122138(1);
            return;
        }
        D_004A6D98_122138 = func_0012AA18_122138();
        if (func_0012A860_122138(D_004A6D98_122138) != 0) return;
        D_004A6D94_122138 = D_004A6D98_122138;
        D_004A1A48_122138 = 0;
        if (D_004A1AAC_122138 != 0) func_00129BE8_122138(D_004A6C3C_122138);
        func_0012A948_122138();
        func_001118F8_122138(D_004307D8_122138, D_004A6D94_122138);
        if (D_004A6D94_122138 < 0) {
            func_00127930_122138(D_004A6D94_122138);
            D_004A6D94_122138 = 0;
            return;
        }
        func_001234C8_122138();
        func_00235130_122138(-1, D_004A1A60_122138);
        return;
    }
    k = D_0049FDB0_122138;
    D_004A6CF0_122138 = 0;
    D_004A6D80_122138 = -1;
    func_00235028_122138(&D_00322630_122138[0], k);
    func_00235028_122138(&D_00322630_122138[1], k);
    func_00235028_122138(&D_00322630_122138[2], k);
    if (D_004A6D8C_122138 == 0) {
        func_00247468_122138(&D_003279F0_122138, 1, &D_00322630_122138[0]);
        func_00247468_122138(&D_003279F0_122138, 2, &D_00322630_122138[1]);
        func_00247468_122138(&D_003279F0_122138, 0, &D_00322630_122138[3]);
        func_00247468_122138(&D_003279F0_122138, 3, &D_00322630_122138[3]);
        D_003279F0_122138.w8 = 0x35000;
        func_00247490_122138(&D_003279F0_122138, 1);
    }
    func_00247580_122138(&D_003279F0_122138, 0x48000);
    if (D_004A1A34_122138 == 2) D_004A6E74_122138 = 0x48000;
    if (D_004A6C1C_122138 != 0) D_004A6E74_122138 = 0x48000;
    D_004A6D80_122138 = -1;
    if (D_004A6E74_122138 & 0x48000) {
        D_004A1A2C_122138 = 10;
        if (D_004A1A34_122138 != 2) func_001297A0_122138(0, 2, 0, 1, 0, 0);
        func_00235130_122138(-1, D_004A1A60_122138);
        D_004A6EA0_122138 = 0;
        D_004A1A48_122138 = 1;
    } else {
        if (!(D_004A6E74_122138 & 0x182010)) return;
        D_004A6CF8_122138 = 0;
        D_004A6DC0_122138 = (void *)D_004A6DBC_122138;
        func_001297A0_122138(0, 2, 0, 2, 0, 0);
        if (D_004A1A54_122138 != 0) {
            D_004A6D94_122138 = 0;
        } else {
            if (--D_004A6D94_122138 < 0) D_004A6D94_122138 = 0;
            for (;;) {
                if (func_0021A938_122138(&D_004A1A20_122138[D_004A6D94_122138])) break;
                if (D_004A6D94_122138 <= 0) break;
                D_004A6D94_122138--;
            }
        }
        if (D_004A6D94_122138 < 0) D_004A6D94_122138 = 0;
        n = 0;
        for (i = 0; i < D_004A1A8C_122138; i++)
            if (func_0021A938_122138(&D_004A1A20_122138[D_004A6D94_122138])) n++;
        if (n == 0) {
            func_0024CFC0_122138(D_004A6CF4_122138);
            func_0012AEA8_122138(2);
        } else {
            func_0021A8F8_122138(&D_004A1A20_122138[D_004A6D94_122138]);
            func_0012AEA8_122138(func_0024CF68_122138(D_004A6CF4_122138));
        }
        func_00235130_122138(-1, D_004A1A60_122138);
    }
    D_004A6E74_122138 = 0;
}

